#include <bits/stdc++.h>
using namespace std;
#define lli long long int
#define fop(i,m,n) for (int i=(m);i<(n);++i)
const int mod = 998244353;

void solve() {
	int n, m, u, v;
	cin >> n >> m;
	vector <int> adj[n];
	fop (i,0,m) {
		cin >> u >> v;
		u--; v--;
		adj[u].push_back(v);
		adj[v].push_back(u);
	}
	vector <bool> vis(n, false);
	vector <int> ans(n);
	bool is = true;
	lli ans1 = 1, ans2 = 1, ans3 = 1;
	function<void(int, int)> dfs = [&](int v, int pa) {
		vis[v] = true;
		ans[v] = ~pa ? ans[pa] ^ 1 : 0;
		ans1 = ans1 * (ans[v] + 1) % mod;
		ans2 = ans2 * (2 - ans[v]) % mod;
		for (int u : adj[v]) {
			if (!vis[u]) {
				dfs(u, v);
			} else {
				if (ans[u] + ans[v] != 1) is = false;
			}
		}
		if (pa == -1) {
			ans3 = ans3 * (ans1 + ans2) % mod;
			ans1 = ans2 = 1;
		}
	};
	
	fop (i,0,n) if (!vis[i]) dfs(i, -1);
	if (!is) ans3 = 0;
	cout << ans3 << '\n';
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