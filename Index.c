#include <stdio.h>

int getFirstDayOfMonth(int year, int month);
int getNumberOfDays(int year, int month);

int main() {
    int year, month;

    printf("Enter year: ");
    scanf("%d", &year);
    printf("\n");
    printf("Enter month (1-12): ");
    scanf("%d", &month);

    int firstDay = getFirstDayOfMonth(year, month);
    int daysInMonth = getNumberOfDays(year, month);

    printf("\n   Sun  Mon  Tue  Wed  Thu  Fri  Sat\n");

    // Printing the first day position
    for (int i = 0; i < firstDay; i++) {
        printf("     ");
    }

    for (int i = 1; i <= daysInMonth; i++) {
        printf("%5d", i);
        if ((i + firstDay) % 7 == 0) {
            printf("\n");
        }
    }

    printf("\n");
    return 0;
}

// Function to get the first day of the month
int getFirstDayOfMonth(int year, int month) {
    // Zeller's congruence algorithm
    if (month < 3) {
        month += 12;
        year -= 1;
    }
    int k = year % 100;
    int j = year / 100;
    int day = 1;
    int f = day + 13*(month + 1)/5 + k + k/4 + j/4 + 5*j;
    return f % 7;
}

// Function to get the number of days in a month
int getNumberOfDays(int year, int month) {
    int daysInMonth[] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
    if (month == 2 && (year % 400 == 0 || (year % 4 == 0 && year % 100 != 0))) {
        return 29; // February in a leap year
    }
    return daysInMonth[month - 1];
}
