#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define int ll
#define ld long double
#define pii pair<int, int>
#define f first
#define s second
#define boost() cin.tie(0), cin.sync_with_stdio(0)

const int MN = 400005, MOD = 1e9 + 7;

int t, n, a[2][MN], vis[MN], id[MN];

int32_t main() {
    boost();

    cin >> t;
    while (t--) {
        cin >> n;
        for (int j = 0; j < 2; j++) {
            for (int i = 1; i <= n; i++) {
                cin >> a[j][i];
            }
        }
        int ans = 1;
        for (int i = 1; i <= n; i++) id[a[0][i]] = i;
        for (int i = 1; i <= n; i++) {
            if (vis[i]) continue;
            ans *= 2;
            ans %= MOD;
            vis[i] = 1;
            int cur = i;
            while (id[a[1][cur]] != i) {
                cur = id[a[1][cur]];
                vis[cur] = 1;
            }
        }
        printf("%lld\n", ans % MOD);
        for (int j = 0; j < 2; j++) {
            for (int i = 1; i <= n; i++) {
                a[j][i] = 0;
            }
        }
        for (int i = 1; i <= n; i++) vis[i] = id[i] = 0;
    }

    return 0;
}