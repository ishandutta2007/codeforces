#include <stdio.h>
#include <iostream>
#include <cstring>

using namespace std;

const int N = 1000002;

char a[N], b[N]; int la, lb, i, j, k;

int main () {
    scanf("%s\n%s", a, b);
    la = strlen(a), lb = strlen(b);
    i = 0, j = 0;
    while (a[i] == '0') i++, la--;
    while (b[j] == '0') j++, lb--;
    if (la > lb) printf(">\n");
    else if (la < lb) printf("<\n");
    else {
        for (k = 0; k < la; k++) {
            if (a[i + k] < b[j + k]) {
                printf("<\n");
                return 0;
            }
            else if (a[i + k] > b[j + k]) {
                printf(">\n");
                return 0;
            }
        }
        printf("=\n");
    }
    return 0;
}