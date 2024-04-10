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
const int mod = 998244353, N = 400005, logN = 18;

vector <int> adj[N];

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

template <typename T>
struct BIT {
    // single point add, prefix query sum
    vector <T> val;
    int n, offset;
    BIT () = default;
    BIT (int _n, int _offset = 3) : n(_n + _offset * 2), offset(_offset) {
        val.assign(n, 0);
    }
    void add(int p, T v) {
        for (p += offset; p < n; p += p & (-p))
            val[p] += v;
    }
    T query(int p) {
        T ans = 0;
        for (p += offset; p > 0; p -= p & (-p))
            ans += val[p];
        return ans;
    }
    T query(int l, int r) {
        // query [l, r)
        return query(r - 1) - query(l - 1);
    }
    int kth (int k) {
        // 1-index, return kth smallest number
        // 1 <= k && k <= current size
        int ans = 0;
        for (int i = 1 << __lg(n); i > 0; i >>= 1) {
            if (ans + i < n && val[ans + i] < k) k -= val[ans += i];
        }
        return ans - offset + 1;
    }
};

struct SweepLine {
    vector <array <int, 4>> query[N];
    vector <int> pt[N];
    int ans[N];
    void add_point(int x, int y) {
        pt[x].pb(y);
    }
    void add_query(int x1, int x2, int y1, int y2, int id) {
        query[y2].pb({x1, x2, id, 1});
        query[y1].pb({x1, x2, id, -1});
    }
    void solve() {
        BIT <int> bit(N);
        for (int x = 0; x < N; ++x) {
            for (auto i : query[x]) {
                ans[i[2]] += i[3] * bit.query(i[0], i[1]);
            }
            for (int y : pt[x])
                bit.add(y, 1);
        }
    }
};

int tag[N], jump[N][logN];

void dfs(int v, int pa) {
    for (int u : adj[v]) if (u != pa) {
        dfs(u, v);
        tag[v] = min(tag[v], tag[u]);
    }
}

int main () {
    owo;
    int n, m, q;
    cin >> n;
    for (int i = 1, p; i < n; ++i) {
        cin >> p, --p;
        adj[p].pb(i);
    }
    for (int i = 0; i < n; ++i)
        tag[i] = i;
    BinaryLifting A(n);
    SweepLine solver;
    cin >> m;
    for (int i = 0, u, v; i < m; ++i) {
        cin >> u >> v, --u, --v;
        int lca = A.lca(u, v);
        tag[u] = min(tag[u], lca);
        tag[v] = min(tag[v], lca);
        solver.add_point(A.in[u], A.in[v]);
        solver.add_point(A.in[v], A.in[u]);
    }
    dfs(0, -1);
    for (int i = 0; i < n; ++i)
        jump[i][0] = tag[i];
    for (int j = 1; j < logN; ++j) {
        for (int i = 0; i < n; ++i) {
            jump[i][j] = jump[jump[i][j - 1]][j - 1];
        }
    }
    cin >> q;
    vector <int> ans(q), is(q);
    for (int id = 0, u, v; id < q; ++id) {
        cin >> u >> v, --u, --v;
        if (A.anc(v, u))
            swap(u, v);
        if (A.anc(u, v)) {
            for (int i = logN - 1; ~i; --i) {
                int k = jump[v][i];
                if (!A.anc(k, u))
                    ans[id] += 1 << i, v = k;
            }
            ans[id]++, is[id] = true;
        } else {
            for (int i = logN - 1; ~i; --i) {
                int k = jump[v][i];
                if (!A.anc(k, u))
                    ans[id] += 1 << i, v = k;
            }
            for (int i = logN - 1; ~i; --i) {
                int k = jump[u][i];
                if (!A.anc(k, v))
                    ans[id] += 1 << i, u = k;
            }
            solver.add_query(A.in[u], A.out[u] + 1, A.in[v], A.out[v] + 1, id);
        }
    }
    solver.solve();
    for (int i = 0; i < q; ++i) {
        if (is[i]) {
            cout << (ans[i] >= n ? -1 : ans[i]) << '\n';
        } else {
            cout << (ans[i] >= n ? -1 : ans[i] + (solver.ans[i] == 0 ? 2 : 1)) << '\n';
        }
    }
}