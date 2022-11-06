#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <algorithm>
#include <vector>
#include <map>
#include <set>
#include <queue>
#include <unordered_map>
#include <unordered_set>
#include <deque>
#include <string>
#include <memory.h>

#define sci(a) scanf("%d", &a)
#define scii(a, b) scanf("%d%d", &a, &b)
#define sciii(a, b, c) scanf("%d%d%d", &a, &b, &c)

#define scid(a) int a; sci(a)
#define sciid(a, b) int a, b; scii(a, b)
#define sciiid(a, b, c) int a, b, c; sciii(a, b, c)

#define rea(a, n) for (int i = 0; i < n; i++) sci(a[i])

#define init_cin ios_base::sync_with_stdio(false); cin.tie(0);

typedef long long lint;

using namespace std;

int dm[13] = {0, 31, 0, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};

bool isVis(int y) {
    return y % 400 == 0 || y % 4 == 0 && y % 100 != 0;
}

int cd(int y, int m, int d) {
    int res = 0;
    for (int i = 0; i < y; i++) {
        if (isVis(i)) {
            res += 366;
        } else {
            res += 365;
        }
    }
    for (int i = 1; i < m; i++) {
        if (i == 2) {
            res += isVis(y) ? 29 : 28;
        } else {
            res += dm[i];
        }
    }
    res += d;
    return res;
}

int main() {
    int y1, m1, d1;
    int y2, m2, d2;
    scanf("%d:%d:%d\n", &y1, &m1, &d1);
    scanf("%d:%d:%d", &y2, &m2, &d2);

    int cd1 = cd(y1, m1, d1);
    int cd2 = cd(y2, m2, d2);

    cout << abs(cd1 - cd2);
    return 0;
}