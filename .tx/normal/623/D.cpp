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

ldouble pne[111];
ldouble p[111];
ldouble pr[111];
ldouble sf[111];

int main() {
    scid(n);
    for (int i = 0; i < n; i++) {
        scid(x);
        p[i] = x / 100.0;
        pne[i] = 1;
    }

    for (int i = 0; i + 1 < n; i++) {
        pne[i] = 1 - p[i];
    }

    ldouble ans = 0;

    for (int k = n; k <= 200031; k++) {
        for (int i = 0; i < n; i++) {
            pr[i] = 1 - pne[i];
            if (i) {
                pr[i] *= pr[i - 1];
            }
        }
        for (int i = n - 1; i >= 0; i--) {
            sf[i] = 1 - pne[i];
            if (i + 1 < n) {
                sf[i] *= sf[i + 1];
            }
        }
        ldouble end_now = -1;
        int mx = -1;
        for (int i = 0; i < n; i++) {
            ldouble x = pne[i] * p[i];
            if (i > 0) {
                x *= pr[i - 1];
            }
            if (i + 1 < n) {
                x *= sf[i + 1];
            }
            if (x > end_now) {
                end_now = x;
                mx = i;
            }
//            if (pne[i] * p[i] > pne[mx] * p[mx]) {
//                mx = i;
//            }
        }
//        for (int i = 0; i < n; i++) {
//            if (i == mx) {
//                end_now *= pne[i] * p[i];
//            } else{
//                end_now *= 1 - pne[i];
//            }
//        }
        pne[mx] *= 1 - p[mx];
        ans += k * end_now;
    }

    cout.precision(11);
    cout << fixed << ans;

    return 0;
}