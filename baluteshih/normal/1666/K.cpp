#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
#define X first
#define Y second
#define SZ(a) ((int)a.size())
#define ALL(v) v.begin(), v.end()
#define pb push_back

const int MAXN = 2050;
const ll INF = 2e18; 
struct MaxFlow { // 0-base
    struct edge {
        int to;
        ll cap, flow;
        int rev;
    };
    vector<edge> G[MAXN];
    int s, t, dis[MAXN], cur[MAXN], n;
    int dfs(int u, ll cap) {
        if (u == t || !cap) return cap;
        for (int &i = cur[u]; i < (int)G[u].size(); ++i) {
            edge &e = G[u][i];
            if (dis[e.to] == dis[u] + 1 && e.flow != e.cap) {
                ll df = dfs(e.to, min(e.cap - e.flow, cap));
                if (df) {
                    e.flow += df;
                    G[e.to][e.rev].flow -= df;
                    return df;
                }
            }
        }
        dis[u] = -1;
        return 0;
    }
    bool bfs() {
        fill_n(dis, n, -1);
        queue<int> q;
        q.push(s), dis[s] = 0;
        while (!q.empty()) {
            int tmp = q.front();
            q.pop();
            for (auto &u : G[tmp])
                if (!~dis[u.to] && u.flow != u.cap) {
                    q.push(u.to);
                    dis[u.to] = dis[tmp] + 1;
                }
        }
        return dis[t] != -1;
    }
    ll maxflow(int _s, int _t) {
        s = _s, t = _t;
        ll flow = 0, df;
        while (bfs()) {
            fill_n(cur, n, 0);
            while ((df = dfs(s, INF))) flow += df;
        }
        return flow;
    }
    void init(int _n) {
        n = _n;
        for (int i = 0; i < n; ++i) G[i].clear();
    }
    void reset() {
        for (int i = 0; i < n; ++i)
            for (auto &j : G[i]) j.flow = 0;
    }
    void add_edge(int u, int v, ll cap) {
        G[u].pb(edge{v, cap, 0LL, (int)G[v].size()});
        G[v].pb(edge{u, 0LL, 0LL, (int)G[u].size() - 1});
    }
} dinic;

int ans[1005];
char chr[4] = {'C', 'A', 'B', 'C'};

int main() {
    ios::sync_with_stdio(0), cin.tie(0);
    int n, m, a, b;
    cin >> n >> m >> a >> b, --a, --b;
    dinic.init(2 * n);
    dinic.add_edge(a << 1, b << 1 | 1, INF);
    dinic.add_edge(a << 1 | 1, b << 1, INF);
    while (m--) {
        int u, v, w;
        cin >> u >> v >> w;
        --u, --v;
        dinic.add_edge(u << 1, v << 1 | 1, w);
        dinic.add_edge(u << 1 | 1, v << 1, w);
        dinic.add_edge(v << 1, u << 1 | 1, w);
        dinic.add_edge(v << 1 | 1, u << 1, w);
    }
    cout << dinic.maxflow(a << 1, b << 1) << "\n";
    for (int i = 0; i < 2 * n; ++i)
        if (~dinic.dis[i])
            ans[i >> 1] |= (i & 1) + 1;
    for (int i = 0; i < n; ++i)
        cout << chr[ans[i]];
    cout << "\n";
}