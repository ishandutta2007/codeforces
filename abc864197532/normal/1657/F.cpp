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
const int mod = 998244353, N = 1600087, logN = 19, K = 111, M = 1000006, C = 500;

struct TwoSAT {
    // 0-indexed
    // idx i * 2 -> +i, i * 2 + 1 -> -i
    vector <int> adj[N], radj[N], newadj[N];
    vector <int> dfs_ord, idx, solution;
    vector <bool> vis;
    int n, nscc;
    TwoSAT (int _n) : n(_n), nscc(0) {
        idx.assign(n * 2, -1), vis.assign(n * 2, false), solution.assign(n, -1);
    }
    void add_clause(int x, int y) {
        // idx i * 2 -> +i, i * 2 + 1 -> -i
        int nx = x ^ 1, ny = y ^ 1;
        adj[nx].push_back(y), radj[y].push_back(nx);
        adj[ny].push_back(x), radj[x].push_back(ny);
    }
    void dfs(int v) {
        vis[v] = true;
        for (int u : adj[v]) if (!vis[u])
            dfs(u);
        dfs_ord.push_back(v);
    }
    void rdfs(int v) {
        idx[v] = nscc;
        for (int u : radj[v]) if (idx[u] == -1)
            rdfs(u);
    }
    bool find_sol() {
        vis.assign(n, false), idx.assign(n, -1);
        for (int i = 0; i < n * 2; ++i) if (!vis[i])
            dfs(i);
        reverse(dfs_ord.begin(), dfs_ord.end());
        for (int i : dfs_ord) if (idx[i] == -1)
            rdfs(i), nscc++;
        for (int i = 0; i < n; i++) {
            if (idx[i << 1] == idx[i << 1 | 1])
                return false;
            if (idx[i << 1] < idx[i << 1 | 1])
                solution[i] = 0;
            else
                solution[i] = 1;
        }
        return true;
    }
};

int main () {
    owo;
    int n, q;
    cin >> n >> q;
    vector <vector <int>> adj(n);
    for (int i = 0, u, v; i < n - 1; ++i) {
        cin >> u >> v, --u, --v;
        adj[u].pb(v), adj[v].pb(u);
    }
    vector <int> par(n), dep(n);
    function <void(int, int)> dfs = [&](int v, int pa) {
        par[v] = pa;
        dep[v] = ~pa ? dep[pa] + 1 : 0;
        for (int u : adj[v]) if (u != pa)
            dfs(u, v);
    };
    dfs(0, -1);
    auto get_path = [&](int u, int v) {
        vector <int> l, r;
        while (u != v) {
            if (dep[u] < dep[v])
                r.pb(v), v = par[v];
            else
                l.pb(u), u = par[u];
        }
        reverse(all(r));
        l.pb(u);
        for (int i : r)
            l.pb(i);
        return l;
    };
    vv <char> c(n, 2, ' ');
    TwoSAT solver(n + q);
    for (int i = 0, u, v; i < q; ++i) {
        string s;
        cin >> u >> v >> s, --u, --v;
        vector <int> path = get_path(u, v);
        assert(path.size() == s.length());
        string t = s; reverse(all(t));
        int qid = n + i;
        for (int j = 0; j < path.size(); ++j) {
            if (c[path[j]][0] == ' ')
                c[path[j]][0] = s[j], c[path[j]][1] = t[j];
            if (c[path[j]][0] != s[j])
                solver.add_clause(qid * 2, path[j] * 2);
            if (c[path[j]][1] != s[j])
                solver.add_clause(qid * 2, path[j] * 2 + 1);
            if (c[path[j]][0] != t[j])
                solver.add_clause(qid * 2 + 1, path[j] * 2);
            if (c[path[j]][1] != t[j])
                solver.add_clause(qid * 2 + 1, path[j] * 2 + 1);
        }
    }
    if (!solver.find_sol())
        cout << "NO\n";
    else {
        cout << "YES\n";
        for (int i = 0; i < n; ++i) {
            cout << (c[i][solver.solution[i]] == ' ' ? 'a' : c[i][solver.solution[i]]);
        }
        cout << '\n';
    }
}