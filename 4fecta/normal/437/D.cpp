#include <bits/stdc++.h>

using namespace std;

#define ll long long
#define int ll
#define ld long double
#define pii pair<int, int>
#define f first
#define s second
#define readl(_s) getline(cin, (_s));
#define boost() cin.tie(0); cin.sync_with_stdio(0)

struct edge {
    int u, v, w;
};

const int MN = 100005;

int n, m, u, v, val[MN], par[MN], sz[MN];
edge ed[MN];

int find(int x) {
    if (x == par[x]) return x;
    return par[x] = find(par[x]);
}

bool merge(int x, int y) {
    x = find(x), y = find(y);
    if (x == y) return false;
    par[x] = par[y];
    sz[y] += sz[x];
    return true;
}

bool cmp(edge x, edge y) {
    return x.w > y.w;
}

int32_t main() {
    boost();

    ld ans = 0;
    cin >> n >> m;
    for (int i = 1; i <= n; i++) par[i] = i, sz[i] = 1;
    for (int i = 1; i <= n; i++) cin >> val[i];
    for (int i = 0; i < m; i++) {
        cin >> u >> v;
        ed[i] = {u, v, min(val[u], val[v])};
    }
    sort(ed, ed + m, cmp);
    for (int i = 0; i < m; i++) {
        if (find(ed[i].u) != find(ed[i].v)) {
            //printf("%d %d %d %d %d\n", ed[i].u, ed[i].v, sz[ed[i].u], sz[ed[i].v], ed[i].w);
            ans += sz[find(ed[i].u)] * sz[find(ed[i].v)] * ed[i].w;
            assert(merge(ed[i].u, ed[i].v));
        }
    }
    printf("%.6Lf\n", 2 * ans / (ld) ((n - 1) * n));
    //printf("%.6Lf\n", ans);

    return 0;
}