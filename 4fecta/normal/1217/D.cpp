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

const int MN = 5005;

int n, m, u, v, ans[MN], vis[MN], cnt = 1, depth[MN];
vector<pii> a[MN];

void dfs(int cur) {
    vis[cur] = 1;
    for (pii nxt : a[cur]) {
        if (!vis[nxt.f]) ans[nxt.s] = 1, dfs(nxt.f);
        else if (vis[nxt.f] == 2) ans[nxt.s] = 1;
        else ans[nxt.s] = 2, cnt = 2;
    }
    vis[cur] = 2;
}

int main() {
    boost();

    cin >> n >> m;
    for (int i = 1; i <= m; i++) {
        cin >> u >> v;
        a[u].push_back({v, i});
    }
    for (int i = 1; i <= n; i++) if (!vis[i]) dfs(i);
    printf("%d\n", cnt);
    for (int i = 1; i <= m; i++) printf("%d ", ans[i]);

    return 0;
}