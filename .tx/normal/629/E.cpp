#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <algorithm>
#include <vector>
#include <map>
#include <set>
#include <queue>
#include <unordered_map>
#include <unordered_set>
#include <deque>
#include <string>
#include <memory.h>

#define sci(a) scanf("%d", &a)
#define scii(a, b) scanf("%d%d", &a, &b)
#define sciii(a, b, c) scanf("%d%d%d", &a, &b, &c)

#define scid(a) int a; sci(a)
#define sciid(a, b) int a, b; scii(a, b)
#define sciiid(a, b, c) int a, b, c; sciii(a, b, c)

#define rea(a, n) for (int i = 0; i < n; i++) sci(a[i])

#define init_cin ios_base::sync_with_stdio(false); cin.tie(0);

typedef long long lint;

using namespace std;

lint sd[111111];
lint su[111111];
int cs[111111];
int up[111111][22];
int tin[111111], tout[111111];

vector<int> g[111111];
int tm = 0;

void dfs1(int v, int p) {
    tin[v] = tm++;
    int op = p;
    for (int i = 0; p != -1; i++) {
        up[v][i] = p;
        p = up[p][i];
    }
    cs[v] = 1;
    for (int i : g[v]) {
        if (i != op) {
            dfs1(i, v);
            sd[v] += sd[i] + cs[i];
            cs[v] += cs[i];
        }
    }
    tout[v] = tm++;
}

int n;

void dfs2(int v, int p) {
    if (p != -1) {
        su[v] = su[p] + n - cs[p] + sd[p] - sd[v] - cs[v] + cs[p] - cs[v];
    }
    for (int i : g[v]) {
        if (i != p) {
            dfs2(i, v);
        }
    }
}

bool isAncestor(int anc, int prec) {
    return tin[anc] <= tin[prec] && tout[prec] <= tout[anc];
}

int lca(int u, int v) {
    if (isAncestor(u, v)) {
        return u;
    }
    if (isAncestor(v, u)) {
        return v;
    }
    for (int i = 20; i >= 0; i--) {
        if (up[u][i] != -1 && !isAncestor(up[u][i], v)) {
            u = up[u][i];
        }
    }
    return up[u][0];
}

int predLca(int u, int v) {
    for (int i = 20; i >= 0; i--) {
        if (up[v][i] != -1 && !isAncestor(up[v][i], u)) {
            v = up[v][i];
        }
    }
    return v;
}

int len(int prec, int anc) {
    int res = 0;
    for (int i = 20; i >= 0; i--) {
        if (up[prec][i] != -1 && !isAncestor(up[prec][i], anc)) {
            res += 1 << i;
            prec = up[prec][i];
        }
    }
    return res + 1;
}

int main() {
    sci(n);
    scid(m);
    for (int i = 0; i + 1 < n; i++) {
        sciid(x, y);
        --x; --y;
        g[x].push_back(y);
        g[y].push_back(x);
    }
    memset(up, -1, sizeof(int) * 111111 * 22);
    dfs1(0, -1);
    dfs2(0, -1);
    while (m-- > 0) {
        sciid(x, y);
        --x; --y;
        if (isAncestor(y, x)) {
            swap(x, y);
        }
        if (isAncestor(x, y)) {
            int cy = cs[y];
            int pl = predLca(x, y);
            int cx = n - cs[pl];
            lint sy = sd[y];
            lint sx = su[x] + sd[x] - sd[pl] - cs[pl];
            double as = 1.0 * sy * cx + 1.0 * sx * cy;
            as /= (1.0 * cx * cy);
            printf("%.11f\n", as + len(y, x) + 1);
            continue;
        }
        int cy = cs[y];
        int cx = cs[x];
        lint sy = sd[y];
        lint sx = sd[x];
        double as = 1.0 * sy * cx + 1.0 * sx * cy;
        as /= (1.0 * cx * cy);
        int lc = lca(x, y);
        printf("%.11f\n", as + len(x, lc) + len(y, lc) + 1);
    }

    return 0;
}