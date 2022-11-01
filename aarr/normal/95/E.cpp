#include <iostream>
#include <vector>
using namespace std;

const int N = 100 * 1000 + 5, LG = 18;
int nparts = 1;

int part[N];
int a[N];
int cnt[N];
int dp[N];
vector <int> adj[N];
bool lucky(int x) {
	while (x > 0) {
		int y = x % 10;
		if (y != 4 && y != 7) {
			return false;
		}
		x /= 10;
	}
	return true;
}
void dfs(int v) {
	for (auto u : adj[v]) {
		if (!part[u]) {
			part[u] = part[v];
			dfs(u);
		}
	}
}
int get(int x, int y) {
	return (x >> y) & 1;
}
int main() {
	int n, m;
	cin >> n >> m;
	for (int i = 0; i < m; i++) {
		int u, v;
		cin >> u >> v;
		adj[u].push_back(v);
		adj[v].push_back(u);
	}
	for (int i = 1; i <= n; i++) {
		if (!part[i]) {
			part[i] = nparts;
			dfs(i);
			nparts++;
		}
	}
	for (int i = 1; i <= n; i++) {
		a[part[i]]++;
	}
	for (int i = 1; i < nparts; i++) {
		cnt[a[i]]++;
	}
//	for (int i = 1; i <= n; i++) {
//		cout << i << " " << cnt[i] << endl;
//	}
	for (int i = 1; i <= n; i++) {
		dp[i] = N;
	}
	for (int i = 1; i <= n; i++) {
		for (int j = 0; j < LG; j++) {
			if (cnt[i] >= (1 << j)) {
				int x = 1 << j;
			//	cout << "73 " << i << " " << j << endl;
				for (int k = n; k >= x * i; k--) {
					dp[k] = min(dp[k], dp[k - x * i] + x);
				}
				cnt[i] -= x;
			}
		}
		if (cnt[i] > 0) {
			int x = cnt[i];
			cnt[i] = 0;
			for (int k = n; k >= x * i; k--) {
				dp[k] = min(dp[k], dp[k - x * i] + x);
			}
		}
	}
//	for (int i = 1; i <= n; i++) {
//		cout << "49 " << i << " " << dp[i] << endl;
//	}
	int ans = N;
	for (int i = 1; i <= n; i++) {
		if (lucky(i)) {
			ans = min(ans, dp[i]);
		}
	}
	if (ans == N) {
		cout << -1;
	}
	else {
		cout << ans - 1 << endl;
	}
	return 0;
}