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
const int mod = 998244353, N = 100100, logN = 20, M = 6e6;

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

vector <int> adj[N];
bool fail[N << 1], ans[N << 1];
int U[N << 1], V[N << 1], cnt[N];
vector <int> F[N];
vector <int> newadj[N << 1];

struct PointBCC {
    vector <vector <int>> idx;
    vector <int> low, dep, par, stk, stkE;
    vector <bool> cut, visE;
    int n, nbcc;
    PointBCC () = default;
    PointBCC (int _n) : n(_n), nbcc(0) {
        low.assign(n, -1), dep.assign(n, -1), idx.assign(n, vector <int> ());
        par.assign(n, -1), cut.assign(n, false), visE.assign(N << 1, false);
        for (int i = 0; i < n; ++i) if (dep[i] == -1)
            dfs(i, -1);
        // idx  < n -> bcc
        // idx >= n -> cut point
        for (int i = 0; i < n; ++i) if (cut[i]) {
            for (int j : idx[i]) {
                newadj[j].push_back(i + n);
                newadj[i + n].push_back(j);
            }
        }
    }
    void dfs(int v, int pa) {
        low[v] = dep[v] = ~pa ? dep[pa] + 1 : 0;
        stk.push_back(v);
        par[v] = pa;
        int ch = 0;
        for (int id : adj[v]) {
            int u = U[id] ^ V[id] ^ v;
            if (u == pa)
                continue;
            if (!visE[id])
                visE[id] = true, stkE.push_back(id);
            if (dep[u] == -1) {
                dfs(u, v);
                low[v] = min(low[v], low[u]);
                ch++;
                if (low[u] >= dep[v]) {
                    // v is a cut point
                    cut[v] = true;
                    int x;
                    vector <int> cc = {v};
                    do {
                        x = stk.back(), stk.pop_back();
                        idx[x].push_back(nbcc);
                        cc.pb(x);
                    } while (x != u);
                    do {
                        x = stkE.back(), stkE.pop_back();
                        if (!fail[x])
                            cnt[U[x]]++, cnt[V[x]]++;
                    } while (x != id);
                    for (int i : cc) {
                        if (cnt[i] > 2) {
                            cout << string(n, '0') << '\n';
                            exit(0);
                        }
                        if (cnt[i] == 2)
                            F[i].pb(nbcc);
                        cnt[i] = 0;
                    }
                    idx[v].push_back(nbcc++);
                }
            } else {
                low[v] = min(low[v], dep[u]);
            }
        }
        if (pa == -1 && ch < 2) 
            cut[v] = false;
    }
};

void solve() {
    int n, m;
    cin >> n >> m;
    Dsu dsu(n);
    for (int i = 1, u, v; i <= m; ++i) {
        cin >> u >> v, --u, --v;
        if (!dsu.Union(u, v)) {
            fail[i] = true;
        }
        adj[u].pb(i), adj[v].pb(i);
        U[i] = u, V[i] = v;
    }
    PointBCC solver(n);
    fill(ans, ans + (N << 1), true);
    function <void(int, int)> dfs = [&](int v, int pa) {
        ans[v] = false;
        for (int u : newadj[v]) if (u != pa) {
            dfs(u, v);
        }
    };
    for (int i = 0; i < n; ++i) if (!F[i].empty()) {
        if (solver.cut[i]) {
            if (F[i].size() > 1) {
                cout << string(n, '0') << '\n';
                return;
            }
            dfs(i + n, F[i][0]);
        }
    }
    for (int i = 0; i < n; ++i) {
        if (solver.cut[i]) {
            cout << ans[i + n];
        } else {
            cout << (ans[solver.idx[i][0]] & F[i].empty());
        }
    }
    cout << endl;
}

int main () {
    owo;
    int t = 1;
    // cin >> t;
    while (t--) {
        solve();
    }
}