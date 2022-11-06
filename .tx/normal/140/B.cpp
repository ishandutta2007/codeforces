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

int a[333][333];
int ans[333];

int main() {
    scid(n);
    for (int i = 0; i <= n; i++) {
        for (int j = 0; j < n; j++) {
            scid(x);
            --x;
            a[i][x] = j;
        }
        a[i][i] = 1e9;
    }

    int m1 = -1, m2 = -1;
    fill(ans, ans + n, -1);
    for (int i = 0; i < n; i++) {
        if (m1 == -1 || a[n][i] < a[n][m1]) {
            m2 = m1;
            m1 = i;
        } else if (m2 == -1 || a[n][i] < a[n][m2]) {
            m2 = i;
        }
        for (int j = 0; j < n; j++) {
            int x = m1;
            if (x == j) {
                x = m2;
            }
            if (x == -1) {
                continue;
            }
            if (ans[j] == -1 || a[j][x] < a[j][ans[j]]) {
                ans[j] = x;
            }
        }
    }

    for (int i = 0; i < n; i++) {
        cout << ans[i] + 1 << " ";
    }

    return 0;
}