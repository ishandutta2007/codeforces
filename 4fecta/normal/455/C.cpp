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

int n, m, q, u, v, t, par[MN], dia[MN], dist[MN], vis[MN], mx, tmp;
vector<int> a[MN];

int find(int x) {
    return x == par[x] ? x : par[x] = find(par[x]);
}

bool merge(int x, int y) {
    x = find(x), y = find(y);
    if (x == y) return false;
    par[y] = par[x];
    dia[x] = max({dia[x], dia[y], (dia[x] + 1) / 2 + (dia[y] + 1) / 2 + 1});
    return true;
}

void dfs(int cur, int pre, int d) {
    dist[cur] = d;
    if (dist[cur] > mx) mx = dist[cur], tmp = cur;
    for (int nxt : a[cur]) if (nxt != pre) dfs(nxt, cur, d + 1);
}

void dfs1(int cur, int pre, int id) {
    vis[cur] = 1;
    par[cur] = id;
    for (int nxt : a[cur]) if (nxt != pre) dfs1(nxt, cur, id);
}

void proc(int st) {
    mx = tmp = -1;
    dfs(st, 0, 0);
    mx = -1;
    dfs(tmp, 0, 0);
    dia[st] = mx;
    dfs1(st, 0, st);
}

int main() {
    boost();

    cin >> n >> m >> q;
    for (int i = 1; i <= n; i++) par[i] = i;
    for (int i = 1; i <= m; i++) {
        cin >> u >> v;
        a[u].push_back(v);
        a[v].push_back(u);
    }
    for (int i = 1; i <= n; i++) {
        if (!vis[i]) proc(i);
    }
    for (int i = 1; i <= q; i++) {
        cin >> t;
        if (t == 2) {
            cin >> u >> v;
            merge(u, v);
        } else {
            cin >> u;
            printf("%d\n", dia[find(u)]);
        }
    }

    return 0;
}