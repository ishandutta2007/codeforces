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

const int MN = 5002;

int n, k, x, a[MN], dp[MN][MN];
deque<pii> q[MN];

ll qry(int l, int r, int t) {
    while (q[t].size() && q[t].front().s < l) q[t].pop_front();
    if (q[t].empty()) return LLONG_MIN / 2;
    return q[t].front().f;
}

int32_t main() {
    boost();

    cin >> n >> k >> x;
    q[0].push_back({0, 0});
    for (int i = 1; i <= n; i++) cin >> a[i];
    for (int i = 1; i <= n + 1; i++) {
        for (int j = x + 1; j >= 1; j--) {
            dp[i][j] = qry(max(0LL, i - k), i - 1, j - 1) + a[i];
            while (q[j].size() && q[j].back().f <= dp[i][j]) q[j].pop_back();
            q[j].push_back({dp[i][j], i});
        }
    }
    if (dp[n + 1][x + 1] > 0) printf("%lld\n", dp[n + 1][x + 1]);
    else printf("-1\n");

    return 0;
}