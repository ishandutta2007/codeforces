#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>

using namespace std;
using namespace __gnu_pbds;

typedef tree<int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update> ordered_set;

#define ll long long
#define ld long double
#define pii pair<int, int>
#define f first
#define s second
#define readl(_s) getline(cin, (_s));
#define boost() cin.tie(0); cin.sync_with_stdio(0)

int n, t, dp[1 << 15][226][3], MOD = 1e9 + 7;
pii a[15];

int main() {
    boost();

    cin >> n >> t;
    for (int i = 0; i < n; i++) {
        cin >> a[i].f >> a[i].s, a[i].s--;
        dp[1 << i][a[i].f][a[i].s] += 1;
    }
    for (int i = 1; i <= t; i++) {
        for (int msk = 0; msk < 1 << n; msk++) {
            for (int cur = 0; cur < n; cur++) {
                if (a[cur].f > i) continue;
                if (!(msk & (1 << cur))) continue;
                dp[msk][i][a[cur].s] += dp[msk ^ (1 << cur)][i - a[cur].f][(a[cur].s + 1) % 3];
                dp[msk][i][a[cur].s] += dp[msk ^ (1 << cur)][i - a[cur].f][(a[cur].s + 2) % 3];
                dp[msk][i][a[cur].s] %= MOD;
            }
        }
    }
    int ans = 0;
    for (int msk = 0; msk < 1 << n; msk++) {
        ans += dp[msk][t][0]; ans %= MOD;
        ans += dp[msk][t][1]; ans %= MOD;
        ans += dp[msk][t][2]; ans %= MOD;
    }
    printf("%d\n", ans);

    return 0;
}