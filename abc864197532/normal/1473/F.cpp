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
const int mod = 1e9 + 7, abc = 864197532, N = 300000, logN = 18, K = 550;

struct Dinic {
    const int INF = 1 << 30;
    struct Edge {
        int v, id, f;
        Edge(int _v, int _f, int _id) : v(_v), id(_id), f(_f) {}
    };

    vector <vector <Edge>> adj;
    vector <int> level;
    int n, s, t;

    Dinic (int _n, int _s, int _t) : n(_n), s(_s), t(_t) {
        adj.resize(n);
        level.resize(n);
    }

    void add_edge(int u, int v, int f) {
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

   int dfs(int v, int minf) {
        if (v == t) return minf;
        int ans = 0;
        for (Edge &e : adj[v]) {
            if (e.f > 0 and level[e.v] == level[v] + 1) {
                int nxtf = dfs(e.v, min(minf, e.f));
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

    int runFlow() {
        int ans = 0;
        while (bfs()) {
            ans += dfs(s, INF);
        }
        return ans;
    }
};

int main () {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n;
    cin >> n;
    int s = n, t = n + 1;
    Dinic flow(n + 2, s, t);
    vector <int> a(n), c(n), lst(101, -1);
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
        for (int j = 1; j <= 100; ++j) {
            if (a[i] % j == 0 && ~lst[j]) {
                flow.add_edge(i, lst[j], 1 << 30);
            }
        }
        lst[a[i]] = i;
    }
    int C = 0;
    for (int i = 0; i < n; ++i) {
        cin >> c[i];
        if (c[i] < 0) flow.add_edge(i, t, -c[i]);
        else C += c[i], flow.add_edge(s, i, c[i]);
    }
    cout << C - flow.runFlow() << endl;
}