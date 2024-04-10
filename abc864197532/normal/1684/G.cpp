#include <bits/stdc++.h>
using namespace std;
#define lli long long int
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
    vv(int n, int m, T v) : vector <vector <T>> (n, vector <T>(m, v)) {}
    vv() {}
};
template <typename T> struct vvv : vector <vv <T>> {
    vvv(int n, int m, int k, T v) : vector <vv <T>> (n, vv <T>(m, k, v)) {}
    vvv() {}
};
#ifdef Doludu
#define test(args...) abc("[" + string(#args) + "]", args)
#define owo freopen("input.txt", "r", stdin), freopen("output.txt", "w", stdout); 
#else
#define test(args...) void(0)
#define owo ios::sync_with_stdio(false); cin.tie(0)
#endif
const int mod = 1e9 + 7, N = 100000, logN = 20, K = 48763;

template <typename T>
struct Dinic {
    struct Edge {
        int v, id;
        T f;
        Edge (int _v, T _f, int _id) : v(_v), id(_id), f(_f) {}
    };
    vector <vector <Edge>> adj;
    vector <int> level;
    int n, s, t; T INF;
    Dinic () = default;
    Dinic (int _n, int _s, int _t) : n(_n), s(_s), t(_t), INF(numeric_limits<T>::max()) {
        adj.resize(n);
    }
    void add_edge(int u, int v, T f) {
        adj[u].push_back(Edge(v, f, adj[v].size()));
        adj[v].push_back(Edge(u, 0, adj[u].size() - 1));
    }
    bool bfs() {
        level.assign(n, -1);
        queue <int> q;
        q.push(s), level[s] = 0;
        while (!q.empty()) {
            int v = q.front(); q.pop();
            for (Edge e : adj[v]) {
                if (e.f > 0 && level[e.v] == -1) {
                    level[e.v] = level[v] + 1;
                    q.push(e.v);
                }
            }
        }
        return level[t] != -1;
    }
    T dfs(int v, T minf) {
        if (v == t) 
            return minf;
        T ans = 0;
        for (Edge &e : adj[v]) {
            if (e.f > 0 && level[e.v] == level[v] + 1) {
                T nxtf = dfs(e.v, min(minf, e.f));
                ans += nxtf, minf -= nxtf, e.f -= nxtf, adj[e.v][e.id].f += nxtf;
                if (minf == 0) 
                    return ans;
            }
        }
        if (!ans) 
            level[v] = -1;
        return ans;
    }
    T runFlow() {
        T ans = 0;
        while (bfs()) {
            ans += dfs(s, INF);
        }
        return ans;
    }
    vector <bool> vis;
    void runBfs() {
        vis.assign(n, false);
        queue <int> q;
        q.push(s), vis[s] = true;
        while (!q.empty()) {
            int v = q.front(); q.pop();
            for (Edge &e : adj[v]) if (e.f > 0 && !vis[e.v]) {
                q.push(e.v), vis[e.v] = true;
            }
        }
    }
    /* Bipartite Matching Restore Answer
       runBfs();
       {!vis[x] | x \in L} U {vis[x] | x \in R} 

       Min Cut Restore Answer
       runBfs();
       {vis[x] | x \in V} */
};

int main () {
    owo;
    int n, m;
    cin >> n >> m;
    int s = n, t = n + 1;
    Dinic <int> flow(n + 2, s, t);
    vector <int> a(n);
    int cnt = 0;
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
        if (a[i] <= m / 3)
            flow.add_edge(s, i, 1);
        else
            flow.add_edge(i, t, 1), cnt++;
    }
    for (int i = 0; i < n; ++i) if (a[i] <= m / 3) {
        for (int j = 0; j < n; ++j) if (a[j] > m / 3 && a[j] % a[i] == 0 && a[j] + a[j] <= m - a[i]) {
            flow.add_edge(i, j, 1);
        }
    }
    if (flow.runFlow() != cnt) 
        return cout << -1 << '\n', 0;
    vector <pii> ans;
    for (int i = 0; i < n; ++i) if (a[i] <= m / 3) {
        ans.eb(a[i], -1);
        for (auto e : flow.adj[i]) if (e.v < n && a[e.v] > m / 3 && !e.f) {
            ans.pop_back(), ans.eb(a[i], a[e.v]);
            break;
        }
    }
    cout << ans.size() << '\n';
    for (auto [x, y] : ans) {
        if (y == -1)
            cout << x + x << ' ' << x + x + x << '\n';
        else 
            cout << x + y + y << ' ' << x + y << '\n';
    }
}