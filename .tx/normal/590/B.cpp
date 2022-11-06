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

int main() {
    sciid(x1, y1);
    sciid(x2, y2);
    sciid(v, t);
    sciid(vx, vy);
    sciid(wx, wy);
    double x = x2 - x1;
    double y = y2 - y1;
    double l = 0, r = 1e31;
    for (int i = 0; i < 1000; i++) {
        double m = (l + r) / 2;
        double mx = 1.0 * min(m, 1.0 * t) * vx + 1.0 * max(0.0, m - t) * wx;
        double my = 1.0 * min(m, 1.0 * t) * vy + 1.0 * max(0.0, m - t) * wy;
        double d = sqrt((mx - x) * (mx - x) + (my - y) * (my - y));
        if (v * m >= d) {
            r = m;
        } else {
            l = m;
        }
    }
    printf("%.11f", l);
    return 0;
}