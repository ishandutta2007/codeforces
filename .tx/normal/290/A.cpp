#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <vector>
#include <algorithm>
#include <map>
#include <set>
#include <queue>
#include <memory.h>

#define scid(a) int a; scanf("%d", &a)
#define sciid(a, b) int a, b; scanf("%d%d", &a, &b)
#define sciiid(a, b, c) int a, b, c; scanf("%d%d%d", &a, &b, &c)

#define sci(a) scanf("%d", &a)
#define scii(a, b) scanf("%d%d", &a, &b)
#define sciii(a, b, c) scanf("%d%d%d", &a, &b, &c)

#define rvei(a, n) vector<int> a(n); for (int i = 0; i < n; i++) sci(a[i])

typedef long long lint;

using namespace std;

void init_cin() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
}

int main() {
    scid(n);
    if (n == 1) {
        printf("Washington");
    }
    if (n == 2 or n == 6) {
        printf("Adams");
    }
    if (n == 3) {
        printf("Jefferson");
    }
    if (n == 4) {
        printf("Madison");
    }
    if (n == 5) {
        printf("Monroe");
    }
    if (n == 7) {
        printf("Jackson");
    }
    if (n == 8) {
        printf("Van Buren");
    }
    if (n == 10) {
        printf("Tyler");
    }
    if (n == 9 or n == 23) {
        printf("Harrison");
    }
    if (n == 11) {
        printf("Polk");
    }
    if (n == 12) {
        printf("Taylor");

    }
    if (n == 13) {
        printf("Fillmore");

    }
    if (n == 14) {
        printf("Pierce");

    }
    if (n == 15) {
        printf("Buchanan");

    }
    if (n == 16) {
        printf("Lincoln");

    }
    if (n == 17 or n == 36) {
        printf("Johnson");

    }
    if (n == 18) {
        printf("Grant");

    }
    if (n == 19) {
        printf("Hayes");

    }
    if (n == 20) {
        printf("Garfield");

    }
    if (n == 21) {
        printf("Arthur");

    }
    if (n == 22 or n == 24) {
        printf("Cleveland");

    }
    if (n == 25) {
        printf("McKinley");

    }
    if (n == 26 or n == 32) {
        printf("Roosevelt");

    }
    if (n == 27) {
        printf("Taft");

    }
    if (n == 28) {
        printf("Wilson");

    }
    if (n == 29) {
        printf("Harding");

    }
    if (n == 30) {
        printf("Coolidge");

    }
    if (n == 31) {
        printf("Hoover");

    }
    if (n == 33) {
        printf("Truman");

    }
    if (n == 34) {
        printf("Eisenhower");

    }
    if (n == 35) {
        printf("Kennedy");

    }
    if (n == 37) {
        printf("Nixon");

    }
    if (n == 38) {
        printf("Ford");

    }
    if (n == 39) {
        printf("Carter");

    }
    if (n == 40) {
        printf("Reagan");

    }

    return 0;
}