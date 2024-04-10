#include <bits/stdc++.h>

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

int a[111];

int main() {
    sciid(n, ml);
    rea(a, n);
    int ans = 0;
    for (int w = 1; w <= 10000; w++) {
        int l = ml - 1, r = 101;
        while (l + 1 < r) {
            int m = (l + r) >> 1;
            int c = 0;
            for (int i = 0; i < n; i++) {
                c += a[i] / m;
            }
            if (c >= w) {
                l = m;
            } else {
                r = m;
            }
        }
        if (l >= ml) {
            ans = max(ans, l * w);
        }
    }
    cout << ans;

    return 0;
}