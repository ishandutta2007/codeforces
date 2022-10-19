#include <bits/stdc++.h>
using namespace std;

#define all(s) s.begin(), s.end()
#define vi vector<int>
#define pb push_back
#define ii pair<int, int>
#define x first
#define y second

struct CentroidDecomposition {
    int n;
    vector<vector<int>> g, gCentroid;
    vector<bool> deleted;
    vector<int> sz;
    vector<int> p;
    
    CentroidDecomposition() {
    }

    CentroidDecomposition(int _n) {
        n = _n;
        g.resize(n + 1); gCentroid.resize(n + 1);
        deleted.resize(n + 1);
        sz.resize(n + 1);
        p.resize(n + 1);
    }

    void addEdge(int u, int v) {
        g[u].pb(v);
        g[v].pb(u);
    }

    void calcSz(int cur, int pre) {
        sz[cur] = 1;
        for (int u : g[cur]) {
            if (u == pre) continue;
            if (deleted[u]) continue;
            calcSz(u, cur);
            sz[cur] += sz[u];
        }
    } 

    int findCentroid(int cur, int pre, int subtreeSize) {
        int mxSz = 0;
        for (int u : g[cur]) {
            if (u == pre) continue;
            if (deleted[u]) continue;
            if (sz[mxSz] < sz[u]) mxSz = u;
        }
        if (sz[mxSz] <= subtreeSize / 2) return cur;
        else return findCentroid(mxSz, cur, subtreeSize);
    }

    void buildCentroid(int cur, int parent) {
        calcSz(cur, 0);
        int centroid = findCentroid(cur, 0, sz[cur]);
        gCentroid[parent].pb(centroid);
        p[centroid] = parent;
        deleted[centroid] = 1;
        for (int e : g[centroid]) {
            if (!deleted[e]) buildCentroid(e, centroid);
        }
    }

    void work() {
        buildCentroid(1, 0);
    }
} cd;

int level[100005];

void dfs(int u, int v) {
    for (int e : cd.gCentroid[u]) {
        if (e == v) continue;
        level[e] = level[u] + 1;
        dfs(e, u);
    }
}

int main() {
    ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    int n;
    cin >> n;
    cd = CentroidDecomposition(n);
    for (int i = 1; i < n; i++) {
        int u, v;
        cin >> u >> v;
        cd.addEdge(u, v);
    }
    cd.work();
    dfs(cd.gCentroid[0][0], 0);
    for (int i = 1; i <= n; i++) {
        cout << (char) ('A' + level[i]) << ' ';
    }
    return 0;
}