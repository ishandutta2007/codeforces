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

const int MN = 200005;

int n, m, val[MN], u, v, st, deg[MN], dp[MN], vis[MN];
vector<int> a[MN];

int32_t main() {
    boost();

    cin >> n >> m;
    for (int i = 1; i <= n; i++) cin >> val[i]; //we need to prune bcc tree with nodes of size > 1. oh wait can just do it like that ccc problem
    for (int i = 1; i <= m; i++) {
        cin >> u >> v;
        a[u].push_back(v);
        a[v].push_back(u);
        deg[u]++; deg[v]++;
    }
    cin >> st;
    if (n == 1) return 0 * printf("%lld\n", val[st]);
    queue<int> q;
    int mx = 0;
    for (int i = 1; i <= n; i++) {
        if (deg[i] == 1 && i != st) vis[i] = 1, q.push(i), mx = max(mx, dp[i]);
    }
    while (q.size()) {
        int cur = q.front(); q.pop();
        mx = max(mx, dp[cur]);
        for (int nxt : a[cur]) {
            if (vis[nxt]) continue;
            deg[nxt]--;
            dp[nxt] = max(dp[nxt], val[cur] + dp[cur]);
            mx = max(mx, dp[nxt]);
            if (deg[nxt] == 1 && nxt != st) {
                vis[nxt] = 1;
                q.push(nxt);
            }
        }
    }
    assert(!vis[st]);
    for (int i = 1; i <= n; i++) if (!vis[i]) mx += val[i];
    printf("%lld\n", mx);

    return 0;
}