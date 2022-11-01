#include <bits/stdc++.h> 

using namespace std;

const int LG = 18;
const int N = 1e5 + 10;
const int INF = 2e9 + 10;

set <int> g[N];
int n, m, p[N][LG], depth[N];
int size[N], centree[N], ans[N];

void dfs (int u, int par, int deep = 0) {
    depth[u] = deep, p[u][0] = par;
    for (int v : g[u]) {
        if (v == par) continue;
        dfs(v, u, deep + 1);
    }
}

int comp;

void visit (int u, int par) {
    ++comp, size[u] = 1;
    for (int v : g[u]) {
        if (v == par) continue;
        visit(v, u);
        size[u] += size[v];
    }
}

int find_centroid (int u, int par) {
    for (int v : g[u]) {
        if (v == par) continue;
        if (size[v] > comp/2) {
            return find_centroid(v, u);
        }
    }
    return u;
}

void decompose (int u, int par) {
    comp = 0, visit(u, u);
    int centroid = find_centroid(u, u);
    if (par == -1) par = centroid;
    centree[centroid] = par;
    for (int v : g[centroid]) {
        g[v].erase(centroid);
        decompose(v, centroid);
    }
    g[centroid].clear();
}

int lca (int u, int v) {
    if (depth[u] < depth[v]) swap(u, v);
    for (int i = LG - 1; i >= 0; --i) {
        if (depth[u] - (1 << i) >= depth[v]) {
            u = p[u][i];
        }
    }
    if (u == v) return u;
    for (int i = LG - 1; i >= 0; --i) {
        if (p[u][i] != -1 and p[u][i] != p[v][i]) {
            u = p[u][i], v = p[v][i];
        }
    }
    return p[u][0];
}

int dist (int u, int v) {
    return depth[u] + depth[v] - 2 * depth[lca(u, v)];
}

void update (int u) {
    int x = u;
    while (true) {
        ans[x] = min(ans[x], dist(x, u));
        if (centree[x] == x) break;
        x = centree[x];
    }
}

int query (int u) {
    int x = u, res = INF;
    while (true) {
        res = min(res, ans[x] + dist(x, u));
        if (centree[x] == x) break;
        x = centree[x];
    }
    return res;
}

inline void read (int *a) {
    register char c = 0;
    while (c < 33) c = getchar();
    *a = 0;
    while (c > 33) {
        *a = *a * 10 + c - '0';
        c = getchar();
    }
}

int main (int argc, char const *argv[]) {
    read(&n); read(&m);
    for (int i = 1; i < n; ++i) {
        int u, v;
        read(&u); read(&v);
        g[u].insert(v);
        g[v].insert(u);
    }
    memset(p, -1, sizeof p);
    dfs(1, 1);
    decompose(1, -1);
    for (int j = 1; j < LG; ++j) {
        for (int i = 1; i <= n; ++i) {
            if (p[i][j - 1] != -1) {
                p[i][j] = p[p[i][j - 1]][j - 1];
            }
        }
    }
    for (int i = 1; i <= n; ++i) {
        ans[i] = INF;
    }
    update(1);
    while (m--) {
        int t, v;
        read(&t); read(&v);
        if (t == 1) {
            update(v);
        } else {
            printf("%d\n", query(v));
        }
    }
    return 0;
}