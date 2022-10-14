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
    vector <vector <int>> adj(n);
    vector <int> d(n);
    for (int i = 0, u, v; i < m; ++i) {
        cin >> u >> v, u--, v--;
        adj[u].pb(v);
        adj[v].pb(u);
        d[u]++, d[v]++;
    }
    vector <bool> vis(n, false);
    vector <int> dep(n, 0);
    vector <int> mark(n, false);
    vector <int> ans;
    function <void(int, int)> dfs = [&](int v, int pa) {
        vis[v] = true;
        bool is = true;
        for (int u : adj[v]) is &= !mark[u];
        if (is) mark[v] = true, ans.pb(v + 1);
        for (int u : adj[v]) if (!vis[u]) {
            dfs(u, v);
        }
    };
    dfs(0, -1);
    if (accumulate(all(vis), 0) != n) {
        cout << "NO\n";
        return;
    }
    cout << "YES\n";
    cout << ans.size() << endl;
    printv(ans);
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