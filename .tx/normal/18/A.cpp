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

int x[2][3];

bool check(int x1, int y1, int x2, int y2) {
    return 1LL * x1 * x2 + 1LL * y1 * y2 == 0 && 1LL * x1 * y2 - 1LL * x2 * y1 != 0;
}

bool right(int x1, int y1, int x2, int y2, int x3, int y3) {
    return check(x2 - x1, y2 - y1, x3 - x1, y3 - y1) || check(x1 - x2, y1 - y2, x3 - x2, y3 - y2) || check(x1 - x3, y1 - y3, x2 - x3, y2 - y3);
}

bool right() {
    return right(x[0][0], x[1][0], x[0][1], x[1][1], x[0][2], x[1][2]);
}

int main() {
    for (int i = 0; i < 3; i++) {
        scii(x[0][i], x[1][i]);
    }

    if (right()) {
        cout << "RIGHT";
        return 0;
    }

    for (int i = 0; i < 2; i++) {
        for (int j = 0; j < 3; j++) {
            for (int d = -1; d <= 1; d += 2) {
                x[i][j] += d;
                if (right()) {
                    cout << "ALMOST";
                    return 0;
                }
                x[i][j] -= d;
            }
        }
    }

    cout << "NEITHER";

    return 0;
}