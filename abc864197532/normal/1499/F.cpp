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
const int mod = 998244353, N = 5001, logC = 30, logN = 19, K = 111, M = 4e6;

vector <int> dp[N];
vector <int> adj[N];
int sum[N], k;

void add(int &i, int j) {
    i += j;
    if (i >= mod) i -= mod;
}

void dfs(int v, int pa) {
    dp[v].pb(1);
    for (int u : adj[v]) if (u != pa) {
        dfs(u, v);
        vector <int> cur = dp[v];
        for (int &i : cur) i = 1ll * i * sum[u] % mod;
        while (cur.size() < dp[u].size() + 1) cur.pb(0);
        for (int i = 0; i < dp[v].size(); ++i) {
            for (int j = 0; j < dp[u].size(); ++j) {
                if (i + j + 1 <= k) add(cur[max(i, j + 1)], 1ll * dp[v][i] * dp[u][j] % mod);
            }
        }
        dp[v] = cur;
    }
    for (int i : dp[v]) add(sum[v], i);
}

int main () {
    owo;
    int n;
    cin >> n >> k;
    for (int i = 0, u, v; i < n - 1; ++i) {
        cin >> u >> v, --u, --v;
        adj[u].pb(v);
        adj[v].pb(u);
    }
    dfs(0, -1);
    cout << sum[0] << endl;
}