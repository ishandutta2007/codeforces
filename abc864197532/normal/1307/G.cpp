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

struct MCMF {
    const int INF = 1 << 30;
    struct edge {
        int v, f, c;
        edge (int _v, int _f, int _c) : v(_v), f(_f), c(_c) {}
    };
    vector <edge> E;
    vector <vector <int>> adj;
    vector <int> dis, pot, rt;
    int n, s, t;
    MCMF (int _n, int _s, int _t) : n(_n), s(_s), t(_t) {
        adj.resize(n);
    }
    void add_edge(int u, int v, int f, int c) {
        adj[u].pb(E.size()), E.pb(edge(v, f, c));
        adj[v].pb(E.size()), E.pb(edge(u, 0, -c));
    }
    bool SPFA() {
        rt.assign(n, -1), dis.assign(n, INF);
        vector <bool> vis(n, false);
        queue <int> q;
        q.push(s), dis[s] = 0, vis[s] = true;
        while (!q.empty()) {
            int v = q.front(); q.pop();
            vis[v] = false;
            for (int id : adj[v]) if (E[id].f > 0 && dis[E[id].v] > dis[v] + E[id].c + pot[v] - pot[E[id].v]) {
                dis[E[id].v] = dis[v] + E[id].c + pot[v] - pot[E[id].v], rt[E[id].v] = id;
                if (!vis[E[id].v]) vis[E[id].v] = true, q.push(E[id].v);
            }
        }
        return dis[t] != INF;
    }
    bool dijkstra() {
        rt.assign(n, -1), dis.assign(n, INF);
        priority_queue <pair <int, int>, vector <pair <int, int>>, greater <pair <int, int>>> pq;
        dis[s] = 0, pq.emplace(dis[s], s);
        while (!pq.empty()) {
            int d, v; tie(d, v) = pq.top(); pq.pop();
            if (dis[v] < d) continue;
            for (int id : adj[v]) if (E[id].f > 0 && dis[E[id].v] > dis[v] + E[id].c + pot[v] - pot[E[id].v]) {
                dis[E[id].v] = dis[v] + E[id].c + pot[v] - pot[E[id].v], rt[E[id].v] = id;
                pq.emplace(dis[E[id].v], E[id].v);
            }
        }
        return dis[t] != INF;
    }
    vector <pii> runFlow() {
        pot.assign(n, 0);
        int cost = 0, flow = 0;
        vector <pii> res;
        bool fr = true;
        while ((fr ? SPFA() : dijkstra())) {
            for (int i = 0; i < n; i++) {
                dis[i] += pot[i] - pot[s];
            }
            int add = INF;
            for (int i = t; i != s; i = E[rt[i] ^ 1].v) {
                add = min(add, E[rt[i]].f);
            }
            for (int i = t; i != s; i = E[rt[i] ^ 1].v) {
                E[rt[i]].f -= add, E[rt[i] ^ 1].f += add;
            }
            flow += add, cost += add * dis[t];
            res.eb(flow, cost);
            fr = false;
            swap(dis, pot);
        }
        return res;
    }
};

void solve() {
    int n, m, q;
    cin >> n >> m;
    MCMF flow(n, 0, n - 1);
    for (int i = 0, u, v, w; i < m; ++i) {
        cin >> u >> v >> w, --u, --v;
        flow.add_edge(u, v, 1, w);
    }
    vector <pii> res = flow.runFlow();
    cin >> q;
    while (q--) {
        int x; cin >> x;
        double ans = 1 << 30;
        for (auto [flow, cost] : res) {
            ans = min(ans, (x + cost) * 1.0 / flow);
        }
        cout << fixed << setprecision(10) << ans << '\n';
    }
}

int main() {
    owo;
    int t = 1;
    // cin >> t;
    while (t--) {
        solve();
    }
}