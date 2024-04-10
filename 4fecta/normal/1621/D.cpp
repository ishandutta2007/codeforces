#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define int ll
#define ld long double
#define pii pair<int, int>
#define f first
#define s second
#define boost() cin.tie(0), cin.sync_with_stdio(0)

const int MN = 505;

int n, c[MN][MN];

int32_t main() {
    boost();

    int t;
    cin >> t;
    while (t--) {
        cin >> n;
        for (int i = 1; i <= 2 * n; i++) {
            for (int j = 1; j <= 2 * n; j++) {
                cin >> c[i][j];
            }
        }
        int ans = 0;
        for (int i = n + 1; i <= 2 * n; i++) {
            for (int j = n + 1; j <= 2 * n; j++) {
                ans += c[i][j];
                c[i][j] = 0;
            }
        }
        int add = 0x3f3f3f3f;
        add = min(add, c[1][n+1]);
        add = min(add, c[n+1][1]);
        add = min(add, c[n][n+1]);
        add = min(add, c[n+1][n]);
        add = min(add, c[1][2*n]);
        add = min(add, c[2*n][1]);
        add = min(add, c[n][2*n]);
        add = min(add, c[2*n][n]);
        printf("%lld\n", ans + add);
    }

    return 0;
}