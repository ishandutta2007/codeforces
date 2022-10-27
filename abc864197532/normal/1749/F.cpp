#include <bits/stdc++.h>
using namespace std;
#define ll long long
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
const int mod = 998244353, N = 1 << 18, D = 22;

vector <int> adj[N];
int val[N][D], in[N], out[N], par[N], jump[N][D], _t;

void dfs(int v, int pa) {
    par[v] = jump[v][0] = pa;
    in[v] = _t++;
    for (int u : adj[v]) if (u != pa)
        dfs(u, v);
    out[v] = _t++;
}

bool anc(int u, int v) {
    return in[u] <= in[v] && out[u] >= out[v];
}

int lca(int u, int v) {
    if (anc(u, v)) return u;
    if (anc(v, u)) return v;
    for (int i = D - 1; ~i; --i) {
        int k = jump[u][i];
        if (~k && !anc(k, v))
            u = k;
    }
    return jump[u][0];
}

void build() {
    dfs(0, -1);
    for (int i = 1; i < D; ++i) {
        for (int j = 0; j < N; ++j) {
            int k = jump[j][i - 1];
            jump[j][i] = ~k ? jump[k][i - 1] : -1;
        }
    }
}

struct BIT {
    // single point add, prefix query sum
    int val[N << 1], offset;
    BIT (int _offset = 3) : offset(_offset) {
        fill(val, val + (N << 1), 0);
    }
    void add(int p, int v) {
        for (p += offset; p < (N << 1); p += p & (-p))
            val[p] += v;
    }
    int query(int p) {
        int ans = 0;
        for (p += offset; p > 0; p -= p & (-p))
            ans += val[p];
        return ans;
    }
    int query(int l, int r) {
        // query [l, r)
        return query(r - 1) - query(l - 1);
    }
} bit[D];

void solve() {
    int n, q;
    cin >> n;
    for (int i = 0, u, v; i < n - 1; ++i) {
        cin >> u >> v, --u, --v;
        adj[u].pb(v), adj[v].pb(u);
    }
    build();
    cin >> q;
    while (q--) {
        int t;
        cin >> t;
        if (t == 1) {
            int v; cin >> v, --v;
            int ans = val[v][0] + bit[0].query(in[v], out[v]);
            for (int p = par[v], i = 1; i < D && ~p; ++i, p = par[p]) {
                ans += val[p][i] + bit[i].query(in[p], out[p]);
            }
            cout << ans << '\n';
        } else {
            int u, v, k, d; cin >> u >> v >> k >> d, --u, --v;
            int l = lca(u, v);
            bit[d].add(in[u], k), bit[d].add(in[v], k), bit[d].add(in[l], -k * 2);
            for (int i = 0; i <= d; ++i)
                val[l][i] += k;
            for (int p = par[l], curd = 1; curd <= d && ~p; ++curd, p = par[p], l = par[l]) {
                for (int j = 0; j <= d - curd; ++j) {
                    val[p][j] += k;
                    if (j) val[l][j - 1] -= k;
                }
            }
        }
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