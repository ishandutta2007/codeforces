#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define int ll
#define ld long double
#define pii pair<int, int>
#define f first
#define s second
#define boost() cin.tie(0), cin.sync_with_stdio(0)

const int MN = 100005, LOG = 18;

int n, m, u, v, sz[MN], vis[MN], red[MN], par[MN], dist[LOG][MN], dep[MN];
vector<int> a[MN];

int size_of(int cur, int pre) {
    sz[cur] = 1;
    for (int nxt : a[cur]) if (!vis[nxt] && nxt != pre) sz[cur] += size_of(nxt, cur);
    return sz[cur];
}

int get_centroid(int cur, int pre, int cnt) {
    for (int nxt : a[cur]) if (!vis[nxt] && nxt != pre && sz[nxt] > cnt) return get_centroid(nxt, cur, cnt);
    return cur;
}

void dfs(int cur, int pre, int d, int lvl) {
    dist[lvl][cur] = d;
    for (int nxt : a[cur]) if (!vis[nxt] && nxt != pre) dfs(nxt, cur, d + 1, lvl);
}

void solve(int cur, int pre) {
    cur = get_centroid(cur, 0, size_of(cur, 0) / 2);
    dep[cur] = dep[pre] + 1;
    par[cur] = pre;
    red[cur] = 0x3f3f3f3f;
    dfs(cur, 0, 0, dep[cur]);
    vis[cur] = 1;
    for (int nxt : a[cur]) {
        if (vis[nxt]) continue;
        solve(nxt, cur);
    }
}

int32_t main() {
    boost();

    cin >> n >> m;
    for (int i = 1; i < n; i++) {
        cin >> u >> v;
        a[u].push_back(v);
        a[v].push_back(u);
    }
    solve(1, 0);
    for (int p = 1; p > 0; p = par[p]) red[p] = min(red[p], dist[dep[p]][1]);
    while (m--) {
        cin >> u >> v;
        if (u == 1) {
            for (int p = v; p > 0; p = par[p]) red[p] = min(red[p], dist[dep[p]][v]);
        } else {
            int ret = 0x3f3f3f3f;
            for (int p = v; p > 0; p = par[p]) ret = min(ret, dist[dep[p]][v] + red[p]);
            printf("%lld\n", ret);
        }
    }

    return 0;
}