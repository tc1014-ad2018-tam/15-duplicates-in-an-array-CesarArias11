/*
 * This programs lets the user enter 'n' numbers.
 * If there's a repetition it will inform it to the user.
 *
 * Author: Cesar Alejandro Arias Perales
 * Date: October 15th, 2018
 * Mail: A01411995@itesm.mx
 *
 */


#include <stdio.h>
#include <stdlib.h>

// This function compares two numbers.
int cmpfunc (const void * a, const void * b) {
    return ( *(int*)a - *(int*)b );
}

int main() {

    // Here I declare my variables.
    int x;
    int n;
    int counter = 0;
    int duplicates = 0;
    int reps;

    // Here I ask how many numbers is the user going to eneter.
    printf("How many numbers are you going to enter?\n");
    scanf("%d", &n);

    int arr[n];

    // For loop that asks the user for a number as many times as numbers indicated, then adds the value to the position
    // of the number of i in the loop into the array.
    for (int i = 0; i < n; i++) {
        printf("Give me number %d:\n", i + 1);
        scanf("%d", &x);
        arr[i] = x;
    }

    // Function that arranges the numbers.
    qsort(arr, n, sizeof(int), cmpfunc);

    // Loop that goes from 0 to entered amount, with a step that changes depending on how many duplicates were found
    for (int i = 0; i < n; i += counter+1) {
        counter = 0;

        // Here is were thr program looks for the duplicates.
        do {
            if (arr[i] == arr[i+counter+1]) {
                counter++; // WHen a duplicate is found.
                reps = 1;
            } else {
                reps = 0;
            }
        } while (reps == 1);

        if (counter > 0) {
            duplicates++;
        }

    }

    printf("The amount of duplicated numbers is %d.", duplicates);

    return 0;
}