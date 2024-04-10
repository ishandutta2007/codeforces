#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
#include <bits/stdc++.h>

using namespace __gnu_pbds;
using namespace std;

typedef tree <
  int,
  null_type,
  less < int >,
  rb_tree_tag,
  tree_order_statistics_node_update >
ordered_set;

int const maxn = 1e6 + 5;
vector < int > g[maxn];
pair < int, int > ans[maxn];
int timer = 0;
ordered_set Q;

void dfs(int v, int p) {
    int child = 0;
    for (auto u : g[v]) {
        if (u != p) child++;
    }
    ans[v].first = (*Q.find_by_order((int)Q.size() - 1- child));
    Q.erase(ans[v].first);
    for (auto u : g[v]) {
        if (u != p) {
            ans[u].second = (*Q.rbegin());
            Q.erase(ans[u].second);
        }
    }
    reverse(g[v].begin(), g[v].end());
    for (auto u : g[v]) {
        if (u != p) dfs(u, v);
    }
}

main() {
#ifdef HOME
    //freopen("input.txt", "r", stdin);
#endif // HOME
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int n, u, v;
    cin >> n;
    for (int i = 1; i < n; ++i) {
        cin >> u >> v;
        g[u].push_back(v);
        g[v].push_back(u);
    }
    ans[1].second = 2 * n, timer = 2 * n - 1;
    for (int i = 1; i <= 2 * n - 1; ++i) Q.insert(i);
    dfs(1, 0);
    for (int i = 1; i <= n; ++i) cout << ans[i].first << " " << ans[i].second << '\n';
    return 0;
}