#include <bits/stdc++.h>
using namespace std;
#define lli long long int
#define mp make_pair
#define pb push_back
#define eb emplace_back
#define test(x) cout << "Line(" << __LINE__ << ") " #x << ' ' << x << endl
#define printv(x) {\
	for (auto i : x) cout << i << ' ';\
	cout << endl;\
}
#define pii pair <int, int>
#define pll pair <lli, lli>
#define X first
#define Y second
#define all(x) x.begin(), x.end()
#define rall(x) x.rbegin(), x.rend()
template<typename A, typename B>
ostream& operator << (ostream& o, pair<A, B> a){
    return o << a.X << ' ' << a.Y;
}
template<typename A, typename B>
istream& operator >> (istream& o, pair<A, B> &a){
    return o >> a.X >> a.Y;
}
const int mod = 1e9 + 7, abc = 864197532, N = 3000005, logN = 20, K = 333;

void solve() {
    int n;
    cin >> n;
    vector <vector <int>> adj(n);
    vector <int> a(n), d(n, -1), val(n), rt(n), mn, mx;
    vector <lli> dp(n, 0);
    vector <vector <int>> level;
    for (int i = 1, x; i < n; ++i) {
        cin >> x, --x;
        adj[i].pb(x);
        adj[x].pb(i);
    }
    for (int i = 1; i < n; ++i) cin >> a[i];
    queue <int> q;
    q.push(0);
    d[0] = 0;
    while (!q.empty()) {
        int v = q.front(); q.pop();
        if (level.size() == d[v]) level.pb({}), mn.pb(1 << 30), mx.pb(0);
        level[d[v]].pb(v);
        mn[d[v]] = min(mn[d[v]], a[v]);
        mx[d[v]] = max(mx[d[v]], a[v]);
        for (int u : adj[v]) if (!~d[u]) {
            q.push(u);
            rt[u] = v;
            d[u] = d[v] + 1;
        }
    }
    for (int i = 0; i < n; ++i) {
        val[i] = max(a[i] - mn[d[i]], mx[d[i]] - a[i]);
    }
    int D = level.size() - 1;
    for (int i = 0; i < D; ++i) {
        for (int v : level[i + 1]) {
            dp[v] = dp[rt[v]] + val[v];
        }
        int m = level[i + 1].size();
        lli pre1 = -1ll << 60, pre2 = -1ll << 60;
        for (int j = 0; j < m; ++j) {
            int v = level[i + 1][j];
            pre1 = max(pre1, dp[v] - a[v] - val[v]);
            pre2 = max(pre2, dp[v] + a[v] - val[v]);
        }
        for (int j = 0; j < m; ++j) {
            int v = level[i + 1][j];
            dp[v] = max({dp[v], pre1 + a[v], pre2 - a[v]});
        }
    }
    lli ans = 0;
    for (int i = 0; i < n; ++i) if (d[i] == D) ans = max(ans, dp[i]);
    cout << ans << '\n';
}

int main () {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int t;
    cin >> t;
    while (t--) {
        solve();
    }
}