#include <cstdio>
#include <map>
#include <queue>

#define int long long

using std::map;
using std::priority_queue;
using std::pair;

const int N = 3e2, INF = 0x7f7f7f7f7f7f7f7f;

int n, c[N + 10], l[N + 10];

map<int, bool> vis;
map<int, int> dis;
priority_queue<pair<int, int> > q;

int gcd(int a, int b) { return b ? gcd(b, a % b) : a; }

void Dijkstra() {
    q.push(std::make_pair(dis[0] = 0, 0));
    while (q.size()) {
        int u = q.top().second;
        q.pop();
        if (u == 1) break;
        if (vis.count(u)) continue;
        vis[u] = 1;
        for (int i = 1; i <= n; i++) {
            int v = gcd(u, l[i]);
            if (dis.count(v) == 0) dis[v] = INF;
            if (dis[v] > dis[u] + c[i]) q.push(std::make_pair(-(dis[v] = dis[u] + c[i]), v));
        }
    }
}

signed main() {
    scanf("%lld", &n);
    for (int i = 1; i <= n; i++) scanf("%lld", l + i);
    for (int i = 1; i <= n; i++) scanf("%lld", c + i);
    Dijkstra();
    if (dis.count(1) == 0) return puts("-1"), 0;
    return printf("%lld\n", dis[1]), 0;
}