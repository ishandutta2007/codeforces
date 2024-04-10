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

struct edge {
    int u, v, ord;
};

struct Dsu {
    vector <int> rt, sz;
    int n, cc;
    Dsu () = default;
    Dsu (int _n) : n(_n), cc(_n) {
        rt.resize(n), iota(rt.begin(), rt.end(), 0);
        sz.assign(n, 1);
    }
    int Find(int v) {
        return rt[v] == v ? v : rt[v] = Find(rt[v]);
    }
    bool Union(int v, int u) {
        u = Find(u), v = Find(v);
        if (u == v)
            return false;
        if (sz[u] > sz[v])
            swap(u, v);
        rt[u] = v;
        sz[v] += sz[u];
        cc--;
        return true;
    }
    bool same(int u, int v) {
        return Find(u) == Find(v);
    }
};

/* Matroid Condition:
S' \subsetin S \in I, S' \in I
S1, S2 \in I, |S1| < |S2|, then exist e \in S2 \ S1 such that S1 U {e} \in I */
struct GraphMatroid {
    vector <edge> E;
    vector <vector <int>> g;
    vector <int> comp;
    int n, m;
    GraphMatroid (int _n, vector <edge> _E) : n(_n), E(_E), m(E.size()) {}
    void dfs(int v, int pa, int id) {
        comp[v] = id;
        for (int u : g[v]) if (u != pa)
            dfs(u, v, id);
    }
    vector <bool> build_X(vector <bool> &I) {
        g.assign(n, vector <int>());
        for (int i = 0; i < m; ++i) if (I[i]) {
            g[E[i].u].push_back(E[i].v);
            g[E[i].v].push_back(E[i].u);
        }
        comp.assign(n, -1);
        int id = 0;
        for (int i = 0; i < n; ++i) if (comp[i] == -1)
            dfs(i, -1, id), id++;
        vector <bool> X(m, false);
        for (int i = 0; i < m; ++i) if (!I[i] && comp[E[i].u] != comp[E[i].v])
            X[i] = true;
        return X;
    }
    void build_exchange_graph(vector <vector <int>> &adj, vector <bool> &I) {
        for (int i = 0; i < m; ++i) if (I[i]) {
            g.assign(n, vector <int>());
            for (int j = 0; j < m; ++j) if (I[j] && i != j) {
                g[E[j].u].push_back(E[j].v);
                g[E[j].v].push_back(E[j].u);
            }
            comp.assign(n, -1);
            int id = 0;
            for (int j = 0; j < n; ++j) if (comp[j] == -1)
                dfs(j, -1, id), id++;
            for (int j = 0; j < m; ++j) if (!I[j] && comp[E[j].u] != comp[E[j].v]) {
                adj[i].push_back(j);
            }
        }
    }
};

struct DegreeMatroid {
    vector <edge> E;
    vector <int> deg_limit;
    int n, m;
    DegreeMatroid (int _n, vector <edge> _E, vector <int> _d) : n(_n), E(_E), m(E.size()), deg_limit(_d) {}
    vector <bool> build_X(vector <bool> &I) {
        vector <int> cnt(n, 0);
        for (int i = 0; i < m; ++i) if (I[i])
            cnt[E[i].ord]++;
        vector <bool> X(m, false);
        for (int i = 0; i < m; ++i) if (!I[i] && cnt[E[i].ord] < deg_limit[E[i].ord])
            X[i] = true;
        return X;
    }
    void build_exchange_graph(vector <vector <int>> &adj, vector <bool> &I) {
        vector <int> cnt(n, 0);
        for (int i = 0; i < m; ++i) if (I[i])
            cnt[E[i].ord]++;
        for (int i = 0; i < m; ++i) if (I[i]) {
            cnt[E[i].ord]--;
            for (int j = 0; j < m; ++j) if (!I[j] && cnt[E[j].ord] < deg_limit[E[j].ord]) {
                adj[j].push_back(i);
            }
            cnt[E[i].ord]++;
        }
    }
};

