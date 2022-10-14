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
#define owo freopen("input.txt", "r", stdin), freopen("output.txt", "w", stdout)
#else
#define test(args...) void(0)
#define owo ios::sync_with_stdio(false); cin.tie(0)
#endif
const int mod = 998244353, N = 1e5 + 1, logN = 18, B = 2048;

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
} LCA;

int idx[N], val[N], par[N], cur_par[N], n, curans;
bool dead[N];
vector <pii> chain[N];
int chain_offset[N], pt[N];

void dfs(int v, int pa) {
    for (int u : adj[v]) if (u != pa) {
        dfs(u, v);
        if (idx[v] == -1 && idx[u] != -1)
            idx[v] = idx[u];
    }
}

void build_chain(int v) {
    sort(all(chain[v]));
    vector <pii> nxt = chain[v]; chain[v].clear();
    for (auto [x, y] : nxt) {
        if (!chain[v].empty() && chain[v].back().X == x)
            chain[v].back().Y += y;
        else
            chain[v].eb(x, y);
    }
    pt[v] = -1;
    for (int i = 0; i < chain[v].size(); ++i) if (chain[v][i].X < 0)
        pt[v] = i;
}

void chain_add(int v, int op) {
    if (chain[v].empty()) {
        chain_offset[v] += op;
        return;
    }
    if (op == 1) {
        chain_offset[v]++;
        if (pt[v] + 1 < chain[v].size() && chain[v][pt[v] + 1].X < chain_offset[v]) {
            pt[v]++, curans += chain[v][pt[v]].Y;
        }
    } else {
        chain_offset[v]--;
        if (pt[v] >= 0 && chain[v][pt[v]].X >= chain_offset[v]) {
            curans -= chain[v][pt[v]].Y, pt[v]--;
        }
    }
}

void point_add(int v, int op) {
    if (op == 1) {
        if (!dead[v] && !val[v])
            curans++;
        val[v]--;
    } else {
        val[v]++;
        if (!dead[v] && !val[v])
            curans--;
    }
}

void solve(vector <pii> queries) {
    vector <int> useful_node;
    for (auto [v, _] : queries)
        useful_node.pb(v);
    sort(all(useful_node), [&](int u, int v) {
        return LCA.in[u] < LCA.in[v];
    });
    useful_node.resize(unique(all(useful_node)) - useful_node.begin());
    {
        int m = useful_node.size();
        for (int i = 1; i < m; ++i)
            useful_node.pb(LCA.lca(useful_node[i - 1], useful_node[i]));
    }
    sort(all(useful_node)), useful_node.resize(unique(all(useful_node)) - useful_node.begin());
    fill(idx, idx + n, -1), fill(cur_par, cur_par + n, -1);

    for (int v : useful_node)
        idx[v] = v;
    dfs(0, -1);
    for (int i = 0; i < n; ++i) {
        if (idx[i] != i && idx[i] != -1 && !dead[i])
            chain[idx[i]].eb(val[i], 1);
    }
    for (int v : useful_node) {
        build_chain(v);
        for (int u : adj[v]) if (u != par[v]) {
            if (idx[u] != -1)
                cur_par[idx[u]] = v;
        }
    }

    for (auto [v, op] : queries) {
        int now = v;
        while (now != -1) {
            point_add(now, op);
            chain_add(now, op);
            now = cur_par[now];
        }
        if (!dead[v]) {
            curans -= val[v] < 0;
            dead[v] = true;
        } else {
            dead[v] = false;
            curans += val[v] < 0;
        }
        cout << curans << ' ';
    }

    for (int i = 0; i < n; ++i) {
        if (idx[i] != i && idx[i] != -1)
            val[i] -= chain_offset[idx[i]];
    }

    for (int v : useful_node)
        chain[v].clear(), chain_offset[v] = 0;
}

int main () {
    owo;
    int q;
    cin >> n >> q;
    for (int i = 1; i < n; ++i)
        cin >> par[i], adj[--par[i]].pb(i);
    for (int i = 0; i < n; ++i)
        cin >> val[i];
    LCA = BinaryLifting(n);
    vector <pii> cur;
    while (q--) {
        int x;
        cin >> x;
        cur.eb(abs(x) - 1, x > 0 ? 1 : -1);
        if (cur.size() == B) {
            solve(cur);
            cur.clear();
        }
    }
    if (!cur.empty()) {
        solve(cur);
    }
    cout << endl;
}