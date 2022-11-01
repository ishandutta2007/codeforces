#include <iostream>
#include <vector>
#define int long long
using namespace std;

const int N = 5005, W = 1000 * 1000 + 5;
int n, ans, t1, t2, x1, x2, maxi;

int par[N];
int sz[N];
int dp1[N];
int dp2[N];
int s[N];
bool mark[N];
vector <pair <int, int> > adj[N];

void dfs2(int v) {
	mark[v] = true;
	s[v] = 1;
	for (auto p : adj[v]) {
		int u = p.first, w = p.second;
		if (u != t1 && u != t2 && !mark[u]) {
			dfs2(u);
			s[v] += s[u];
			dp1[v] += dp1[u] + 1ll * s[u] * w;
		}
	}
}
void dfs3(int v, int &mini, int x) {
	mark[v] = true;
	for (auto p : adj[v]) {
		int u = p.first, w = p.second;
		if (!mark[u] && u != t1 && u != t2) {
			dp2[u] = dp2[v];
			dp2[u] -= s[u] * w;
			dp2[u] += (x - s[u]) * w;
		//	cout << "47 " << v << " " << u << " " << s[u] << " " << dp2[v] << " " << dp2[u] << endl;
			dfs3(u, mini, x);
		}
	}
//	cout << "48 " << v << " " << x << " " << s[v] << " " << dp1[v] << " " << dp2[v] << endl;
	mini = min(mini, dp2[v]);
}
void dfs1(int v) {
//	cout << "71 " << v << endl;
	sz[v] = 1;
	for (auto p : adj[v]) {
		int u = p.first, w = p.second;
		if (u != par[v]) {
			par[u] = v;
			dfs1(u);
			sz[v] += sz[u];
			fill(mark + 1, mark + n + 1, false);
			fill(dp1 + 1, dp1 + n + 1, 0);
			fill(s + 1, s + n + 1, 0);
			ans += 1ll * sz[u] * (n - sz[u]) * w;
			t1 = u, t2 = v;
			long long min1 = 1ll * N * N * W, min2 = N * N * W;
			x1 = sz[u], x2 = n - sz[u];
			dfs2(u);
			dfs2(v);
			fill(mark + 1, mark + n + 1, false);
			fill(dp2, dp2 + n + 1, 0);
			dp2[v] = dp1[v];
			dp2[u] = dp1[u];
			dfs3(u, min1, x1);
			dfs3(v, min2, x2);
		//	cout << v << " " << u << " " << w << " " << min1 << " " << min2 << " " << dp2[u] << " " << dp2[v] << endl;
			maxi = max(maxi, 1ll * (dp2[u] - min1) * x2 + 1ll * (dp2[v] - min2) * x1);
		}
	}
}
int32_t main() {
	cin >> n;
	for (int i = 1; i < n; i++) {
		int u, v, w;
		cin >> u >> v >> w;
		adj[u].push_back({v, w});
		adj[v].push_back({u, w});
	}
	dfs1(1);
//	cout << ans << " " << maxi << endl;
	cout << ans - maxi;
	return 0;
}