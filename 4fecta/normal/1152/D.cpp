#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>

using namespace std;
using namespace __gnu_pbds;

typedef tree<int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update> ordered_set;

#define ll long long
#define int ll
#define ld long double
#define pii pair<int, int>
#define f first
#define s second
#define readl(_s) getline(cin, (_s));
#define boost() cin.tie(0); cin.sync_with_stdio(0)

const int MN = 2005, MOD = 1e9 + 7;

int n, dp[MN][MN], take[MN][MN];

int rec(int lvl, int delta) {
    if (dp[lvl][delta] != -1) return dp[lvl][delta];
    dp[lvl][delta] = 0;
    int tmp = 0;
    if (delta > 0) dp[lvl][delta] += rec(lvl - 1, delta - 1), tmp += !take[lvl - 1][delta - 1];
    if (delta + 1 <= lvl - 1) dp[lvl][delta] += rec(lvl - 1, delta + 1), tmp += !take[lvl - 1][delta + 1];
    if (tmp) dp[lvl][delta]++, take[lvl][delta] = 1;
    dp[lvl][delta] %= MOD;
    return dp[lvl][delta];
}

int32_t main() {
    boost();

    cin >> n;
    memset(dp, -1, sizeof(dp));
    dp[0][0] = 0;
    printf("%lld\n", rec(2 * n, 0) % MOD);
    /*for (int i = 0; i <= 2 * n; i++) {
        for (int j = 0; j <= 2 * n; j++) printf("%d ", dp[i][j]);
        printf("\n");
    }
    printf("\n");
    for (int i = 0; i <= 2 * n; i++) {
        for (int j = 0; j <= 2 * n; j++) printf("%d ", take[i][j]);
        printf("\n");
    }*/

    return 0;
}