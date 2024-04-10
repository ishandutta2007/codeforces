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

static const long double eps = 1e-20;
using namespace std;

int main() {
    sciiid(x, y, n);
    long double mn = 1e9;
    lint aa = 0, ab = 1;
    for (int b = 1; b <= n; b++) {
        lint a = 1LL * x * b / y;
        long double t = abs((long double) x / y - (long double) a / b);
        if (abs(t - mn) > eps && t < mn) {
            mn = t;
            aa = a;
            ab = b;
        }
        a++;
        t = abs((long double) x / y - (long double) a / b);
        if (abs(t - mn) > eps && t < mn) {
            mn = t;
            aa = a;
            ab = b;
        }
    }

    cout << aa << "/" << ab;

    return 0;
}