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

const int MN = 300005;

int n, sz[MN], dp[MN], ans; //dp is max path len
vector<int> a[MN];

void dfs(int cur, int par) {
    priority_queue<int> s;
    dp[cur] = sz[cur] + 1;
    for (int nxt : a[cur]) {
        if (nxt == par) continue;
        dfs(nxt, cur);
        s.push(dp[nxt]);
        dp[cur] = max(dp[cur], dp[nxt] + sz[cur] - 1);
    }
    ans = max(ans, dp[cur]);
    if (s.size() > 1) {
        int p1 = s.top(); s.pop();
        int p2 = s.top(); s.pop();
        ans = max(ans, p1 + p2 + sz[cur] - 3);
    }
}

int main() {
    boost();

    int t;
    cin >> t;
    while (t--) {
        cin >> n;
        for (int i = 1, u, v; i < n; i++) {
            cin >> u >> v;
            a[u].push_back(v);
            a[v].push_back(u);
            sz[u]++, sz[v]++;
        }
        dfs(1, 0);
        printf("%d\n", ans);
        for (int i = 1; i <= n; i++) {
            sz[i] = 0;
            a[i].clear();
            dp[i] = 0;
        }
        ans = 0;
    }

    return 0;
}