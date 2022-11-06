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

int a[22];
int b[22];

const double eps = 1e-9;

int main() {
    sciid(n, v);
    rea(a, n);
    rea(b, n);

    double l = 0, r = v;
    double av = 0;
    for (int itn = 0; itn < 10000; itn++) {
        double m = (l + r) / 2;
        av = 0;
        bool ok = true;
        for (int i = 0; i < n; i++) {
            if (a[i] * m > b[i] - eps) {
                ok = false;
                break;
            }
            av += a[i] * m;
        }
        if (av > v + eps) {
            ok = false;
        }
        if (ok) {
            l = m;
        } else {
            r = m;
        }
    }
    double ans = 0;
    for (int i = 0; i < n; i++) {
        ans += a[i] * l;
    }
    printf("%.11f", ans);

    return 0;
}