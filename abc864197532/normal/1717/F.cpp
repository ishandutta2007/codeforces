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
const int mod = 1e9 + 7, N = 100087;

template <typename T>
struct Dinic {
    struct Edge {
        int v, id, rev;
        T f;
        Edge (int _v, T _f, int _id, int _rev) : v(_v), id(_id), f(_f), rev(_rev) {}
    };
    vector <vector <Edge>> adj;
    vector <int> level;
    int n, s, t; T INF;
    Dinic () = default;
    Dinic (int _n, int _s, int _t) : n(_n), s(_s), t(_t), INF(numeric_limits<T>::max()) {
        adj.resize(n);
    }
    void add_edge(int u, int v, T f) {
        adj[u].push_back(Edge(v, f, adj[v].size(), 0));
        adj[v].push_back(Edge(u, 0, adj[u].size() - 1, 1));
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
};

void solve() {
    int n, m;
    cin >> n >> m;
    vector <int> S(n), a(n);
    for (int i = 0; i < n; ++i)
        cin >> S[i];
    for (int i = 0; i < n; ++i)
        cin >> a[i];
    int s = n, t = s + 1, ne = s + 2, pos = 0, neg = 0;
    Dinic <int> flow(n + 3, s, t);
    for (int i = 0, u, v; i < m; ++i) {
        cin >> u >> v, --u, --v;
        flow.add_edge(u, v, 1);
        a[u]++, a[v]--;
    }
    for (int i = 0; i < n; ++i) if (S[i]) {
        if (a[i] & 1) {
            cout << "NO\n";
            return;
        }
        a[i] /= 2;
    }
    for (int i = 0; i < n; ++i) {
        if (!S[i]) {
            flow.add_edge(ne, i, m), flow.add_edge(i, ne, m);
        } else {
            if (a[i] > 0) {
                flow.add_edge(s, i, a[i]);
                pos += a[i];
            }
            if (a[i] < 0) {
                flow.add_edge(i, t, -a[i]);
                neg -= a[i];
            }
        }
    }
    if (pos > neg) {
        flow.add_edge(ne, t, pos - neg);
    }
    if (neg > pos) {
        flow.add_edge(s, ne, neg - pos);
    }
    if (flow.runFlow() != max(pos, neg)) {
        cout << "NO\n";
        return;
    }
    cout << "YES\n";
    for (int i = 0; i < n; ++i) {
        for (auto e : flow.adj[i]) if (e.v < n && !e.rev) {
            if (e.f == 1) {
                cout << i + 1 << ' ' << e.v + 1 << '\n';
            } else {
                cout << e.v + 1 << ' ' << i + 1 << '\n';
            }
        }
    }
}

int main () {
    owo;
    int t = 1;
    // cin >> t;
    while (t--) {
        solve();
    }
}