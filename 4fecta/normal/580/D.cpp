#include <bits/stdc++.h>

using namespace std;

#define ll long long
#define int ll
#define ld long double
#define pii pair<int, int>
#define f first
#define s second
#define readl(_s) getline(cin, (_s));
#define boost() cin.tie(0); cin.sync_with_stdio(0)
#define popcnt(x) __builtin_popcount(x)

const int MN = 20;

int n, m, k, u, v, c, dp[MN][1 << MN], cost[MN][MN], val[MN], ans = 0;

int rec(int cur, int msk) {
    if (dp[cur][msk] != -1) return dp[cur][msk];
    int nxt = msk ^ (1 << cur);
    for (int j = 0; j < n; j++) {
        if (nxt & (1 << j)) {
            dp[cur][msk] = max(dp[cur][msk], rec(j, nxt) + val[cur] + cost[j][cur]);
        }
    }
    return dp[cur][msk];
}

int32_t main() {
    boost();

    memset(dp, -1, sizeof(dp));
    cin >> n >> m >> k;
    for (int i = 0; i < n; i++) cin >> val[i], dp[i][1 << i] = val[i];
    for (int i = 0; i < k; i++) {
        cin >> u >> v >> c;
        u--, v--;
        cost[u][v] = c;
    }
    for (int i = 0; i < (1 << n); i++) {
        if (popcnt(i) == m) {
            for (int j = 0; j < n; j++) {
                if ((1 << j) & i) {
                    ans = max(ans, rec(j, i));
                    //printf("%d\n", i);
                }
            }
        }
    }
    printf("%lld\n", ans);

    return 0;
}