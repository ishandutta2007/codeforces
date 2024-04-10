#pragma GCC optimize("O3")
#pragma GCC target("sse4")

#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>

using namespace std;
using namespace __gnu_pbds;

typedef tree<int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update> ordered_set;

#define ll long long
#define int ll
#define ld long double
#define pii pair<int, int>
#define f first
#define s second
#define readl(_s) getline(cin, (_s));
#define boost() cin.tie(0); cin.sync_with_stdio(0)

struct node {
    int node, cnt, price;
};

bool cmp(node x, node y) {
    return x.price < y.price;
}

const int MN = 5005;

int n, m, q, w, u, v, x, dist[MN][MN];
vector<int> a[MN];
vector<node> s;

int check(int t, int st, int req) {
    int cnt = 0, cost = 0;
    for (node p : s) {
        if (dist[st][p.node] > t) continue;
        if (req - cnt <= p.cnt) return cost + p.price * (req - cnt);
        cnt += p.cnt;
        cost += p.price * p.cnt;
    }
    return 1LL << 60;
}

void bfs(int st) {
    queue<int> q;
    q.push(st);
    dist[st][st] = 0;
    while (q.size()) {
        int cur = q.front(); q.pop();
        for (int nxt : a[cur]) if (dist[st][nxt] > dist[st][cur] + 1) dist[st][nxt] = dist[st][cur] + 1, q.push(nxt);
    }
}

int32_t main() {
    boost();

    memset(dist, 0x3f, sizeof(dist));
    cin >> n >> m;
    for (int i = 1; i <= m; i++) {
        cin >> u >> v;
        a[u].push_back(v);
        a[v].push_back(u);
    }
    for (int i = 1; i <= n; i++) bfs(i);
    cin >> w;
    for (int i = 1; i <= w; i++) {
        cin >> x >> u >> v;
        s.push_back({x, u, v});
    }
    sort(s.begin(), s.end(), cmp);
    cin >> q;
    while (q--) {
        cin >> x >> u >> v;
        int lo = 0, hi = MN, mid;
        while (lo < hi) { //NlogN
            mid = (lo + hi) >> 1;
            if (check(mid, x, u) <= v) hi = mid;
            else lo = mid + 1;
        }
        if (lo == MN) printf("-1\n");
        else printf("%lld\n", lo);
    }

    return 0;
}