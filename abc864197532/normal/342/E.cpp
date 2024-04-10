#include <bits/stdc++.h>
using namespace std;
const int N = 100000, C = 350;

vector <int> adj[N];
int dep[N], _t, n, euler_tour[N * 2 + 1], idx[N];

struct SparseTableMin {
    vector <vector <int>> table;
    void build (vector <int> a) {
        int n = a.size();
        int m = __lg(n) + 1;
        table.resize(n, vector <int> (m, 0));
        for (int i = 0; i < n; ++i)
            table[i][0] = a[i];
        for (int j = 1; j < m; ++j) {
            for (int i = 0; i + (1 << j) <= n; ++i) {
                table[i][j] = min(table[i][j - 1], table[i + (1 << j - 1)][j - 1]);
            }
        }
    }
    int query(int l, int r) {
        if (l == r)
            return -1;
        int g = __lg(r - l);
        return min(table[l][g], table[r - (1 << g)][g]);
    }
} ST;

void dfs(int v, int pa) {
    idx[v] = _t;
    euler_tour[_t++] = v;
    dep[v] = ~pa ? dep[pa] + 1 : 0;
    for (int u : adj[v]) if (u != pa) {
        dfs(u, v);
        euler_tour[_t++] = v;
    }
}

void lca_build() {
    dfs(0, -1);
    vector <int> ord(n * 2 - 1);
    for (int i = 0; i < n * 2 - 1; ++i)
        ord[i] = dep[euler_tour[i]];
    ST.build(ord);
}

int query_dis(int u, int v) {
    return dep[u] + dep[v] - ST.query(min(idx[u], idx[v]), max(idx[u], idx[v]) + 1) * 2;
}

int dis[N], col[N];
vector <int> same_block_vertex;

void rebuild_dis() {
    for (int v : same_block_vertex)
        col[v] = 1;
    same_block_vertex.clear();
    queue <int> q;
    fill(dis, dis + n, -1);
    for (int i = 0; i < n; ++i) if (col[i]) {
        dis[i] = 0;
        q.push(i);
    }
    while (!q.empty()) {
        int v = q.front(); q.pop();
        for (int u : adj[v]) if (dis[u] == -1) {
            dis[u] = dis[v] + 1;
            q.push(u);
        }
    }
}

int main () {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int q;
    cin >> n >> q;
    for (int i = 0, u, v; i < n - 1; ++i) {
        cin >> u >> v, --u, --v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    lca_build();
    col[0] = 1;
    for (int i = 0; i < q; ++i) {
        if (i % C == 0) {
            rebuild_dis();
        }
        int t, v;
        cin >> t >> v, --v;
        if (t == 1) {
            same_block_vertex.push_back(v);
        } else {
            int ans = dis[v];
            for (int u : same_block_vertex) {
                ans = min(ans, query_dis(u, v));
            }
            cout << ans << '\n';
        }
    }
}