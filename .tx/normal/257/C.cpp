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
typedef long double ldouble;

using namespace std;

struct point {
    ldouble x, y;
};

point a[111111];

const ldouble PI = acosl(-1.0);

ldouble norm(ldouble x) {
    while (x < 0) {
        x += 2 * PI;
    }
    while (x >= 2 * PI) {
        x -= 2 * PI;
    }
    return x;
}

int main() {
    scid(n);
    for (int i = 0; i < n; i++) {
        sciid(x, y);
        a[i] = point{ldouble(x), ldouble(y)};
    }
    sort(a, a + n, [](const point& l, const point& r) {
        return atan2(l.y, l.x) < atan2(r.y, r.x);
    });
    a[n] = a[0];
    ldouble ans = 0;
    for (int i = 0; i < n; i++) {
        ldouble x = -atan2(a[i].y, a[i].x) + atan2(a[i + 1].y, a[i + 1].x);
        ans = max(ans, norm(x));
    }
    if (abs(ans) < 1e-9) {
        ans = 2 * PI;
    }
    cout.precision(11);
    cout << fixed << (2 * PI - ans) / PI * 180;



    return 0;
}