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

struct edge {
    int u, v, w, i;
};

const int MN = 100005;

int n, m, u, v, w, use[MN], vis[MN], dist[MN], val[MN], bck[MN];
vector<edge> a[MN];
edge ed[MN];

int op(int id, int cur) {
    return ed[id].u == cur ? ed[id].v : ed[id].u;
}

int main() {
    boost();

    cin >> n >> m;
    for (int i = 1; i <= m; i++) {
        cin >> u >> v >> w;
        w ^= 1;
        a[u].push_back({0, v, w, i});
        a[v].push_back({0, u, w, i});
        ed[i] = {u, v, w, i};
    }
    memset(val, 0x3f, sizeof(val));
    queue<int> q;
    q.push(1);
    dist[1] = val[1] = 0;
    vis[1] = 1;
    while (q.size()) {
        int cur = q.front(); q.pop();
        for (edge nxt : a[cur]) {
            if (vis[nxt.v]) {
                if (dist[nxt.v] == dist[cur] + 1 && val[nxt.v] > val[cur] + nxt.w) {
                    val[nxt.v] = val[cur] + nxt.w;
                    bck[nxt.v] = nxt.i;
                }
            } else {
                vis[nxt.v] = 1;
                val[nxt.v] = min(val[nxt.v], val[cur] + nxt.w);
                dist[nxt.v] = dist[cur] + 1;
                bck[nxt.v] = nxt.i;
                q.push(nxt.v);
            }
        }
    }
    int cur = n;
    while (cur > 1) {
        use[bck[cur]] = 1;
        cur = op(bck[cur], cur);
    }
    int cnt = 0;
    for (int i = 1; i <= m; i++) if (use[i] == ed[i].w) cnt++;
    printf("%d\n", cnt);
    for (int i = 1; i <= m; i++) if (use[i] == ed[i].w) printf("%d %d %d\n", ed[i].u, ed[i].v, ed[i].w);

    return 0;
}