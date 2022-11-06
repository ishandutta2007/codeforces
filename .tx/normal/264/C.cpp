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

lint d[111111];
int v[111111];
int c[111111];

const lint inf = 1e18;

int main() {
    sciid(n, q);
    rea(v, n);
    for (int i = 0; i < n; i++) {
        sci(c[i]);
        --c[i];
    }
    while (q-- > 0) {
        sciid(a, b);
        fill(d, d + n, -inf);
        pair<lint, int> m1 = {0, -1};
        pair<lint, int> m2 = {-inf, -1};
        for (int i = 0; i < n; i++) {
            lint mm = m1.second == c[i] ? m2.first : m1.first;
            lint nv = -inf;
            if (mm != -inf) {
                nv = max(nv, mm + 1LL * b * v[i]);
            }
            if (d[c[i]] != -inf) {
                nv = max(nv, d[c[i]] + 1LL * a * v[i]);
            }
            if (nv != -inf) {
                if (nv > d[c[i]]) {
                    d[c[i]] = nv;
                    if (nv > m1.first) {
                        if (c[i] == m1.second) {
                            m1.first = nv;
                        } else {
                            m2 = m1;
                            m1 = {nv, c[i]};
                        }
                    } else if (nv > m2.first) {
                        m2 = {nv, c[i]};
                    }
                }
            }
        }
        lint ans = max(*max_element(d, d + n), 0LL);
        cout << ans << "\n";
    }




    return 0;
}