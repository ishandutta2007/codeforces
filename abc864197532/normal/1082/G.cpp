#include <bits/stdc++.h>
using namespace std;
#define lli long long int
#define mp make_pair
#define pb push_back
#define eb emplace_back
#define test(x) cout << "Line(" << __LINE__ << ") " #x << ' ' << x << endl
#define printv(x) {\
	for (auto i : x) cout << i << ' ';\
	cout << endl;\
}
#define pii pair <int, int>
#define pll pair <lli, lli>
#define X first
#define Y second
#define all(x) x.begin(), x.end()
#define rall(x) x.rbegin(), x.rend()
template<typename A, typename B>
ostream& operator << (ostream& o, pair<A, B> a){
    return o << a.X << ' ' << a.Y;
}
template<typename A, typename B>
istream& operator >> (istream& o, pair<A, B> &a){
    return o >> a.X >> a.Y;
}
const int mod = 1e9 + 7, abc = 864197532, N = 200000, K = 500;


struct Dinic {
    const long long INF = 1ll << 60;
    struct Edge {
        int v, id;
        long long f;
        Edge(int _v, long long _f, int _id) : v(_v), id(_id), f(_f) {}
    };

    vector <vector <Edge>> adj;
    vector <int> level;
    int n, s, t;

    Dinic (int _n, int _s, int _t) : n(_n), s(_s), t(_t) {
        adj.resize(n);
        level.resize(n);
    }

    void add_edge(int u, int v, long long f) {
        adj[u].push_back(Edge(v, f, adj[v].size()));
        adj[v].push_back(Edge(u, 0, adj[u].size() - 1));
    }

    bool bfs() {
        for (int i = 0; i < n; ++i) level[i] = -1;
        queue <int> q;
        q.push(s);
        level[s] = 0;
        while (q.size()) {
            int v = q.front(); q.pop();
            for (Edge e : adj[v]) {
                if (e.f > 0 and level[e.v] == -1) {
                    level[e.v] = level[v] + 1;
                    q.push(e.v);
                }
            }
        }
        return level[t] != -1;
    }

    long long dfs(int v, long long minf) {
        if (v == t) return minf;
        long long ans = 0;
        for (Edge &e : adj[v]) {
            if (e.f > 0 and level[e.v] == level[v] + 1) {
                long long nxtf = dfs(e.v, min(minf, e.f));
                ans += nxtf;
                minf -= nxtf;
                e.f -= nxtf;
                adj[e.v][e.id].f += nxtf;
                if (minf == 0) return ans;
            }
        }
        if (!ans) level[v] = -1;
        return ans;
    }

    long long runFlow() {
        long long ans = 0;
        while (bfs()) {
            ans += dfs(s, INF);
        }
        return ans;
    }
};

int main () {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n, m;
    cin >> n >> m;
    int s = n + m, t = n + m + 1;
    Dinic flow(n + m + 2, s, t);
    lli all_edge_w = 0;
    for (int i = 0, x; i < n; ++i) cin >> x, flow.add_edge(i + m, t, x);
    for (int i = 0, u, v, w; i < m; ++i) {
        cin >> u >> v >> w, --u, --v;
        all_edge_w += w;
        flow.add_edge(s, i, w);
        flow.add_edge(i, u + m, 1ll << 60);
        flow.add_edge(i, v + m, 1ll << 60);
    }
    cout << all_edge_w - flow.runFlow() << endl;
}