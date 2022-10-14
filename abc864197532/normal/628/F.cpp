/*
 *   ##   #####   ####      ####  #    #  ####
 *  #  #  #    # #    #    #    # #    # #    #
 * #    # #####  #         #    # #    # #    #
 * ###### #    # #         #    # # ## # #    #
 * #    # #    # #    #    #    # ##  ## #    #
 * #    # #####   ####      ####  #    #  ####
 */
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
#define info() cerr << __PRETTY_FUNCTION__ << ": " << __LINE__ << endl
void abc() {cerr << endl;}
template <typename T, typename ...U> void abc(T a, U ...b) {
    cerr << a << ' ', abc(b...);
}
template <typename T> void printv(T l, T r) {
    while (l != r) cout << *l << " \n"[++l == r];
}
template <typename A, typename B> istream& operator >> (istream& o, pair<A, B> &a) {
    return o >> a.X >> a.Y;
}
template <typename A, typename B> ostream& operator << (ostream& o, pair<A, B> a) {
    return o << '(' << a.X << ", " << a.Y << ')';
}
template <typename T> ostream& operator << (ostream& o, vector<T> a) {
    bool is = false;
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
#define test(args...) info(), abc("[" + string(#args) + "]", args)
#define owo void(0)
#else
#define test(args...) void(0)
#define owo ios::sync_with_stdio(false); cin.tie(0)
#endif
const int mod = 1e9 + 7, N = 2520, logN = 20;

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
    owo;
    int n, m, q;
    cin >> n >> m >> q;
    vector <pii> Q(q);
    for (int i = 0; i < q; ++i) cin >> Q[i], Q[i].X++;
    Q.eb(1, 0);
    Q.eb(m + 1, n);
    sort(all(Q));
    vector <pair <pii, int>> v;
    for (int i = 1; i < Q.size(); ++i) {
        if (Q[i - 1].X != Q[i].X) v.pb(mp(mp(Q[i - 1].X, Q[i].X), Q[i].Y - Q[i - 1].Y));
    }
    int _n = 2 + 5 + m + v.size(), _s = 0, _t = _n - 1;
    Dinic flow(_n, _s, _t);
    for (int i = _n - 2; i >= _n - 6; --i) {
        flow.add_edge(_s, i, n / 5);
    }
    for (int i = 1; i <= m; ++i) flow.add_edge(_n - (i % 5) - 2, i, 1);
    int cur = m + 1, cnt = 0;
    for (auto A : v) {
        for (int i = A.X.X; i < A.X.Y; ++i) flow.add_edge(i, cur, 1);
        if (A.Y < 0) return cout << "unfair\n", 0;
        cnt += A.Y;
        flow.add_edge(cur, _t, A.Y);
        cur++;
    }
    if (cnt != n) return cout << "unfair\n", 0;
    if (flow.runFlow() == n) cout << "fair\n";
    else cout << "unfair\n";
}