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
const int mod = 998244353, N = 2000001, logN = 20, K = 111;

int main () {
    owo;
    int n;
    cin >> n;
    vector <int> v, a(n), b(n);
    for (int i = 0; i < n; ++i) cin >> a[i] >> b[i], v.pb(a[i]), v.pb(b[i]);
    sort(all(v));
    v.resize(unique(all(v)) - v.begin());
    int m = v.size();
    vector <vector <int>> adj(m);
    for (int i = 0; i < n; ++i) {
        int x = lower_bound(all(v), a[i]) - v.begin();
        int y = lower_bound(all(v), b[i]) - v.begin();
        adj[x].pb(y), adj[y].pb(x);
    }
    int num, e, mx, smx;
    vector <bool> vis(m, false);
    function<void(int)> dfs = [&](int v) {
        num++;
        e += adj[v].size();
        vis[v] = true;
        if (mx < v) smx = mx, mx = v;
        else if (smx < v) smx = v;
        for (int u : adj[v]) if (!vis[u]) {
            dfs(u);
        }
    };
    int ans = 0;
    for (int i = 0; i < m; ++i) if (!vis[i]) {
        num = e = 0, mx = smx = -1;
        dfs(i);
        e >>= 1;
        if (num < e) {
            cout << -1 << endl;
            return 0;
        } else if (num == e) {
            ans = max(ans, mx);
        } else if (num == e + 1) {
            ans = max(ans, smx);
        }
    }
    cout << v[ans] << endl;
}