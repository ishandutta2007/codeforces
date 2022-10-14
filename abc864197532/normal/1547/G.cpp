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
const int mod = 998244353, N = 1000001, logC = 30, logN = 19, K = 111, M = 4e6;

vector <int> adj[N], radj[N];
int scc[N], _id = 0;
bool vis[N];
vector <int> order;

void rdfs(int v) {
    vis[v] = true;
    for (int u : radj[v]) if (!vis[u]) {
        rdfs(u);
    }
    order.push_back(v);
}

void dfs(int v) {
    scc[v] = _id;
    for (int u : adj[v]) if (scc[u] == -1) {
        dfs(u);
    }
}

void build(int n) {
    _id = 0;
    order.clear();
    for (int i = 0; i < n; ++i) {
        vis[i] = false;
        scc[i] = -1;
    }
    for (int i = 0; i < n; ++i) if (!vis[i]) {
        rdfs(i);
    }
    reverse(order.begin(), order.end());
    for (int v : order) {
        if (scc[v] == -1) {
            dfs(v);
            _id++;
        }
    }
}

int main () {
    owo;
    int t;
    cin >> t;
    while (t--) {
        int n, m;
        cin >> n >> m;
        vector <bool> tag(n, false), tag2(n, false);
        for (int i = 0, u, v; i < m; ++i) {
            cin >> u >> v, --u, --v;
            if (u == v) tag[u] = true;
            else {
                adj[u].pb(v);
                radj[v].pb(u);
            }
        }
        build(n);
        vector <vector <int>> adj2(n);
        for (int i = 0; i < n; ++i) for (int j : adj[i]) {
            if (scc[i] == scc[j]) tag2[scc[i]] = true;
            else {
                adj2[scc[i]].pb(scc[j]);
            }
        }
        for (int i = 0; i < n; ++i) if (tag[i]) tag2[scc[i]] = true;
        vector <int> ans(n, 0);
        vector <bool> vis(n, false);
        ans[scc[0]] = 1;
        vis[scc[0]] = true;
        for (int v = _id - 1; ~v; --v) {
            if (!vis[v]) continue;
            if (tag2[v]) ans[v] = -1;
            for (int u : adj2[v]) {
                vis[u] = true;
                if (tag2[v]) tag2[u] = true;
                else ans[u] = min(ans[u] + ans[v], 2);
            }
        }
        for (int i = 0; i < n; ++i) cout << ans[scc[i]] << " \n"[i == n - 1], adj[i].clear(), radj[i].clear();
    }
}