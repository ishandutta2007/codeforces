#include <iostream>
#include <vector>
using namespace std;

const int N = 20;

vector <int> adj[N];
long long dp[1 << N][N];
bool mark[N][N];

int get(int x, int y) {
	return (x >> y) & 1;
}

int main() {
	int n, m;
	cin >> n >> m;
	for (int i = 0; i < m; i++) {
		int u, v;
		cin >> u >> v;
		if (u > v) {
			swap(u, v);
		}
		adj[u].push_back(v);
		adj[v].push_back(u);
		dp[1 << (u - 1)][v]++;
		mark[u][v] = true;
	}
	for (int i = 1; i <= n; i++) {
		dp[0][i] = 1;
	}
	long long ans = 0;
	for (int mask = 1; mask < 1 << n; mask++) {
		int v = __builtin_ctz(mask) + 1;
		for (int i = 1; i <= n; i++) {
			if (!get(mask, i - 1) && v < i) {
				for (auto u : adj[i]) {
					if (get(mask, u - 1) && u != i && u != v) {
						dp[mask][i] += dp[mask ^ (1 << (u - 1))][u];
					}
				}
			//	cout << mask << " " << i << " " << dp[mask][i] << endl;
				if (__builtin_popcount(mask) > 1 && mark[v][i]) {
			//		cout << "73 " << endl;
					ans += dp[mask][i];
				}
			}

		}
	}
	cout << ans / 2 << endl;
	return 0;
}