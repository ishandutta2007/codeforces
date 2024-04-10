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
const int mod = 998244353, N = 600001, logN = 18, B = 1 << 8, M = 1 << 21;

struct TwoSAT {
    // 0-indexed
    // idx i * 2 -> +i, i * 2 + 1 -> -i
    vector <vector <int>> adj, radj;
    vector <int> dfs_ord, idx, solution;
    vector <bool> vis;
    int n, nscc;
    // idx i * 2 -> +i, i * 2 + 1 -> -i
    TwoSAT () = default;
    TwoSAT (int _n) : n(_n), nscc(0) {
        adj.resize(n * 2), radj.resize(n * 2);
        idx.assign(n * 2, -1), vis.assign(n * 2, false), solution.assign(n, -1);
    }
    void add_clause(int x, int y) {
        // (x or y) = true
        int nx = x ^ 1, ny = y ^ 1;
        adj[nx].push_back(y), radj[y].push_back(nx);
        adj[ny].push_back(x), radj[x].push_back(ny);
    }
    void add_ifthen(int x, int y) {
        // if x = true then y = true
        add_clause(x ^ 1, y);
    }
    void add_must(int x) {
        // x = true
        int nx = x ^ 1;
        adj[nx].pb(x), radj[x].pb(nx);
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
    /*
     a_i <= 0, a_i <= 1, a_i <= 2, a_i <= k
     0 0 0 0 1 1 1 1 1
     (0)
     a_i <= x then a_i <= x + 1
     a_i <= x is false then a_{i + 1} <= x is false
     (1) a_i != x
     if a_i <= x then a_i <= x - 1
     (2) a_i + a_j <= x
     if a_i <= y - 1 is false then a_j <= x - y
     (3) a_i + a_j >= x
     if a_i <= y then a_j <= x - y - 1 is false
     */
    int t;
    cin >> t;
    while (t--) {
        int n, m, k;
        cin >> n >> m >> k;
        TwoSAT solver(n * (k + 1));
        auto idx = [&](int i, int a) {
            return i * (k + 1) + a;
        };
        for (int i = 0; i < n; ++i) for (int j = 0; j < k; ++j) {
            solver.add_ifthen(idx(i, j) * 2, idx(i, j + 1) * 2);
        }
        for (int i = 1; i < n; ++i) for (int j = 0; j <= k; ++j) {
            solver.add_ifthen(idx(i - 1, j) * 2 + 1, idx(i, j) * 2 + 1);
        }
        for (int i = 0; i < n; ++i)
            solver.add_must(idx(i, 0) * 2 + 1), solver.add_must(idx(i, k) * 2);
        while (m--) {
            int ty;
            cin >> ty;
            if (ty == 1) {
                int i, x;
                cin >> i >> x, --i;
                solver.add_ifthen(idx(i, x) * 2, idx(i, x - 1) * 2);
            } else if (ty == 2) {
                int i, j, x;
                cin >> i >> j >> x, --i, --j;
                for (int t : {0, 1}) {
                    for (int y = 1; y <= k; ++y) {
                        int res = x - y;
                        if (res < 0)
                            res = 0;
                        if (res > k)
                            res = k;
                        solver.add_ifthen(idx(i, y - 1) * 2 + 1, idx(j, res) * 2);
                    }
                    swap(i, j);
                }
            } else {
                int i, j, x;
                cin >> i >> j >> x, --i, --j;
                for (int t : {0, 1}) {
                    for (int y = 1; y <= k; ++y) {
                        int res = x - y - 1;
                        if (res < 0)
                            res = 0;
                        if (res > k)
                            res = k;
                        solver.add_ifthen(idx(i, y) * 2, idx(j, res) * 2 + 1);
                    }
                    swap(i, j);
                }
            }
        }
        if (solver.find_sol()) {
            vector <int> ans(n, k);
            for (int i = 0; i < n; ++i) {
                for (int j = 1; j <= k; ++j) {
                    if (solver.solution[idx(i, j)] && !solver.solution[idx(i, j - 1)])
                        ans[i] = j;
                }
            }
            printv(all(ans));
        } else {
            cout << "-1\n";
        }
    }
}