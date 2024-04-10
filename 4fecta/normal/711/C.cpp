#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>

using namespace std;
using namespace __gnu_pbds;

typedef tree<int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update> ordered_set;

#define ll long long
#define ld long double
#define int ll
#define pii pair<int, int>
#define f first
#define s second
#define readl(_s) getline(cin, (_s));
#define boost() cin.tie(0); cin.sync_with_stdio(0)

const int MN = 105;

int n, m, cmp, a[MN], cost[MN][MN], dp[MN][MN][MN]; //idx, number of components, cur colour

int32_t main() {
    boost();

    cin >> n >> m >> cmp;
    for (int i = 1; i <= n; i++) cin >> a[i];
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) cin >> cost[i][j];
    }
    for (int i = 0; i < MN; i++) for (int j = 0; j < MN; j++) for (int k = 0; k < MN; k++) dp[i][j][k] = 1LL << 60;
    for (int i = 0; i <= m; i++) dp[0][0][i] = 0;
    for (int i = 1; i <= n; i++) {
        if (a[i]) {
            for (int j = 1; j <= cmp; j++) {
                for (int k = 0; k <= m; k++) {
                    if (a[i] == k) dp[i][j][k] = min(dp[i][j][k], dp[i - 1][j][k]);
                    else dp[i][j][a[i]] = min(dp[i][j][a[i]], dp[i - 1][j - 1][k]);
                }
            }
        } else {
            for (int j = 1; j <= cmp; j++) {
                for (int k = 0; k <= m; k++) {
                    for (int nxt = 1; nxt <= m; nxt++) {
                        if (nxt == k) dp[i][j][k] = min(dp[i][j][k], dp[i - 1][j][k] + cost[i][nxt]);
                        else dp[i][j][nxt] = min(dp[i][j][nxt], dp[i - 1][j - 1][k] + cost[i][nxt]);
                    }
                }
            }
        }
    }
    int ans = 1LL << 60;
    for (int i = 1; i <= m; i++) ans = min(ans, dp[n][cmp][i]);
    printf("%lld\n", ans == 1LL << 60 ? -1 : ans);

    return 0;
}