#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <algorithm>
#include <vector>
#include <queue>
#include <map>
#include <set>
#include <unordered_map>
#include <string>
#include <memory.h>

#define sci(a) scanf("%d", &a)
#define scii(a, b) scanf("%d%d", &a, &b)
#define sciii(a, b, c) scanf("%d%d%d", &a, &b, &c)

#define scid(a) int a; sci(a)
#define sciid(a, b) int a, b; scii(a, b)
#define sciiid(a, b, c) int a, b, c; sciii(a, b, c)

#define rvei(a, n) for (int i = 0; i < n; i++) sci(a[i])
#define rveid(a, n) vector<int> a(n); rvei(a, n)

#define init_cin ios_base::sync_with_stdio(false); cin.tie(0);

typedef long long lint;

using namespace std;

const int N = 222222;

struct Edge {
    int from, to, w, id;

    Edge(int from, int to, int w, int id) : from(from), to(to), w(w), id(id) {
    }
};

struct DSU {
    int a[N];
    int r[N];

    DSU(int n) {
        for (int i = 0; i < n; i++) {
            a[i] = i;
            r[i] = 1;
        }
    }

    int get(int x) {
        return a[x] == x ? x : a[x] = get(a[x]);
    }

    void unite(int x, int y) {
        x = get(x);
        y = get(y);
        if (r[x] < r[y]) {
            a[x] = y;
        } else if (r[x] > r[y]) {
            a[y] = x;
        } else {
            a[y] = x;
            r[x]++;
        }
    }
};

vector<pair<int, int> > mst[N];

int up[N][22];
int tin[N];
int tout[N];
int mxw[N][22];

int tim = 0;

void build(int v, int p, int w) {
    int op = p;
    for (int i = 0; p != -1; i++) {
        mxw[v][i] = max(mxw[v][i], w);
        w = max(w, mxw[p][i]);
        up[v][i] = p;
        p = up[p][i];
    }
    p = op;
    tin[v] = tim++;
    for (auto &i : mst[v]) {
        if (i.first != p) {
            build(i.first, v, i.second);
        }
    }
    tout[v] = tim++;
}

bool isAncestor(int anc, int desc) {
    return tin[anc] <= tin[desc] && tout[anc] >= tout[desc];
}

int lca(int x, int y) {
    if (isAncestor(x, y)) {
        return x;
    }
    if (isAncestor(y, x)) {
        return y;
    }
    for (int i = 21; i >= 0; i--) {
        if (up[x][i] != -1 && !isAncestor(up[x][i], y)) {
            x = up[x][i];
        }
    }
    return up[x][0];
}

int maxWeight(int x, int y) {
    int res = 0;
    for (int i = 21; i >= 0; i--) {
        if (up[x][i] != -1 && isAncestor(y, up[x][i])) {
            res = max(res, mxw[x][i]);
            x = up[x][i];
        }
    }
    return res;
}

lint ans[N];

int main() {
    sciid(n, m);
    vector<Edge> edges;
    for (int i = 0; i < m; i++) {
        sciiid(x, y, z);
        --x; --y;
        edges.push_back(Edge(x, y, z, i));
    }

    sort(edges.begin(), edges.end(), [] (const Edge &a, const Edge &b) { return a.w < b.w;});
    DSU dsu(n);
    lint mstW = 0;
    for (auto &e : edges) {
        if (dsu.get(e.from) != dsu.get(e.to)) {
            dsu.unite(e.from, e.to);
            mst[e.from].push_back({e.to, e.w});
            mst[e.to].push_back({e.from, e.w});
            mstW += e.w;
        }
    }
    memset(up, -1, sizeof(int) * N * 22);
    build(0, -1, -1);

    for (auto &e : edges) {
        int lc = lca(e.from, e.to);
        int mx = max(maxWeight(e.from, lc), maxWeight(e.to, lc));
        ans[e.id] = mstW - mx + e.w;
    }

    for (int i = 0; i < m; i++) {
        printf("%I64d\n", ans[i]);
    }

    return 0;
}