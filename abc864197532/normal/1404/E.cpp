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
const int mod = 1e9 + 7, N = 1 << 20, K = 250;

struct Dinic {
    const int INF = 1 << 30;
    struct edge {
        int v, f;
        edge (int _v, int _f) : v(_v), f(_f) {}
    };
    vector <vector <int>> adj;
    vector <edge> E;
    vector <int> level;
    int n, s, t;
    Dinic (int _n, int _s, int _t) : n(_n), s(_s), t(_t) {adj.resize(n);}
    void add_edge(int u, int v, int f) {
        adj[u].pb(E.size()), E.pb(edge(v, f));
        adj[v].pb(E.size()), E.pb(edge(u, 0));
    }
    bool bfs() {
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
    int dfs(int v, int minf) {
        if (v == t) return minf;
        int ans = 0;
        for (int id : adj[v]) if (E[id].f > 0 && level[E[id].v] == level[v] + 1) {
            int nxtf = dfs(E[id].v, min(minf, E[id].f));
            minf -= nxtf, E[id].f -= nxtf;
            ans += nxtf, E[id ^ 1].f += nxtf;
            if (!minf) return ans;
        }
        if (!ans) level[v] = -1;
        return ans;
    }
    int runFlow() {
        int ans = 0;
        while (bfs()) ans += dfs(s, INF);
        return ans;
    }
};

void solve() {
    int n, m;
    cin >> n >> m;
    vector <string> s(n);
    int cnt = 0;
    for (int i = 0; i < n; ++i)
        cin >> s[i], cnt += count(all(s[i]), '#');
    int L = (n - 1) * m, R = n * (m - 1), S = L + R, T = S + 1;
    Dinic flow(L + R + 2, S, T);
    for (int i = 0; i < n; ++i) for (int j = 0; j < m; ++j) if (s[i][j] == '#') {
        for (int dx : {-1, 1}) for (int dy : {-1, 1}) {
            if (0 <= i + dx && i + dx < n && 0 <= j + dy && j + dy < m && s[i + dx][j] == '#' && s[i][j + dy] == '#') {
                // (i, j) -> (i + dx, j)
                // (i, j) -> (i, j + dy)
                flow.add_edge(min(i, i + dx) * m + j, L + i * (m - 1) + min(j, j + dy), 1);
            }
        }
    }
    int sum = 0;
    for (int i = 0; i + 1 < n; ++i) for (int j = 0; j < m; ++j) {
        sum += s[i][j] == '#' && s[i + 1][j] == '#';
    }
    for (int i = 0; i < n; ++i) for (int j = 0; j + 1 < m; ++j) {
        sum += s[i][j] == '#' && s[i][j + 1] == '#';
    }
    for (int i = 0; i < L; ++i)
        flow.add_edge(S, i, 1);
    for (int i = L; i < L + R; ++i)
        flow.add_edge(i, T, 1);
    cout << cnt - (sum - flow.runFlow()) << '\n';
}

int main() {
    owo;
    int t = 1;
    // cin >> t;
    while (t--) {
        solve();
    }
}