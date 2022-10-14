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
const int mod = 1e9 + 7, N = 2520, logN = 20;

int main () {
    owo;
    int t;
    cin >> t;
    while (t--) {
        int n, m;
        cin >> n >> m;
        vector <lli> a(n);
        vector <vector <int>> adj(n);
        for (int i = 0; i < n; ++i) cin >> a[i];
        for (int i = 0, x; i < n; ++i) cin >> x, a[i] -= x;
        for (int i = 0, u, v; i < m; ++i) {
            cin >> u >> v, --u, --v;
            adj[u].pb(v);
            adj[v].pb(u);
        }
        vector <int> vis(n, 0);
        bool cyc = false;
        function<void(int, int)> dfs = [&](int v, int pa) {
            for (int u : adj[v]) if (u != pa) {
                if (!vis[u]) vis[u] = 3 - vis[v], dfs(u, v);
                else if (vis[v] == vis[u]) cyc = true;
            }
        };
        bool ans = true;
        vis[0] = 1;
        dfs(0, -1);
        lli dis = 0;
        for (int i = 0; i < n; ++i) {
            if (vis[i] == 1) dis += a[i];
            else dis -= a[i];
        }
        if (cyc) {
            if (dis & 1) ans = false;
        } else {
            if (dis) ans = false;
        }
        cout << (ans ? "YES\n" : "NO\n");
    }
}