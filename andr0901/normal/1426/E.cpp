//#pragma GCC optimize("Ofast")
#include <bits/stdc++.h>

using namespace std;

//vector string deque break continue
#define forn(i, s, f) for (int i = (int)s; i < (int)f; i++)
#define ll long long
#define ull unsigned long long
#define ld long double
#define pii pair <int, int>
#define fs first
#define sc second
#define pf push_front
#define pb push_back
#define pop_f pop_front
#define pop_b pop_back
#define eb emplace_back
#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()
#define sz(x) (int)(x).size()

#ifdef DEBUG
#else
    #define cerr if (false) cerr
#endif

template <typename T> istream& operator>>(istream& in, vector <T>& a) {for (auto& i : a) in >> i; return in;}
template <typename T> ostream& operator<<(ostream& out, vector <T>& a)  {for (auto& i : a) out << i << " "; return out;}
template <typename T, typename U> void chkmin(T& a, U b) {if (a > b) a = b;}
template <typename T, typename U> void chkmax(T& a, U b) {if (a < b) a = b;}

template <typename T, typename U> 
class Mincost_maxflow {
private:
    struct Edge {
        int v, u, idx;
        T c, f;
        U cost;
    };

    vector <vector <int>> gr;
    vector <Edge> e;
    vector <U> dst;
    vector <int> par;

    bool ford_bellman(int s, int t) {
        dst = vector <U> (sz(gr), numeric_limits<U>::max() / 2);
        par = vector <int> (sz(gr));
        dst[s] = 0;
        forn (iters, 0, sz(gr)) {
            forn (i, 0, sz(e)) {
                int v = e[i].v, u = e[i].u;
                T c = e[i].c, f = e[i].f;
                U cost = e[i].cost; 
                if (c - f > 0 && dst[v] + cost < dst[u]) {
                    dst[u] = dst[v] + cost;
                    par[u] = i;
                }
            }
        }
        return dst[t] < numeric_limits<U>::max() / 2;
    }

    T find_path(int s, int t, vector <vector <int>>& paths) {
        vector <bool> used(sz(gr));
        deque <int> edges;
        int v = s;
        while (!used[v] && v != t) {
            used[v] = true;
            int nxt = -1;
            for (int i : gr[v]) {
                int u = e[i].u;
                T f = e[i].f;
                if (f > 0) {
                    nxt = i;
                    break;
                }
            }
            if (nxt == -1)
                return 0;
            edges.pb(nxt);
            v = e[nxt].u;
        }
        if (used[v])
            while (e[edges[0]].v != v)
                edges.pop_front();
        T delta = numeric_limits<T>::max();
        for (int i : edges)
            chkmin(delta, e[i].f);
        for (int i : edges) {
            e[i].f -= delta;
            e[i ^ 1].f += delta;
        }
        if (!used[v]) {
            paths.pb({});
            for (auto i : edges)
                paths.back().pb(e[i].idx);
        }
        return delta;
    }

public:
    Mincost_maxflow (int _n) {
        gr.resize(_n);
    }

    pair <T, U> find(int s, int t) {
        pair <T, U> ans = {0, 0};
        while (ford_bellman(s, t)) {
            T delta = numeric_limits<T>::max();
            int v = t;
            while (v != s) {
                chkmin(delta, e[par[v]].c - e[par[v]].f);
                v = e[par[v]].v;
            }
            v = t;
            while (v != s) {
                ans.second += delta * e[par[v]].cost;
                e[par[v]].f += delta;
                e[par[v] ^ 1].f -= delta;
                v = e[par[v]].v;
            }
            ans.first += delta;
        }
        return ans;
    }

    vector <vector <int>> decompose(int s, int t) {
        vector <vector <int>> paths;
        while (find_path(s, t, paths));
        return paths; 
    }

    void add_edge(int v, int u, T c, U cost, int i = -1) {
        gr[v].pb(sz(e));
        e.pb({v, u, i, c, 0, cost});
        gr[u].pb(sz(e));
        e.pb({u, v, i, 0, 0, -cost});
    }
};

int main() {
    ios_base::sync_with_stdio(0), cin.tie(0);
    int n;
    cin >> n;
    vector <int> a(3), b(3);
    cin >> a >> b;
    int mx = 0;
    forn (i, 0, 3)
        mx += min(a[i], b[(i + 1) % 3]);
    Mincost_maxflow <int, int> g(8);
    int s = 6, t = 7;
    forn (i, 0, 3)
        g.add_edge(s, i, a[i], 0);
    forn (i, 0, 3)
        g.add_edge(i + 3, t, b[i], 0);
    forn (i, 0, 3)
        g.add_edge(i, i + 3, 1e9, 0);
    forn (i, 0, 3)
        g.add_edge(i, 3 + (i + 1) % 3, 1e9, 1);
    forn (i, 0, 3)
        g.add_edge(i, 3 + (i + 2) % 3, 1e9, 0);
    cout << g.find(s, t).sc << " " << mx;   
    return 0;
}