template <typename M1, typename M2>
struct MatroidIntersection {
    M1 m1;
    M2 m2;
    MatroidIntersection (M1 _m1, M2 _m2) : m1(_m1), m2(_m2) {}
    /* 1. build X1, X2
       2. If e \in X1 and e \in X2, add e
       3. Else build exchange graph
          m1 -> add edge from I to E \ I
          m2 -> add edge from E \ I to I
          weight: I -> w, E \ I -> -w
       4. find a minimum path (weight, number) from X1 to X2 (use bfs or SPFA) */
    vector <vector <int>> adj;
    vector <int> bfs(vector <bool> &X1, vector <bool> &X2) {
        int n = X1.size();
        queue <int> q;
        vector <int> dis(n, -1), rt(n, -1);
        for (int i = 0; i < n; ++i) if (X1[i])
            q.push(i), dis[i] = 0;
        while (!q.empty()) {
            int v = q.front(); q.pop();
            for (int u : adj[v]) if (dis[u] == -1) {
                dis[u] = dis[v] + 1, rt[u] = v;
                q.push(u);
            }
        }
        pair <int, int> mn = make_pair(1 << 30, -1);
        for (int i = 0; i < n; ++i) if (X2[i] && dis[i] != -1)
            mn = min(mn, make_pair(dis[i], i));
        int now = mn.second;
        if (now == -1)
            return {};
        vector <int> path = {now};
        while (rt[now] != -1) {
            now = rt[now], path.push_back(now);
        }
        reverse(path.begin(), path.end());
        return path;
    }
    vector <bool> solve(int n) {
        vector <bool> I(n, false);
        while (true) {
            vector <bool> X1 = m1.build_X(I), X2 = m2.build_X(I);
            if (count(X1.begin(), X1.end(), 0) == n || count(X2.begin(), X2.end(), 0) == n)
                break;
            int add = -1;
            for (int i = 0; i < n; ++i) if (X1[i] && X2[i]) {
                add = i;
                break;
            }
            if (add != -1) {
                I[add] = true;
                continue;
            }
            adj.assign(n, vector <int>());
            m1.build_exchange_graph(adj, I);
            m2.build_exchange_graph(adj, I);
            vector <int> path = bfs(X1, X2);
            if (path.empty())
                break;
            for (int i : path)
                I[i] = !I[i];
        }
        return I;
    }
    vector <int> SPFA(vector <bool> &X1, vector <bool> &X2, vector <bool> &I, vector <int> &weight) {
        int n = X1.size();
        queue <int> q;
        vector <pair <int, int>> dis(n, make_pair(1 << 30, -1));
        vector <int> rt(n, -1);
        vector <bool> vis(n, false);
        for (int i = 0; i < n; ++i) if (X1[i])
            q.push(i), dis[i] = make_pair(-weight[i], 0), vis[i] = true;
        while (!q.empty()) {
            int v = q.front(); q.pop();
            vis[v] = false;
            for (int u : adj[v]) {
                pair <int, int> nxt = mp(dis[v].first + (I[u] ? weight[u] : -weight[u]), dis[v].second + 1);
                if (dis[u] > nxt) {
                    dis[u] = nxt, rt[u] = v;
                    if (!vis[u])
                        q.push(u), vis[u] = true;
                }
            }
        }
        pair <pair <int, int>, int> mn = make_pair(make_pair(1 << 30, -1), -1);
        for (int i = 0; i < n; ++i) if (X2[i])
            mn = min(mn, make_pair(dis[i], i));
        int now = mn.second;
        if (now == -1)
            return {};
        vector <int> path = {now};
        while (rt[now] != -1) {
            now = rt[now], path.push_back(now);
        }
        reverse(path.begin(), path.end());
        return path;
    }
    vector <bool> solve_max_weight(vector <int> weight) {
        int n = weight.size();
        vector <bool> I(n, false);
        while (true) {
            vector <bool> X1 = m1.build_X(I), X2 = m2.build_X(I);
            if (count(X1.begin(), X1.end(), 0) == n || count(X2.begin(), X2.end(), 0) == n)
                break;
            adj.assign(n, vector <int>());
            m1.build_exchange_graph(adj, I);
            m2.build_exchange_graph(adj, I);
            vector <int> path = SPFA(X1, X2, I, weight);
            if (path.empty())
                break;
            for (int i : path)
                I[i] = !I[i];
        }
        return I;
    }
};

int main () {
    owo;
    int n, k;
    cin >> n >> k;
    vector <int> deg(n, n);
    for (int i = 0; i < k; ++i)
        cin >> deg[i];
    vv <int> w(n, n, 0);
    for (int i = 0; i < n; ++i) {
        for (int j = i + 1; j < n; ++j) {
            cin >> w[i][j];
        }
    }
    int ans = 1 << 30;
    vector <pair <int, int>> useful;
    {
        Dsu dsu(n);
        vector <pair <int, int>> E;
        for (int i = k; i < n; ++i) for (int j = i + 1; j < n; ++j)
            E.eb(i, j);
        sort(all(E), [&](pii i, pii j) {
            return w[i.X][i.Y] < w[j.X][j.Y]; 
        });
        for (auto [u, v] : E) {
            if (dsu.Union(u, v))
                useful.eb(u, v);
        }
    }
    for (int s = 0; s < 1 << (k * (k - 1) / 2); ++s) {
        Dsu dsu(k);
        vector <int> d = deg;
        bool cycle = false;
        int cost = 0, ecnt = 0, idx = 0;
        for (int i = 0; i < k; ++i) for (int j = i + 1; j < k; ++j, ++idx) if (s >> idx & 1) {
            cycle |= !dsu.Union(i, j), cost += w[i][j], ecnt++;
            d[i]--, d[j]--;
        }
        if (cycle || *min_element(all(d)) < 0)
            continue;
        vector <edge> E;
        vector <int> weight;
        for (int i = 0; i < k; ++i) for (int j = k; j < n; ++j) {
            E.push_back({dsu.Find(i), j, i}), weight.push_back(-w[i][j]);
        }
        for (auto [u, v] : useful) {
            E.push_back({u, v, u}), weight.push_back(-w[u][v]);
        }
        GraphMatroid m1(n, E);
        DegreeMatroid m2(n, E, d);
        MatroidIntersection <GraphMatroid, DegreeMatroid> solver(m1, m2);
        vector <bool> I = solver.solve_max_weight(weight);
        for (int i = 0; i < E.size(); ++i) if (I[i])
            cost -= weight[i], ecnt++;
        if (ecnt == n - 1)
            ans = min(ans, cost);
    }
    cout << ans << '\n';
}