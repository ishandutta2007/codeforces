#include <bits/stdc++.h>

using namespace std;

struct edge {
    int u, v, w, idx;
    bool operator < (const edge &x) const {
        return w < x.w;
    }
};

struct DSU {
    int n;
    vector<int> par, sz;
    DSU(int _n) {
        n = _n;
        par.resize(n);
        sz.resize(n, 1);
        for(int i = 0; i < n; i++)
            par[i] = i;
    }
    int find(int v) {
        return (v == par[v] ? v : par[v] = find(par[v]));
    }
    void unite(int u, int v) {
        u = find(u);
        v = find(v);
        if(u != v) {
            if(sz[u] < sz[v])
                swap(u, v);
            par[v] = u;
            sz[u] += sz[v];
        }
    }
};

int n, m;
edge e[200000], e1[200000];
DSU dsu(200000);
vector<bool> inspan;
vector<pair<int, int>> g[200000];
int up[200000][20], minw[200000][20];
int tin[200000], tout[200000], tik_tak;
vector<int> ans;
vector<int> add[200000], era[200000];
int link[200000];
multiset<int> setik[200000];
int eup[200000];

void dfs1(int v, int p) {
    tin[v] = tik_tak++;
    if(v == 0) {
        up[v][0] = v;
        minw[v][0] = 0;
    }
    for(int i = 1; i < 20; i++) {
        up[v][i] = up[up[v][i - 1]][i - 1];
        minw[v][i] = max(minw[v][i - 1], minw[up[v][i - 1]][i - 1]);
    }
    for(pair<int, int> to : g[v])
        if(to.first != p) {
            up[to.first][0] = v;
            minw[to.first][0] = e[to.second].w;
            eup[to.first] = to.second;
            dfs1(to.first, v);
        }
    tout[v] = tik_tak++;
}

bool upper(int u, int v) {
    return tin[u] < tin[v] && tout[u] > tout[v];
}

pair<int, int> lca(int u, int v) {
    if(tin[u] > tin[v])
        swap(u, v);
    int w = 0;
    if(upper(u, v)) {
        for(int i = 19; i >= 0; i--)
            if(!upper(up[v][i], u)) {
                w = max(w, minw[v][i]);
                v = up[v][i];
            }
        return {u, w};
    }
    for(int i = 19; i >= 0; i--)
        if(!upper(up[u][i], v)) {
            w = max(w, minw[u][i]);
            u = up[u][i];
        }
    for(int i = 19; i >= 0; i--)
        if(!upper(up[v][i], u)) {
            w = max(w, minw[v][i]);
            v = up[v][i];
        }
    return {up[u][0], max({w, minw[u][0], minw[v][0]})};
}

void dfs2(int v, int p) {
    int big = -1;
    for(pair<int, int> to : g[v])
        if(to.first != p) {
            dfs2(to.first, v);
            if(big == -1 || setik[link[to.first]].size() > setik[link[big]].size())
                big = to.first;
        }
    link[v] = (big == -1 ? v : link[big]);
    for(pair<int, int> to : g[v])
        if(to.first != p && to.first != big)
            for(int x : setik[link[to.first]])
                setik[link[v]].insert(x);
    for(int x : add[v])
        setik[link[v]].insert(x);
    for(int x : era[v])
        setik[link[v]].erase(setik[link[v]].find(x));
    if(v != 0 && !setik[link[v]].empty())
        ans[eup[v]] = *setik[link[v]].begin() - 1;
}

int main() {
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    //freopen("input.txt", "r", stdin);
    cin >> n >> m;
    for(int i = 0; i < m; i++) {
        cin >> e[i].u >> e[i].v >> e[i].w;
        --e[i].u; --e[i].v;
        e[i].idx = i;
        e1[i] = e[i];
    }
    sort(e1, e1 + m);
    inspan.resize(m, false);
    for(edge ee : e1)
        if(dsu.find(ee.u) != dsu.find(ee.v)) {
            dsu.unite(ee.u, ee.v);
            g[ee.u].push_back({ee.v, ee.idx});
            g[ee.v].push_back({ee.u, ee.idx});
            inspan[ee.idx] = true;
        }
    dfs1(0, -1);
    ans.resize(m, -1);
    for(int i = 0; i < m; i++)
        if(!inspan[i]) {
            int u = e[i].u, v = e[i].v;
            pair<int, int> lcaa = lca(u, v);
            ans[i] = lcaa.second - 1;
            if(tin[u] > tin[v])
                swap(u, v);
            if(lcaa.first == u) {
                add[v].push_back(e[i].w);
                era[u].push_back(e[i].w);
            } else {
                add[u].push_back(e[i].w);
                add[v].push_back(e[i].w);
                era[lcaa.first].push_back(e[i].w);
                era[lcaa.first].push_back(e[i].w);
            }
        }
    dfs2(0, -1);
    for(int i = 0; i < m; i++)
        cout << ans[i] << ' ';
}