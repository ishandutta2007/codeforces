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

int main() {
    sciid(n, m);
    sciid(x, y);
    lint ans = 0;
    scid(k);
    while (k-- > 0) {
        sciid(dx, dy);
        int cx = 1e9;
        if (dx > 0) {
            cx = (n - x) / dx;
        } else if (dx < 0) {
            cx = -(x - 1) / dx;
        }
        int cy = 1e9;
        if (dy > 0) {
            cy = (m - y) / dy;
        } else if (dy < 0) {
            cy = -(y - 1) / dy;
        }
        int c = min(cx, cy);
        ans += c;
        x += c * dx;
        y += c * dy;
    }
    cout << ans;

    return 0;
}