#include<bits/stdc++.h>

using namespace std;

typedef long long ll;
int const maxm = 10005, maxg = 1005;
ll dp[maxm][maxg];
ll inf = 2e18;
int d[maxm];
pair < int, int > Q[2 * maxm * maxg];
int go[maxm], was[maxm];

main() {
#ifdef HOME
    freopen("input.txt", "r", stdin);
#endif // HOME
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int n, m, g, r, ptr = 0;
    ll ans = inf;
    cin >> n >> m;
    for (int i = 1; i <= m; ++i) cin >> d[i];
    sort(d + 1, d + m + 1);
    cin >> g >> r;
    for (int i = 1; i <= m; ++i) {
        for (int j = 0; j <= g; ++j) dp[i][j] = inf;
    }
    dp[1][0] = 0;
    Q[ptr++] = {1, 0};
    int T = 0;
    while (ptr > 0) {
        T++;
        int cur = 0;
        for (int i = 0; i < ptr; ++i) {
            ll val = dp[Q[i].first][Q[i].second];
            int x = Q[i].first, y = Q[i].second;
            if (d[x] + g - y >= n) ans = min(ans, val + (ll)(n - d[x]));
            if (y == g) {
                if (dp[x][0] > dp[x][y] + (ll)r) {
                    dp[x][0] = dp[x][y] + (ll)r;
                    if (was[x] != T) {
                        go[cur++] = x;
                        was[x] = T;
                    }
                }
            }
            else {
                if (x < m && y + d[x + 1] - d[x] <= g) {
                    if (dp[x + 1][y + d[x + 1] - d[x]] > val + (ll)(d[x + 1] - d[x])) {
                        dp[x + 1][y + d[x + 1] - d[x]] = val + (ll)(d[x + 1] - d[x]);
                        if (ptr < 2 * maxm * maxg) Q[ptr++] = {x + 1, y + d[x + 1] - d[x]};
                    }
                }
                if (x > 1 && y + d[x] - d[x - 1] <= g) {
                    if (dp[x - 1][y + d[x] - d[x - 1]] > val + (ll)(d[x] - d[x - 1])) {
                        dp[x - 1][y + d[x] - d[x - 1]] = val + (ll)(d[x] - d[x - 1]);
                        if (ptr < 2 * maxm * maxg) Q[ptr++] = {x - 1, y + d[x] - d[x - 1]};
                    }
                }
            }
        }
        ptr = cur;
        for (int i = 0; i < cur; ++i) Q[i] = {go[i], 0};
    }
    if (ans >= inf / 2) cout << -1;
    else cout << ans;
    return 0;
}