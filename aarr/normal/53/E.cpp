#include <iostream>
#include <vector>
#include <queue>
using namespace std;

const int N = 10;

bool adj[N][N];
pair <int, int> inc[N * N];
long long dp[1 << N][1 << N];

int get(int x, int y) {
	return (x >> y) & 1;
}
int main() {
	int n, m, k;
	long long ans = 0;
	cin >> n >> m >> k;
	for (int i = 0; i < m; i++) {
		int u, v;
		cin >> u >> v;
		adj[--u][--v] = true;
		adj[v][u] = true;
		inc[i] = {u, v};
	}
	dp[0][0] = 1;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < i; j++) {
			if (adj[i][j]) {
				dp[(1 << i) + (1 << j)][0] = 1;
			}
		}
	}
	for (int mask1 = 1; mask1 < 1 << n; mask1++) {
		for (int mask2 = 0; mask2 < 1 << n; mask2++) {
			bool b = true;
			for (int i = 0; i < n; i++) {
				if (get(mask2, i) && !get(mask1, i)) {
					b = false;
				}
			}
			if (b) {
				for (int i = 0; i < n; i++) {
					if (get(mask1, i) && !get(mask2, i)) {
						for (int j = 0; j < n; j++) {
							if (get(mask1, j) && get(mask2, j) && adj[i][j]) {
								int mask3 = mask1 - (1 << i);
								int mask4 = mask2 - (1 << j);
							//	cout << mask1 << " " << mask2 << " " << mask3 << " " << mask4 << endl; 
								dp[mask1][mask2] += dp[mask3][mask2];
								dp[mask1][mask2] += dp[mask3][mask4];
							}
						}
						break;
					}
				}
			}
		//	cout << mask1 << " " << mask2 << " " << dp[mask1][mask2] << endl;
		}
	}
	for (int mask2 = 0; mask2 < 1 << n; mask2++) {
		if (__builtin_popcount(mask2) == n - k) {
			ans += dp[(1 << n) - 1][mask2];
		}
	}
	cout << ans << endl;
	return 0;
	
}