#include <iostream>
using namespace std;

const int N = 22;

//int adj[N + 3];
//int adj2[N + 3];
int dp[(1 << (N - 1))][N];
int adj[N];

int get(int x, int y) {
	return (x >> y) & 1;
}
int main() {
	int n, m;
	cin >> n >> m;
	for (int i = 0; i < m; i++) {
		int u, v;
		cin >> u >> v;
		u--;
		v--;
		dp[0][u] += 1 << v;
		dp[0][v] += 1 << u;
	}
	if (m == n * (n - 1) / 2) {
		cout << 0 << endl;
		return 0;
	}
	for (int i = 0; i < n; i++) {
		dp[0][i] += 1 << i;
	}
	int ans = (1 << n) - 1;
	for (int mask = 1; mask < (1 << n); mask++) {
		if (__builtin_popcount(mask) >= __builtin_popcount(ans))
			continue;
		int u = __builtin_ctz(mask);
		int mask2 = mask ^ (1 << u);
		mask2 = mask2 >> 1;
	//	cout << mask << " " << mask2 << endl;
		for (int i = 0; i < n; i++) {
			adj[i] = dp[mask2][i];
		}
		for (int i = 0; i < n; i++) {
			if (get(adj[u], i)) {
				adj[i] |= adj[u];
			}
		}
		bool b = true;
		for (int i = 0; i < n; i++) {
			if (adj[i] != (1 << n) - 1)
				b = false;
		}
		if (b)
			ans = mask;	
	//	cout << mask << " " << b << endl;
		if (!get(mask, 0)) {
			for (int i = 0; i < n; i++) {
				dp[mask >> 1][i] = adj[i];
			}
		}
	}
//	for (int i = 0; i < n; i++) {
//		cout << dp[1][i] << endl;
//	}
	cout << __builtin_popcount(ans) << endl;
	for (int i = 0; i < n; i++) {
		if (get(ans, i)) {
			cout << i + 1 << " ";
		}
	}
	return 0;
}