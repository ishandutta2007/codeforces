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

const int MN = 1000005;

int n, m, u, v, loop[MN], vis[MN];
vector<int> a[MN];
ll ans, cnt;

void dfs(int cur) {
    vis[cur] = 1;
    for (int nxt : a[cur]) {
        if (vis[nxt]) continue;
        dfs(nxt);
    }
}

int32_t main() {
    boost();

    cin >> n >> m;
    for (int i = 1; i <= m; i++) {
        cin >> u >> v;
        if (u == v) {cnt++; loop[u]++; continue;}
        a[u].push_back(v);
        a[v].push_back(u);
    }
    for (int i = 1; i <= n; i++) if (a[i].size() || loop[i]) {dfs(i); break;}
    for (int i = 1; i <= n; i++) if (!vis[i] && (a[i].size() || loop[i])) return 0 * printf("0\n");
    for (int i = 1; i <= n; i++) ans += (ll) a[i].size() * ((ll) a[i].size() - 1) / 2;
    ans += cnt * (cnt - 1) / 2 + cnt * (m - cnt);
    printf("%lld\n", ans);

    return 0;
}