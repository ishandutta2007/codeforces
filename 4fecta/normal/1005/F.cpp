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

const int MN = 200005;

int n, m, k, u, v, vis[MN], cnt[MN], ans[MN], dist[MN];
pii edge[MN];
vector<int> g[MN], poss[MN];
ll res;

int adj(int cur, int ed) {
    return cur == edge[ed].f ? edge[ed].s : edge[ed].f;
}

void gen(int idx) {
    if (res <= 0) return;
    if (idx == n + 1) {
        res--;
        for (int i = 1; i <= m; i++) printf("%d", ans[i]);
        printf("\n");
        return;
    }
    for (int i : poss[idx]) {
        ans[i] = 1;
        gen(idx + 1);
        ans[i] = 0;
    }
}

int main() {
    boost();

    cin >> n >> m >> k;
    for (int i = 1; i <= n; i++) cnt[i] = 1;
    for (int i = 1; i <= m; i++) {
        cin >> u >> v;
        edge[i] = {u, v};
        g[u].push_back(i);
        g[v].push_back(i);
    }
    queue<pii> q;
    queue<int> prev;
    q.push({0, 1});
    prev.push(0);
    while (q.size()) {
        pii cur = q.front(); q.pop();
        int pre = prev.front(); prev.pop();
        if (vis[cur.s]) {
            if (cur.f == dist[cur.s]) cnt[cur.s]++, poss[cur.s].push_back(pre);
            continue;
        }
        vis[cur.s] = 1;
        dist[cur.s] = cur.f;
        poss[cur.s].push_back(pre);
        for (int ed : g[cur.s]) {
            int nxt = adj(cur.s, ed);
            q.push({cur.f + 1, nxt}), prev.push(ed);
        }
    }
    ll tot = 1;
    for (int i = 1; i <= n; i++) if (tot <= k) tot *= cnt[i];
    res = min((ll) k, tot);
    printf("%lld\n", res);
    gen(1);

    return 0;
}