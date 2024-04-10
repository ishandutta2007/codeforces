#include <bits/stdc++.h>
using namespace std;
#define lli long long int
#define mp make_pair
#define pb push_back
#define eb emplace_back
#define test(x) cout << #x << ' ' << x << endl;
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
const int mod = 1e9 + 7, abc = 864197532, N = 100087, logN = 17, K = 3e6;

void solve() {
    int n, m;
    cin >> n >> m;
    vector <int> adj[n];
    for (int i = 0, u, v; i < m; ++i) {
        cin >> u >> v, u--, v--;
        adj[u].pb(v);
    }
    queue <int> q;
    vector <int> dis(n, 1 << 30);
    q.push(0);
    dis[0] = 0;
    while (q.size()) {
        int v = q.front(); q.pop();
        for (int u : adj[v]) if (dis[u] == 1 << 30) {
            dis[u] = dis[v] + 1;
            q.push(u);
        }
    }
    vector <vector <int>> dp(n, vector <int>(2, -1));
    dp[0][0] = dp[0][1] = 0;
    function <int(int, int)> solve = [&](int v, int f) {
        if (dp[v][f] != -1) return dp[v][f];
        dp[v][f] = dis[v];
        for (int u : adj[v]) {
            if (dis[v] < dis[u]) dp[v][f] = min(dp[v][f], solve(u, f));
            else if (dis[v] >= dis[u] && f) dp[v][f] = min(dp[v][f], solve(u, 0));
        }
        return dp[v][f];
    };
    for (int i = 0; i < n; ++i) cout << solve(i, 1) << " \n"[i == n - 1];
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