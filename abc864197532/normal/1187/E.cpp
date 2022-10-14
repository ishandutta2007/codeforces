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
const int mod = 1e9 + 7, abc = 864197532, N = 200001, logN = 17;

vector <int> adj[N];
lli dp[N], sz[N], ans[N];

void dfs1(int v, int pa) {
    sz[v] = 1;
    dp[v] = 0;
    for (int u : adj[v]) if (u != pa) {
        dfs1(u, v);
        sz[v] += sz[u];
        dp[v] += dp[u];
    }
    dp[v] += sz[v];
}

void dfs2(int v, int pa, int n) {
    ans[v] = dp[v] - sz[v];
    if (~pa) {
        ans[v] += ans[pa] + n - sz[v];
    }
    for (int u : adj[v]) if (u != pa) {
        ans[v] -= dp[u];
        dfs2(u, v, n);
        ans[v] += dp[u];
    }
}

int main () {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n;
    cin >> n;
    for (int i = 0, u, v; i < n - 1; ++i) {
        cin >> u >> v, u--, v--;
        adj[u].pb(v);
        adj[v].pb(u);
    }
    dfs1(0, -1);
    dfs2(0, -1, n);
    cout << *max_element(ans, ans + n) + n << endl;
}