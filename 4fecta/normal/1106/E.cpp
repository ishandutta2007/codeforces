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

const int MN = 100001;

int n, m, k; ll dp[MN][201];
multiset<pii> active;
vector<vector<pii>> on, off;
vector<pii> greed;

ll rec(int i, int j) {
    if (i > n) return 0;
    if (dp[i][j] != -1) return dp[i][j];
    if (greed[i].f == -1) return dp[i][j] = rec(i + 1, j);
    dp[i][j] = greed[i].f + rec(greed[i].s + 1, j);
    if (j > 0) dp[i][j] = min(dp[i][j], rec(i + 1, j - 1));
    return dp[i][j];
}

int32_t main() {
    boost();
    
    memset(dp, -1, sizeof dp);
    cin >> n >> m >> k;
    on.resize(n + 1), off.resize(n + 1), greed.resize(n + 1);
    for (int i = 1; i <= k; i++) {
        int s, t, d, w;
        cin >> s >> t >> d >> w;
        on[s].push_back({w, d});
        if (t < n) off[t + 1].push_back({w, d});
    }
    for (int i = 1; i <= n; i++) {
        for (pii p : on[i]) active.insert(p);
        for (pii p : off[i]) {
            auto it = active.find(p);
            active.erase(it);
        }
        if (active.empty()) greed[i] = {-1, -1};
        else greed[i] = *active.rbegin();
    }
    printf("%lld\n", rec(1, m));

    return 0;
}