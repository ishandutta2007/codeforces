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

typedef long long lint;

using namespace std;

void init_cin() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
}

void solve() {
    sciiid(a, x, y);
    if (y % a == 0) {
        cout << -1;
        return;
    }
    y /= a;
    int l;
    if (y != 0 && y % 2 == 0) {
        l = 2;
    } else {
        l = 1;
    }
    if (l == 1 && abs(x) >= (a + 1) / 2 || l == 2 && abs(x) >= a || l == 2 && x == 0) {
        cout << -1;
        return;
    }
    if (l == 1) {
        if (y == 0) {
            cout << 1;
        } else {
            cout << y / 2 * 3 + 2;
        }
    } else {
        int t = (y + 1) / 2 * 3;
        if (x > 0) {
            t++;
        }
        cout << t;
    }
}

int main() {
    solve();
    return 0;
}