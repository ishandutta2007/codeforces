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
#define info() cout << __PRETTY_FUNCTION__ << ": " << __LINE__ << endl
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
template <typename T> struct vvvv : vector <vvv <T>> {
    vvvv(int n, int m, int k, int t, T v) : vector <vvv <T>> (n, vvv <T>(m, k, t, v)) {}
    vvvv() {}
};
#ifdef Doludu
#define test(args...) abc("[" + string(#args) + "]", args)
#define owo freopen("input.txt", "r", stdin), freopen("output.txt", "w", stdout); 
#else
#define test(args...) void(0)
#define owo ios::sync_with_stdio(false); cin.tie(0)
#endif
const int mod = 998244353, N = 300001, logN = 20, K = 15;

struct edge {
    int v;
    lli w1, w2;
};

lli w[N];
vector <edge> adj[N];
lli mn[N];
vector <lli> pre_mn[N], suf_mn[N];
edge par[N];
int in[N], out[N], _id = 0;

void dfs1(int v, int pa) {
    mn[v] = w[v];
    in[v] = _id++;
    for (auto e : adj[v]) if (e.v != pa) {
        edge E = e; E.v = v;
        par[e.v] = E;
        dfs1(e.v, v);
        mn[v] = min(mn[v], mn[e.v] + e.w1 + e.w2);
        pre_mn[v].pb(mn[e.v] + e.w1 + e.w2);
    }
    suf_mn[v] = pre_mn[v];
    for (int i = 1; i < pre_mn[v].size(); ++i) {
        pre_mn[v][i] = min(pre_mn[v][i], pre_mn[v][i - 1]);
    }
    for (int i = int(suf_mn[v].size()) - 2; i >= 0; --i) {
        suf_mn[v][i] = min(suf_mn[v][i], suf_mn[v][i + 1]);
    }
    out[v] = _id++;
}

void dfs2(int v, int pa) {
    int t = 0;
    for (auto e : adj[v]) if (e.v != pa) {
        mn[e.v] = min(mn[e.v], mn[v] + e.w1 + e.w2);
        if (t) 
            mn[e.v] = min(mn[e.v], pre_mn[v][t - 1] + e.w1 + e.w2);
        if (t + 1 < suf_mn[v].size()) 
            mn[e.v] = min(mn[e.v], suf_mn[v][t + 1] + e.w1 + e.w2);
        dfs2(e.v, v);
        t++;
    }
}

lli jump[N][20][2][2], ver[N][20];

int main () {
    owo;
    int n;
    cin >> n;
    for (int i = 0; i < n; ++i) {
        cin >> w[i];
    }
    lli w1, w2;
    for (int i = 0, u, v; i < n - 1; ++i) {
        cin >> u >> v >> w1 >> w2, --u, --v;
        adj[u].pb({v, w1, w2});
        adj[v].pb({u, w1, w2});
    }
    dfs1(0, -1);
    dfs2(0, -1);
    for (int i = 0; i < n; ++i) {
        w[i] = min(w[i], mn[i]);
        ver[i][0] = i ? par[i].v : -1;
        if (i) {
            jump[i][0][0][0] = min(par[i].w1, w[i] + par[i].w2 + w[par[i].v]);
            jump[i][0][0][1] = min(par[i].w1 + w[par[i].v], w[i] + par[i].w2);
            jump[i][0][1][0] = min(par[i].w2 + w[par[i].v], w[i] + par[i].w1);
            jump[i][0][1][1] = min(par[i].w2, w[i] + par[i].w1 + w[par[i].v]);
        }
    }
    for (int j = 1; j < 20; ++j) {
        for (int i = 0; i < n; ++i) {
            if (ver[i][j - 1] == -1) {
                ver[i][j] = -1;
            } else {
                ver[i][j] = ver[ver[i][j - 1]][j - 1];
                if (ver[i][j] == -1)
                    continue;
                for (int f = 0; f < 2; ++f) for (int t = 0; t < 2; ++t) {
                    jump[i][j][f][t] = 1ll << 60;
                    for (int k = 0; k < 2; ++k) {
                        jump[i][j][f][t] = min(jump[i][j][f][t], jump[i][j - 1][f][k] + jump[ver[i][j - 1]][j - 1][k][t]);
                    }
                }
            }
        }
    }
    int q;
    cin >> q;
    while (q--) {
        int u, v;
        cin >> u >> v, --u, --v;
        int f = u & 1, t = v & 1;
        u >>= 1, v >>= 1;
        if (u == v) {
            cout << w[u] << '\n';
        } else {
            if (in[u] <= in[v] && out[u] >= out[v]) {
                swap(v, u), swap(f, t);
            }
            if (in[v] <= in[u] && out[v] >= out[u]) {
                // v top
                vector <lli> now(2, 1ll << 60);
                now[f] = 0;
                for (int k = 19; ~k; --k) {
                    int d = ver[u][k];
                    if (d == -1)
                        continue;
                    if (!(in[d] < in[v] && out[d] > out[v])) {
                        vector <lli> nxt(2, 1ll << 60);
                        for (int i = 0; i < 2; ++i) for (int j = 0; j < 2; ++j) {
                            nxt[j] = min(nxt[j], now[i] + jump[u][k][i][j]);
                        }
                        u = d;
                        now = nxt;
                    }
                }
                cout << now[t] << '\n';
            } else {
                vector <lli> now(2, 1ll << 60);
                now[f] = 0;
                for (int k = 19; ~k; --k) {
                    int d = ver[u][k];
                    if (d == -1)
                        continue;
                    if (!(in[d] <= in[v] && out[d] >= out[v])) {
                        vector <lli> nxt(2, 1ll << 60);
                        for (int i = 0; i < 2; ++i) for (int j = 0; j < 2; ++j) {
                            nxt[j] = min(nxt[j], now[i] + jump[u][k][i][j]);
                        }
                        u = d;
                        now = nxt;
                    }
                }
                vector <lli> nxt(2, 1ll << 60);
                for (int i = 0; i < 2; ++i) for (int j = 0; j < 2; ++j) {
                    nxt[j] = min(nxt[j], now[i] + jump[u][0][i][j]);
                }
                vector <lli> now2 = nxt;
                now = vector <lli>(2, 1ll << 60);
                now[t] = 0;
                u = ver[u][0];
                for (int k = 19; ~k; --k) {
                    int d = ver[v][k];
                    if (d == -1)
                        continue;
                    if (!(in[d] < in[u] && out[d] > out[u])) {
                        vector <lli> nxt(2, 1ll << 60);
                        for (int i = 0; i < 2; ++i) for (int j = 0; j < 2; ++j) {
                            nxt[j] = min(nxt[j], now[i] + jump[v][k][i][j]);
                        }
                        v = d;
                        now = nxt;
                    }
                }
                cout << min(now[0] + now2[0], now[1] + now2[1]) << '\n';
            }
        }
    }
}