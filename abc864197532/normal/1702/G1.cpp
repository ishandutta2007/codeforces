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
const int mod = 998244353, N = 200005, logN = 20, M = 6e6;

vector <int> adj[N], newadj[N];

struct BinaryLifting {
    // 0-index
    vector <int> in, out, dep;
    vector <vector <int>> jump;
    int _t, n, lg;
    BinaryLifting () = default;
    BinaryLifting (int _n) : n(_n) {
        lg = __lg(n) + 1, _t = 0;
        jump.assign(n, vector <int> (lg, -1));
        in.assign(n, 0), out.assign(n, 0), dep.assign(n, 0);
        dfs(0, -1);
    }
    void dfs(int v, int pa) {
        in[v] = _t++, jump[v][0] = pa;
        dep[v] = ~pa ? dep[pa] + 1 : 0;
        for (int i = 1; i < lg; ++i) {
            int k = jump[v][i - 1];
            jump[v][i] = ~k ? jump[k][i - 1] : k;
        }
        for (int u : adj[v]) if (u != pa) {
            dfs(u, v);
        }
        out[v] = _t++;
    }
    bool anc(int u, int v) {
        return in[u] <= in[v] && out[u] >= out[v];
    }
    int lca(int u, int v) {
        if (anc(u, v))
            return u;
        if (anc(v, u))
            return v;
        for (int i = lg - 1; ~i; --i) {
            int k = jump[u][i];
            if (~k && !anc(k, v))
                u = k;
        }
        return jump[u][0];
    }
    int lift(int u, int d) {
        for (int i = 0; i < lg; ++i) if (d >> i & 1)
            u = jump[u][i];
        return u;
    }
    int dis(int u, int v) {
        return dep[u] + dep[v] - dep[lca(u, v)] * 2;
    }
};

int main () {
    owo;
    int n, q;
    cin >> n;
    for (int i = 0, u, v; i < n - 1; ++i) {
        cin >> u >> v, --u, --v;
        adj[u].pb(v), adj[v].pb(u);
    }
    BinaryLifting LCA(n);
    cin >> q;
    while (q--) {
        int sz; cin >> sz;
        vector <int> a(sz);
        for (int &i : a)
            cin >> i, --i;
        sort(all(a), [&](int i, int j) {
            return LCA.in[i] < LCA.in[j];
        });
        for (int i = 1; i < sz; ++i) {
            a.pb(LCA.lca(a[i - 1], a[i]));
        }
        sort(all(a), [&](int i, int j) {
            return LCA.in[i] < LCA.in[j];
        });
        a.resize(unique(all(a)) - a.begin());
        for (int i = 1; i < a.size(); ++i) {
            int u = LCA.lca(a[i - 1], a[i]), v = a[i];
            newadj[u].pb(v), newadj[v].pb(u);
        }
        bool ans = true;
        for (int i = 0; i < a.size(); ++i) if (newadj[a[i]].size() > 2)
            ans = false;
        cout << (ans ? "YES\n" : "NO\n");
        for (int i = 0; i < a.size(); ++i) 
            newadj[a[i]].clear();
    }
}