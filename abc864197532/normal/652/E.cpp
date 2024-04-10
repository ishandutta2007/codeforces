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
const int mod = 998244353, N = 300005, logN = 20, M = 6e6;

vector <int> adj[N];
vector <pii> newadj[N];
int E[N], W[N];

struct EdgeBCC {
    // 0-indexed
    vector <int> low, dep, idx, stk, stkE, par, parE;
    vector <bool> bridge, dp; // edge i -> pa[i] is bridge ?
    int n, nbcc;
    EdgeBCC () = default;
    EdgeBCC (int _n) : n(_n), nbcc(0) {
        low.assign(n, -1), dep.assign(n, -1), idx.assign(n, -1);
        par.assign(n, -1), bridge.assign(n, false), parE.assign(n, -1);
        for (int i = 0; i < n; ++i) if (dep[i] == -1) {
            dfs(i, -1);
        }
        for (int i = 1; i < n; ++i) if (bridge[i]) {
            newadj[idx[i]].eb(idx[par[i]], W[parE[i]]);
            newadj[idx[par[i]]].eb(idx[i], W[parE[i]]);
        }
    }
    void dfs(int v, int pa) {
        low[v] = dep[v] = ~pa ? dep[pa] + 1 : 0;
        par[v] = pa;
        stk.push_back(v);
        for (int id : adj[v]) {
            int u = E[id] ^ v;
            if (u == pa)
                continue;
            stkE.pb(id);
            if (dep[u] == -1) {
                parE[u] = id;
                dfs(u, v);
                low[v] = min(low[v], low[u]);
            } else {
                low[v] = min(low[v], low[u]);
            }
        }
        if (low[v] == dep[v]) {
            bridge[v] = true;
            int x;
            do {
                x = stk.back(), stk.pop_back();
                idx[x] = nbcc;
            } while (x != v);
            dp.pb(false);
            while (!stkE.empty() && stkE.back() != parE[v]) {
                x = stkE.back(), stkE.pop_back();
                if (W[x])
                    dp.back() = true;
            }
            if (!stkE.empty())
                stkE.pop_back();
            nbcc++;
        }
    }
};

int main () {
    owo;
    int n, m;
    cin >> n >> m;
    for (int i = 0, u, v; i < m; ++i) {
        cin >> u >> v >> W[i], --u, --v;
        E[i] = u ^ v;
        adj[u].pb(i), adj[v].pb(i);
    }
    EdgeBCC solver(n);
    int s, t;
    cin >> s >> t, --s, --t;
    s = solver.idx[s], t = solver.idx[t];
    vector <int> dis(n, -1);
    queue <int> q; q.push(s), dis[s] = 0;
    while (!q.empty()) {
        int v = q.front(); q.pop();
        dis[v] |= solver.dp[v];
        for (auto [u, w] : newadj[v]) if (dis[u] == -1) {
            dis[u] = dis[v] | w, q.push(u);
        }
    }
    cout << (dis[t] == 1 ? "YES\n" : "NO\n");
}