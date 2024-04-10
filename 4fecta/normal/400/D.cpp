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

const int MN = 100005;

int n, m, k, u, v, w, sz[505], dist[505][505], lbl[MN];
pii par[MN];
vector<pii> a[MN];
vector<pii> g[MN];
vector<pair<pii, int>> edge;

int find(int x) {
    if (par[x].f == x) return x;
    return par[x].f = find(par[x].f);
}

bool merge(int x, int y) {
    x = find(x), y = find(y);
    if (x == y) return false;
    if (sz[x] < sz[y]) par[x].f = par[y].f, par[y].s += par[x].s;
    else par[y].f = par[x].f, par[x].s += par[y].s;
    return true;
}

void dijk(int idx) {
    priority_queue<pii, vector<pii>, greater<>> q;
    q.push({0, idx});
    while (q.size()) {
        pii cur = q.top(); q.pop();
        if (cur.f > dist[idx][cur.s]) continue;
        for (pii nxt : g[cur.s]) {
            if (dist[idx][nxt.f] <= dist[idx][cur.s] + nxt.s) continue;
            dist[idx][nxt.f] = dist[idx][cur.s] + nxt.s;
            q.push({dist[idx][nxt.f], nxt.f});
        }
    }
}

int main() {
    memset(dist, 0x3f, sizeof(dist));
    boost();
    for (int i = 0; i < MN; i++) par[i] = {i, 1};
    cin >> n >> m >> k;
    for (int i = 1; i <= k; i++) cin >> sz[i];
    for (int i = 0; i < m; i++) {
        cin >> u >> v >> w;
        a[u].push_back({v, w});
        a[v].push_back({u, w});
        edge.push_back({{u, v}, w});
        if (!w) merge(u, v);
    }
    int idx = 1;
    for (int i = 1; i <= k; i++) {
        int num = find(idx);
        for (int j = idx; j < idx + sz[i]; j++) {
            lbl[j] = i;
            if (find(j) != num) {printf("No\n"); return 0;}
        }
        idx += sz[i];
        dist[i][i] = 0;
    }
    for (auto p : edge) {
        if (lbl[p.f.f] == lbl[p.f.s]) continue;
        g[lbl[p.f.f]].push_back({lbl[p.f.s], p.s});
        g[lbl[p.f.s]].push_back({lbl[p.f.f], p.s});
    }

    for (int i = 1; i <= k; i++) {
        dijk(i);
    }
    printf("Yes\n");
    for (int i = 1; i <= k; i++) {
        for (int j = 1; j <= k; j++) {
            if (dist[i][j] == 0x3f3f3f3f) printf("-1 ");
            else printf("%d ", dist[i][j]);
        }
        printf("\n");
    }

    return 0;
}