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
const int mod = 1e9 + 7, abc = 864197532, N = 100007, logN = 17;

vector <int> adj[N];
int a[N];
bool vis[N];
int mn;

void dfs(int v) {
    vis[v] = true;
    mn = min(mn, a[v]);
    for (int u : adj[v]) if (!vis[u]) {
        dfs(u);
    }
}

int main () {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n, m;
    cin >> n >> m;
    for (int i = 0; i < n; ++i) cin >> a[i];
    for (int i = 0, u, v; i < m; ++i) {
        cin >> u >> v, u--, v--;
        adj[u].pb(v);
        adj[v].pb(u);
    }
    lli ans = 0;
    for (int i = 0; i < n; ++i) if (!vis[i]) mn = 1 << 30, dfs(i), ans += mn;
    cout << ans << endl;
}