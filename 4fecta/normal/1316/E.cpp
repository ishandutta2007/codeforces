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

const int MN = 100005;

int n, p, k, val[MN], a[MN][7]; ll dp[2][1 << 7];
vector<pii> ord;

int32_t main() {
    boost();

    memset(dp, -0x3f, sizeof(dp));
    dp[0][0] = 0;
    cin >> n >> p >> k;
    for (int i = 1; i <= n; i++) cin >> val[i], ord.push_back({val[i], i});
    sort(ord.begin(), ord.end(), greater<>());
    for (int i = 1; i <= n; i++) for (int j = 0; j < p; j++) cin >> a[i][j];
    for (int i = 1; i <= n; i++) {
        //printf("%d %d\n", ord[i - 1].f, ord[i - 1].s);
        for (int msk = 0; msk < 1 << p; msk++) {
            for (int s = 0; s < p; s++) {
                if (msk & (1 << s)) {
                    int cnt = i - __builtin_popcount(msk) - 1;
                    dp[i & 1][msk] = max(dp[i & 1][msk], dp[1 - (i & 1)][msk ^ (1 << s)] + a[ord[i - 1].s][s]);
                    if (cnt < k) dp[i & 1][msk] = max(dp[i & 1][msk], dp[1 - (i & 1)][msk] + ord[i - 1].f);
                    else dp[i & 1][msk] = max(dp[i & 1][msk], dp[1 - (i & 1)][msk]);
                }
            }
            int cnt = i - __builtin_popcount(msk) - 1;
            if (cnt < k) dp[i & 1][msk] = max(dp[i & 1][msk], dp[1 - (i & 1)][msk] + ord[i - 1].f);
            else dp[i & 1][msk] = max(dp[i & 1][msk], dp[1 - (i & 1)][msk]);
        }
    }
    printf("%lld\n", dp[n & 1][(1 << p) - 1]);

    return 0;
}