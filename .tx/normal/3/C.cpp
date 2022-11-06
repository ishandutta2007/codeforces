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

#define rveid(a, n) vector<int> a(n); for (int i = 0; i < n; i++) sci(a[i])

typedef long long lint;

using namespace std;

void init_cin() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
}

char a[4][4];

bool eq(int i1, int j1, int i2, int j2, int i3, int j3, char c) {
    return a[i1][j1] == a[i2][j2] && a[i2][j2] == a[i3][j3] && a[i1][j1] == c;
}

bool win(char c) {
    bool res = false;
    for (int i = 0; i < 3; i++) {
        res |= eq(i, 0, i, 1, i, 2, c);
        res |= eq(0, i, 1, i, 2, i, c);
    }
    res |= eq(0, 0, 1, 1, 2, 2, c);
    res |= eq(0, 2, 1, 1, 2, 0, c);
    return res;
}

int main() {
    int n = 3;
    int kx = 0, ko = 0;
    for (int i = 0; i < n; i++) {
        scanf("%s", a[i]);
        for (int j = 0; j < n; j++) {
            if (a[i][j] == 'X') {
                kx++;
            } else if (a[i][j] == '0') {
                ko++;
            }
        }
    }
    if (kx - ko > 1 || kx - ko < 0) {
        puts("illegal");
        return 0;
    }
    bool wx = win('X');
    bool wy = win('0');
    if (wx && wy || wx && kx == ko || wy && kx > ko) {
        puts("illegal");
        return 0;
    }
    if (wx) {
        puts("the first player won");
    } else if (wy) {
        puts("the second player won");
    } else if (ko + kx == 9) {
        puts("draw");
    } else if (kx == ko) {
        puts("first");
    } else {
        puts("second");
    }

    return 0;
}