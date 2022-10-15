#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>

using namespace std;
using namespace __gnu_pbds;

typedef tree<int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update> ordered_set;

#define ll long long
#define ld long double
#define int ll
#define pii pair<int, int>
#define f first
#define s second
#define readl(_s) getline(cin, (_s));
#define boost() cin.tie(0); cin.sync_with_stdio(0)

struct edge {
    int u, v, w, i;
};

const int MN = 300005;

int n, m, u, v, w, dist[MN], par[MN], st;
vector<pii> a[MN];
edge edges[MN];
vector<edge> opt;
vector<int> inc;
vector<edge> g[MN];

bool cmp(edge x, edge y) {
    return x.w < y.w;
}

int find(int x) {
    return x == par[x] ? x : par[x] = find(par[x]);
}

bool merge(int x, int y) {
    x = find(x), y = find(y);
    if (x == y) return false;
    par[x] = par[y];
    return true;
}

int32_t main() {
    boost();

    cin >> n >> m;
    for (int i = 1; i <= m; i++) {
        cin >> u >> v >> w;
        a[u].push_back({v, w});
        a[v].push_back({u, w});
        edges[i] = {u, v, w};
    }
    cin >> st;
    priority_queue<pii, vector<pii>, greater<pii>> q;
    for (int i = 1; i <= n; i++) dist[i] = 1LL << 60;
    dist[st] = 0;
    q.push({0, st});
    while (q.size()) {
        pii cur = q.top(); q.pop();
        if (cur.f > dist[cur.s]) continue;
        for (pii nxt : a[cur.s]) {
            if (dist[nxt.f] <= dist[cur.s] + nxt.s) continue;
            dist[nxt.f] = dist[cur.s] + nxt.s;
            q.push({dist[nxt.f], nxt.f});
        }
    }
    for (int i = 1; i <= m; i++) {
        edge e = edges[i];
        if (abs(dist[e.u] - dist[e.v]) == e.w) {
            if (dist[e.u] > dist[e.v]) swap(e.u, e.v);
            g[e.v].push_back({0, e.u, e.w, i});
        }
    }
    int ans = 0;
    for (int i = 1; i <= n; i++) {
        ll mn = 1LL << 60;
        int choice = 0;
        for (edge e : g[i]) {
            if (e.w < mn) {
                mn = e.w;
                choice = e.i;
            }
        }
        if (choice) inc.push_back(choice), ans += mn;
    }
    printf("%lld\n", ans);
    for (int i : inc) printf("%lld ", i);

    return 0;
}