#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <algorithm>
#include <vector>
#include <map>
#include <set>
#include <queue>
#include <stack>
#include <unordered_map>
#include <unordered_set>
#include <deque>
#include <string>
#include <memory.h>
#include <bitset>

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

const double eps = 1e-9;

bool eq(double a, double b) {
    return abs(a - b) < eps;
}

bool le(double a, double b) {
    return a < b + eps;
}

#define ans(x) printf("%.11f", (double) (x) / 2); return 0

int main() {
    sciiid(x1, y1, r1);
    sciiid(x2, y2, r2);
    if (r1 > r2) {
        swap(x1, x2);
        swap(y1, y2);
        swap(r1, r2);
    }
    double dc = sqrt((x2 - x1) * (x2 - x1) + (y2 - y1) * (y2 - y1));
    if (le(dc + r1, r2)) {
        ans(r2 - r1 - dc);
    }
    if (le(dc, r1 + r2)) {
        ans(0);
    }
    ans(dc - r1 - r2);


    return 0;
}