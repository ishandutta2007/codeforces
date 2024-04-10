#include <bits/stdc++.h>
using namespace std;
#define ll long long int
#define mp make_pair
#define pb push_back
#define eb emplace_back
#define pii pair <int, int>
#define X first
#define Y second
#define all(x) x.begin(), x.end()
#define rall(x) x.rbegin(), x.rend()
void abc() {cout << endl;}
template <typename T, typename ...U> void abc(T a, U ...b) {
    cout << a << ' ', abc(b...);
}
template <typename T> void printv(T l, T r) {
    for (; l != r; ++l) cout << *l << " \n"[l + 1 == r];
}
template <typename A, typename B> istream& operator >> (istream& o, pair<A, B> &a) {
    return o >> a.X >> a.Y;
}
template <typename A, typename B> ostream& operator << (ostream& o, pair<A, B> a) {
    return o << '(' << a.X << ", " << a.Y << ')';
}
template <typename T> ostream& operator << (ostream& o, vector<T> a) {
    bool is = false;
    if (a.empty()) return o << "{}";
    for (T i : a) {o << (is ? ' ' : '{'), is = true, o << i;}
    return o << '}';
}
template <typename T> struct vv : vector <vector <T>> {
    vv (int n, int m, T v) : vector <vector <T>> (n, vector <T>(m, v)) {}
    vv (int n, int m) : vector <vector <T>> (n, vector <T>(m)) {}
    vv () {}
};
template <typename T> struct vvv : vector <vv <T>> {
    vvv (int n, int m, int k, T v) : vector <vv <T>> (n, vv <T>(m, k, v)) {}
    vvv (int n, int m, int k) : vector <vv <T>> (n, vv <T>(m, k)) {}
    vvv () {}
};
#ifdef Doludu
#define test(args...) abc("[" + string(#args) + "]", args)
#define owo freopen("input.txt", "r", stdin), freopen("output.txt", "w", stdout)
#else
#define test(args...) void(0)
#define owo ios::sync_with_stdio(false); cin.tie(0)
#endif
const int mod = 1e9 + 7, N = 501, C = 1e7 + 5;

struct Dinic {
    const int INF = 1 << 30;
    struct edge {
        int v, f;
        edge (int _v, int _f) : v(_v), f(_f) {}
    };
    vector <vector <int>> adj;
    vector <edge> E;
    vector <int> level;
    int n;
    Dinic (int _n) : n(_n) {adj.resize(n);}
    void add_edge(int u, int v, int f) {
        adj[u].pb(E.size()), E.pb(edge(v, f));
        adj[v].pb(E.size()), E.pb(edge(u, 0));
    }
    bool bfs(int s, int t) {
        level.assign(n, -1);
        queue <int> q;
        level[s] = 0, q.push(s);
        while (!q.empty()) {
            int v = q.front(); q.pop();
            for (int id : adj[v]) if (E[id].f > 0 && level[E[id].v] == -1) {
                level[E[id].v] = level[v] + 1;
                q.push(E[id].v);
            }
        }
        return level[t] != -1;
    }
    int dfs(int v, int minf, int t) {
        if (v == t) return minf;
        int ans = 0;
        for (int id : adj[v]) if (E[id].f > 0 && level[E[id].v] == level[v] + 1) {
            int nxtf = dfs(E[id].v, min(minf, E[id].f), t);
            minf -= nxtf, E[id].f -= nxtf;
            ans += nxtf, E[id ^ 1].f += nxtf;
            if (!minf) return ans;
        }
        if (!ans) level[v] = -1;
        return ans;
    }
    int solve(int s, int t) {
        int ans = 0;
        while (bfs(s, t)) ans += dfs(s, INF, t);
        return ans;
    }
    vector <bool> vis;
    void runbfs(int s) {
        vis.assign(n, false);
        queue <int> q;
        vis[s] = true, q.push(s);
        while (!q.empty()) {
            int v = q.front(); q.pop();
            for (int id : adj[v]) if (E[id].f > 0 && !vis[E[id].v]) {
                vis[E[id].v] = true, q.push(E[id].v);
            }
        }
    }
    vector <edge> ordE;
    void record() {
        ordE = E;
    }
    void reset() {
        E = ordE;
    }
};

vector <array <int, 3>> GomoryHu(vector <vector <pii>> adj, int n) { // 0-based
    Dinic flow(n);
    for (int i = 0; i < n; ++i) for (auto [j, w] : adj[i])
        flow.add_edge(i, j, w);
    flow.record();
    vector <array <int, 3>> ans;
    vector <int> rt(n);
    for (int i = 0; i < n; ++i) rt[i] = 0;
    for (int i = 1; i < n; ++i) {
        int t = rt[i];
        flow.reset(); // clear flows on all edge
        ans.push_back({i, t, flow.solve(i, t)});
        flow.runbfs(i);
        for (int j = i + 1; j < n; ++j) if (rt[j] == t && flow.vis[j]) {
            rt[j] = i;
        }
    }
    return ans;
}

void solve() {
    int n, m;
    cin >> n >> m;
    vector <vector <pii>> adj(n);
    for (int i = 0, u, v, w; i < m; ++i) {
        cin >> u >> v >> w, --u, --v;
        adj[u].eb(v, w), adj[v].eb(u, w);
    }
    auto edge = GomoryHu(adj, n);
    vector <vector <int>> g(n);
    vector <bool> vis;
    function <void(int, int)> dfs = [&](int v, int pa) {
        vis[v] = true;
        for (int u : g[v]) if (u != pa) {
            dfs(u, v);
        }
    };
    vector <int> order;
    function <void(vector <int>)> solve = [&](vector <int> cc) {
        if (cc.size() == 1) {
            order.pb(cc[0]);
            return;
        }
        int id = -1;
        vector <bool> in(n, false);
        for (int i : cc)
            in[i] = true;
        for (int i = 0; i < n - 1; ++i) if (in[edge[i][0]] && in[edge[i][1]] && (id == -1 || edge[id][2] > edge[i][2])) {
            id = i;
        }
        vis.assign(n, false);
        dfs(edge[id][0], edge[id][1]);
        vector <int> L, R;
        for (int i = 0; i < n; ++i) if (in[i]) {
            if (vis[i])
                L.pb(i);
            else
                R.pb(i);
        }
        solve(L), solve(R);
    };
    int ans = 0;
    for (int i = 0; i < n - 1; ++i) {
        ans += edge[i][2];
        g[edge[i][0]].pb(edge[i][1]), g[edge[i][1]].pb(edge[i][0]);
    }
    cout << ans << '\n';
    vector <int> pt(n); iota(all(pt), 0);
    solve(pt);
    for (int &i : order)
        i++;
    printv(all(order));
}

int main() {
    owo;
    int t = 1;
    // cin >> t;
    while (t--) {
        solve();
    }
}