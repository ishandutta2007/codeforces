#include <bits/stdc++.h>
using namespace std;
#define ll long long int
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
const int mod = 998244353, N = 1 << 20, K = 250;

void solve() {
    int n, m;
    cin >> n >> m;
    vector <vector <int>> adj(n);
    for (int i = 0, u, v; i < m; ++i) {
        cin >> u >> v, --u, --v;
        adj[u].pb(v), adj[v].pb(u);
    }
    int f; cin >> f;
    vector <int> h(f);
    for (int i = 0; i < f; ++i)
        cin >> h[i], --h[i];
    vector <int> imp(n, 0);
    vector <bool> is(f, false);
    int k; cin >> k;
    for (int i = 0, x; i < k; ++i)
        cin >> x, --x, is[x] = true, imp[h[x]] |= 1 << i;
    vv <bool> vis(n, 1 << k, false);
    vector <int> dis(n, -1);
    queue <pii> q;
    q.emplace(0, 0), vis[0][0] = true, dis[0] = 0;
    while (!q.empty()) {
        int v, msk; tie(v, msk) = q.front(); q.pop();
        for (int u : adj[v]) if (dis[u] == -1 || dis[u] == dis[v] + 1) {
            dis[u] = dis[v] + 1;
            int nxtmsk = msk | imp[u];
            if (!vis[u][nxtmsk]) {
                vis[u][nxtmsk] = true, q.emplace(u, nxtmsk);
            }
        }
    }
    for (int i = 0; i < n; ++i) {
        for (int s = (1 << k) - 1; s; --s) if (vis[i][s]) {
            for (int j = 0; j < k; ++j) if (s >> j & 1)
                vis[i][s ^ (1 << j)] = true;
        }
    }
    vv <bool> dp(f + 1, 1 << k, false);
    dp[0][0] = true;
    int full = (1 << k) - 1;
    for (int i = 0; i < f; ++i) for (int s = 0; s < 1 << k; ++s) if (dp[i][s]) {
        if (!is[i]) {
            for (int t = full ^ s; t; t = (t - 1) & (full ^ s)) if (vis[h[i]][t]) {
                dp[i + 1][s | t] = true;
            }
        }
        dp[i + 1][s] = true;
    }
    int ans = 1 << 30;
    for (int i = 0; i < 1 << k; ++i) if (dp[f][i])
        ans = min(ans, k - __builtin_popcount(i));
    cout << ans << '\n';
}

int main() {
    owo;
    int t = 1;
    cin >> t;
    while (t--) {
        solve();
    }
}