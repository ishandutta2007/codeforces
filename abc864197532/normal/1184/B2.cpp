#include <bits/stdc++.h>
#include <ext/pb_ds/tree_policy.hpp>
#include <ext/pb_ds/assoc_container.hpp>
using namespace std;
#define lli long long int
#define fop(i,m,n) for (int i=(m);i<(n);i++)
#define FOP(i,m,n) for (int i=(m)-1;i>=(n);--i)
#define test(x) cout << #x << ' ' << x << endl;
#define printv(a) {\
    for (auto i : a) cout << i << ' ';\
    cout << '\n';\
}
#define eb emplace_back
#define pb push_back
#define mp make_pair
#define mt make_tuple
#define pii pair<int,int>
#define pdd pair<ld,ld>
typedef long double ld;
#define pll pair<lli,lli>
#define tiii tuple<int,int,int>
#define all(a) a.begin(), a.end()
#define rall(a) a.rbegin(), a.rend()
#define X first
#define Y second
#define oset tree<lli,null_type,less<lli>,rb_tree_tag,tree_order_statistics_node_update>
#define readfile freopen("input.txt", "r", stdin); freopen("output.txt", "w", stdout);
auto SEED = chrono::steady_clock::now().time_since_epoch().count();
mt19937 rng(SEED);
const int mod = 1e9 + 7, x = 864197532, N = 300087, logN = 18, K = 500, C = 1 << 20;

struct enemy {
    int x, a, f;
};

struct our {
    int x, d;
};

template <typename T>
struct Dinic {
    const T INF = 0x3f3f3f3f;
    struct Edge {
        int v, id;
        T f;
        Edge(int _v, T _f, int _id) : v(_v), id(_id), f(_f) {}
    };

    vector <vector <Edge>> adj;
    vector <int> level;
    int n, s, t;

    Dinic (int _n, int _s, int _t) : n(_n), s(_s), t(_t) {
        adj.resize(n);
        level.resize(n);
    }

    void add_edge(int u, int v, T f) {
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

    T dfs(int v, T minf) {
        if (v == t) return minf;
        T ans = 0;
        for (Edge &e : adj[v]) {
            if (e.f > 0 and level[e.v] == level[v] + 1) {
                T nxtf = dfs(e.v, min(minf, e.f));
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

    T runFlow() {
        T ans = 0;
        while (bfs()) {
            ans += dfs(s, INF);
        }
        return ans;
    }
};

int main () {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n, m, u, v;
    cin >> n >> m;
    int dis[n][n];
    fop (i,0,n) fop (j,0,n) dis[i][j] = (i == j ? 0 : 1 << 30);
    fop (i,0,m) {
        cin >> u >> v, u--, v--;
        dis[u][v] = dis[v][u] = 1;
    }
    fop (k,0,n) fop (i,0,n) fop (j,0,n) {
        dis[i][j] = min(dis[i][j], dis[i][k] + dis[k][j]);
    }
    int a, b;
    lli k, h;
    cin >> a >> b >> k >> h;
    vector <enemy> E(a);
    vector <our> O(b);
    fop (i,0,a) {
        cin >> E[i].x >> E[i].a >> E[i].f;
        E[i].x--;
    }
    fop (i,0,b) {
        cin >> O[i].x >> O[i].d;
        O[i].x--;
    }
    Dinic <lli> solver(a + b + 2, 0, 1);
    fop (i,0,a) solver.add_edge(0, i + 2, 1);
    fop (i,0,b) solver.add_edge(a + 2 + i, 1, 1);
    int cnt = 0;
    fop (i,0,a) {
        fop (j,0,b) {
            if (E[i].a >= O[j].d && dis[E[i].x][O[j].x] <= E[i].f) {
                solver.add_edge(i + 2, a + 2 + j, 1);
            }
        }
    }
    int ans = solver.runFlow();
    cout << min(k * ans, h * a) << endl;
}