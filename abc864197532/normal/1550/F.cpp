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
const int mod = 1e9 + 7, N = 200001, logN = 20, K = 111;

struct edge {
    int u, v, w;
    edge (int _u, int _v, int _w) : u(_u), v(_v), w(_w) {}
    bool operator < (const edge& o) {
        return w < o.w;
    }
};

struct Dsu {
    int dsu[N], size[N], n, cc;
    Dsu (int _n) : n(_n), cc(_n) {
        for (int i = 0; i < n; ++i) {
            dsu[i] = i;
            size[i] = 1;
        }
    }
    int Find(int v) {
        if (dsu[v] == v) return v;
        return dsu[v] = Find(dsu[v]);
    }
    bool Union(int v, int u) {
        int x = Find(v), y = Find(u);
        if (x == y) return false;
        if (size[x] > size[y]) swap(x, y);
        dsu[x] = y;
        size[y] += size[x];
        size[x] = 0;
        cc--;
        return true;
    }
    bool same(int u, int v) {
        return Find(u) == Find(v);
    }
};

vector <pii> adj[N];
int mx[N];

void dfs(int v, int pa) {
    for (auto [u, w] : adj[v]) if (u != pa) {
        mx[u] = max(mx[v], w);
        dfs(u, v);
    }
}



int main () {
    owo;
    int n, q, s, d;
    cin >> n >> q >> s >> d, --s;
    vector <int> a(n);
    for (int i = 0; i < n; ++i) cin >> a[i];
    Dsu dsu(n);
    set <pii> rock;
    for (int i = 0; i < n; ++i) rock.insert({a[i], i});
    auto dis = [&](int i, int j) {
        return abs(abs(a[i] - a[j]) - d);
    };
    while (dsu.cc > 1) {
        vector <int> now[n];
        vector <edge> best(n, edge(-1, -1, 1 << 30));
        for (int i = 0; i < n; ++i) now[dsu.Find(i)].pb(i);
        for (int i = 0; i < n; ++i) if (!now[i].empty()) {
            for (int j : now[i]) rock.erase({a[j], j});
            for (int j : now[i]) {
                {
                    auto it = rock.lower_bound({a[j] + d, j});
                    if (it != rock.end()) {
                        int v = it->Y;
                        edge cur = edge(v, j, dis(v, j));
                        if (cur < best[i]) best[i] = cur;
                    }
                    if (it != rock.begin()) {
                        int v = (--it)->Y;
                        edge cur = edge(v, j, dis(v, j));
                        if (cur < best[i]) best[i] = cur;
                    }
                }
                {
                    auto it = rock.lower_bound({a[j] - d, j});
                    if (it != rock.end()) {
                        int v = it->Y;
                        edge cur = edge(v, j, dis(v, j));
                        if (cur < best[i]) best[i] = cur;
                    }
                    if (it != rock.begin()) {
                        int v = (--it)->Y;
                        edge cur = edge(v, j, dis(v, j));
                        if (cur < best[i]) best[i] = cur;
                    }
                }
            }
            for (int j : now[i]) rock.insert({a[j], j});
        }
        for (int i = 0; i < n; ++i) if (!now[i].empty()) {
            if (dsu.Union(best[i].u, best[i].v)) {
                adj[best[i].u].eb(best[i].v, best[i].w);
                adj[best[i].v].eb(best[i].u, best[i].w);
            }
        }
    }
    dfs(s, -1);
    while (q--) {
        int v, k;
        cin >> v >> k, --v;
        cout << (mx[v] <= k ? "YES\n" : "NO\n");
    }
}