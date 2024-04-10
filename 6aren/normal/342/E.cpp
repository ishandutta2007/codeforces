//https://codeforces.com/contest/342/problem/E
#include <bits/stdc++.h>
using namespace std;

#define all(s) s.begin(), s.end()
#define vi vector<int>
#define pb push_back
#define ii pair<int, int>
#define x first
#define y second

const int N = 100005;
const int BL = (int) sqrt(N) + 1;

struct LCA {
    int n, l, timer;
    vector<vector<int>> g, up;
    vector<int> tin, tout;
    LCA() {
        g.clear();
        up.clear();
        tin.clear();
        tout.clear();
        n = 0, l = 0;
        timer = 0;
    }

    LCA(int _n) {
        timer = 0;
        n = _n;
        l = log2(_n) + 1;
        g.resize(n + 1);
        up.resize(l + 1);
        tin.resize(n + 1, 0);
        tout.resize(n + 1, 0);
        for (int i = 0; i <= l; i++) {
            up[i].resize(n + 1, 0);
        }
    }

    void addEdge(int u, int v) {
        g[u].pb(v);
        g[v].pb(u);
    }

    void dfs(int u, int par) {
        tin[u] = timer++;
        for (auto v : g[u]) {
            if (v == par) continue;
            up[0][v] = u;
            dfs(v, u);
        }
        tout[u] = timer;
    }

    void prepare(int root) {
        g[0].push_back(root);
        dfs(0, -1);
        for (int i = 1; i <= l; i++) {
            for (int j = 0; j <= n; j++) {
                up[i][j] = up[i - 1][up[i - 1][j]];
            }
        }
    }

    bool isAncestor(int u, int v) {
        return (tin[u] <= tin[v] && tout[u] >= tout[v]);
    }

    int lca(int u, int v) {
        if (isAncestor(u, v)) return u;
        if (isAncestor(v, u)) return v;
        for (int i = l; i >= 0; i--) {
            if (!isAncestor(up[i][u], v)) {
                u = up[i][u];
            }
        }
        return up[0][u];
    }
} lca;

int dep[N], d[N];
bool check[N];

void dfs(int cur, int pre) {
    for (int e : lca.g[cur]) {
        if (e == pre) continue;
        dep[e] = dep[cur] + 1;
        dfs(e, cur);
    }
}

int dis(int u, int v) {
    return (dep[u] + dep[v] - 2 * dep[lca.lca(u, v)]); 
}

int main() {
    ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    int n, m;
    cin >> n >> m;
    lca = LCA(n);
    for (int i = 1; i < n; i++) {
        int u, v;
        cin >> u >> v;
        lca.addEdge(u, v);
    }
    dfs(1, 0);
    for (int i = 1; i <= n; i++) {
        d[i] = dep[i];
    }
    lca.prepare(1);
    vi cur;
    for (int i = 1; i <= m; i++) {
        int type, u;
        cin >> type >> u;
        if (type == 1) {
            cur.pb(u);
        } else {
            int ans = d[u];
            for (int e : cur) {
                ans = min(ans, dis(u, e));
            }
            cout << ans << '\n';
        }
        if (i % BL == 0) {
            queue<ii> q;
            memset(check, 0, sizeof(check));
            for (int e : cur) q.push({e, 0}), d[e] = 0;
            cur.clear();
            while (!q.empty()) {
                int u = q.front().x;
                int val = q.front().y;
                q.pop();
                for (int e : lca.g[u]) {
                    if (check[e]) continue;
                    if (d[e] <= val + 1) continue;
                    d[e] = val + 1;
                    q.push({e, val + 1});
                }
            }
        }
    }
    return 0;
}