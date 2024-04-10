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

const int MN = 100005;

int n, m, k, u, per[MN], dp[1 << 10][3]; //min cost to have mask i with j pizzas.
pii piz[MN], dp1[1 << 10][3];
vector<pii> v;

int32_t main() {
    boost();

    cin >> n >> m;
    for (int i = 1; i <= n; i++) {
        cin >> k;
        for (int j = 1; j <= k; j++) cin >> u, u--, per[i] |= 1 << u;
    }
    for (int i = 0; i < (1 << 10); i++) for (int j = 0; j < 3; j++) dp[i][j] = 1LL << 60;
    dp[0][0] = 0;
    for (int i = 1; i <= m; i++) {
        cin >> piz[i].f >> k;
        v.push_back({piz[i].f, i});
        for (int j = 1; j <= k; j++) cin >> u, u--, piz[i].s |= 1 << u;
        for (int msk = (1 << 9) - 1; msk >= 0; msk--) {
            int nxt = msk | piz[i].s;
            if (dp[nxt][2] > dp[msk][1] + piz[i].f) {
                dp[nxt][2] = dp[msk][1] + piz[i].f;
                dp1[nxt][2] = {i, dp1[msk][1].s};
            }
            if (dp[nxt][1] > dp[msk][0] + piz[i].f) {
                dp[nxt][1] = dp[msk][0] + piz[i].f;
                dp1[nxt][1] = {-1, i};
            }
        }
    }
    sort(v.begin(), v.end());
    int ans = 0, cost = 0;
    pii p = {v[0].s, v[1].s};
    for (int msk = 0; msk < (1 << 9); msk++) {
        if (dp[msk][2] >= 1LL << 60) continue;
        int cnt = 0;
        for (int i = 1; i <= n; i++) {
            int msk1 = per[i] | msk;
            if (msk == msk1) cnt++;
        }
        if (cnt > ans) ans = cnt, cost = dp[msk][2], p = dp1[msk][2];
        else if (cnt == ans && dp[msk][2] < cost) cost = min(cost, dp[msk][2]), p = dp1[msk][2];
    }
    printf("%lld %lld\n", p.f, p.s);

    return 0;
}