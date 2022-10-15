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

const int MN = 1005;

int n, m, cost[MN], lim[MN], u, v, x, y, w;
ll dist[MN];
vector<pii> a[MN], g[MN];

void dijk(int st) {
    for (int i = 0; i < MN; i++) dist[i] = LLONG_MAX >> 1;
    priority_queue<pii, vector<pii>, greater<>> q;
    dist[st] = 0;
    q.push({0, st});
    while (q.size()) {
        pii cur = q.top(); q.pop();
        if (cur.f > dist[cur.s] || cur.f > lim[st]) continue;
        for (pii nxt : a[cur.s]) {
            if (dist[nxt.f] > dist[cur.s] + nxt.s) {
                dist[nxt.f] = dist[cur.s] + nxt.s;
                q.push({dist[nxt.f], nxt.f});
            }
        }
    }
    for (int i = 1; i <= n; i++) {
        if (i == st) continue;
        if (dist[i] <= lim[st]) {
            g[st].push_back({i, cost[st]});
        }
    }
}

void dijk1(int st) {
    for (int i = 0; i < MN; i++) dist[i] = LLONG_MAX >> 1;
    priority_queue<pii, vector<pii>, greater<>> q;
    dist[st] = 0;
    q.push({0, st});
    while (q.size()) {
        pii cur = q.top(); q.pop();
        if (cur.f > dist[cur.s]) continue;
        for (pii nxt : g[cur.s]) {
            if (dist[nxt.f] > dist[cur.s] + nxt.s) {
                dist[nxt.f] = dist[cur.s] + nxt.s;
                q.push({dist[nxt.f], nxt.f});
            }
        }
    }
}

int main() {
    boost();

    cin >> n >> m >> x >> y;
    for (int i = 0; i < m; i++) {
        cin >> u >> v >> w;
        a[u].push_back({v, w});
        a[v].push_back({u, w});
    }
    for (int i = 1; i <= n; i++) {
        cin >> lim[i] >> cost[i];
        dijk(i);
    }
    dijk1(x);
    printf("%lld\n", dist[y] == (LLONG_MAX >> 1) ? -1 : dist[y]);

    return 0;
}