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
const int mod = 1e9 + 7, N = 1 << 19, logN = 20;

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

void solve() {
    int n;
    cin >> n;
    vvv <bool> is(n, n, n, false); // dis(i, k) = dis(j, k)
    for (int i = 0; i < n; ++i) for (int j = i + 1; j < n; ++j) {
        string s; cin >> s;
        for (int k = 0; k < n; ++k) if (s[k] == '1')
            is[i][j][k] = is[j][i][k] = true;
    }
    for (int j = 1; j < n; ++j) {
        // claim : edge(i, j)
        vv <bool> vis(n, n, false);
        vector <pii> edge;
        int cnt = 0;
        edge.eb(0, j), vis[0][j] = vis[j][0] = true, cnt++;
        while (!edge.empty()) {
            int i, j; tie(i, j) = edge.back(); edge.pop_back();
            // j root
            for (int k = 0; k < n; ++k) if (k != i && k != j && is[k][i][j] && !vis[k][j]) {
                vis[k][j] = vis[j][k] = true, cnt++, edge.eb(j, k);
            }
            // i root
            for (int k = 0; k < n; ++k) if (k != i && k != j && is[k][j][i] && !vis[k][i]) {
                vis[k][i] = vis[i][k] = true, cnt++, edge.eb(i, k);
            }
            if (cnt >= n)
                break;
        }
        if (cnt == n - 1) {
            Dsu dsu(n);
            vector <vector <int>> adj(n);
            for (int i = 0; i < n; ++i) for (int j = 0; j < n; ++j) if (vis[i][j]) {
                dsu.Union(i, j), adj[i].pb(j);
            }
            if (dsu.cc == 1) {
                vv <int> dis(n, n, 0);
                function <void(int, int, int)> dfs = [&](int v, int pa, int st) {
                    dis[st][v] = ~pa ? dis[st][pa] + 1 : 0;
                    for (int u : adj[v]) if (u != pa) {
                        dfs(u, v, st);
                    }
                };
                for (int i = 0; i < n; ++i)
                    dfs(i, -1, i);
                bool fail = false;
                for (int i = 0; i < n; ++i) for (int j = i + 1; j < n; ++j) for (int k = 0; k < n; ++k) {
                    if ((dis[i][k] == dis[j][k]) ^ is[i][j][k])
                        fail = true;
                }
                if (!fail) {
                    cout << "YES\n";
                    for (int i = 0; i < n; ++i) for (int j = i + 1; j < n; ++j) if (vis[i][j]) {
                        cout << i + 1 << ' ' << j + 1 << endl;
                    }
                    return;
                }
            }
        }
    }
    cout << "NO\n";
}

int main () {
    owo;
    int t = 1;
    cin >> t;
    while (t--) {
        solve();
    }
}