#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

const int N = 55, C = 1005;

int dis[N][N];
long long dp[N][N][N];
bool mark[N];
vector <pair <int, int> > vec[N];



int main() {
	int n, m, g1, g2, s1, s2;
	cin >> n >> m; 
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			if (i != j) {
				dis[i][j] = N * C;
			}
		}
	}
	for (int i = 0; i < m; i++) {
		int u, v, w;
		cin >> u >> v >> w;
		dis[u][v] = min(dis[u][v], w);
		dis[v][u] = min(dis[v][u], w);
	}
	cin >> g1 >> g2 >> s1 >> s2;
	for (int k = 1; k <= n; k++) {
		for (int i = 1; i <= n; i++) {
			for (int j = 1; j <= n; j++) {
				dis[i][j] = min(dis[i][j], dis[i][k] + dis[k][j]);
			}
		}
	}
/*	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			cout << dis[i][j] << " ";
		}
		cout << endl;
	}*/
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			if (i != j)
				vec[i].push_back({dis[i][j], i});
		}
		sort(vec[i].begin(), vec[i].end());
	}
	long long ans = 0;
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			if (i != j) {
				if (vec[i][0] < vec[j].back()) {
				//	cout << 31 << endl;
					for (int x = 0; x <= n; x++) {
						for (int y = 0; y <= n; y++) {
							for (int z = 0; z <= n; z++) {
								dp[x][y][z] = 0;
							}
						}
					}
					fill(mark, mark + n + 1, false);
					for (int x = 1; x <= n; x++) {
						for (int k = 0; k < n - 1; k++) {
							if (vec[x][k] > vec[i][0] && vec[x][k] < vec[j].back()) {
								mark[x] = true;
							}
						}
					//	cout << "32 " << mark[x] << endl;
					}
					dp[0][0][0] = 1;
					for (int x = 0; x <= n; x++) {
						for (int y = 0; y <= n; y++) {
							for (int z = 0; z <= n; z++) {
								int s = x + y + z;
								if (s > n || s == 0) {
									continue;
								}
								if (s == i) {
									if (x)
										dp[x][y][z] = dp[x - 1][y][z];
									continue;
								}
								if (s == j) {
									if (z)
										dp[x][y][z] = dp[x][y][z - 1];
									continue;
								}
								if (vec[s][0] <= vec[i][0] && x) {
									dp[x][y][z] += dp[x - 1][y][z];
								}
								if (vec[s].back() >= vec[j].back() && z) {
									dp[x][y][z] += dp[x][y][z - 1];
								//	dp[x][y][z] %= mod;
								}
								if (mark[s] && y) {
									dp[x][y][z] += dp[x][y - 1][z];
								//	dp[x][y][z] %= mod;
								}
							}
						}
					}
				//	cout << "35 " << dp[1][1][1] << endl;
					for (int x = 0; x <= n; x++) {
						for (int y = 0; y <= n; y++) {
							for (int z = 0; z <= n; z++) {
							//	cout << "37 " << x << " " << y << " " << z << " " << dp[x][y][z] << endl;
								if (x + y + z == n && g1 <= x && x <= g2 && s1 <= y && y <= s2) {
									ans += dp[x][y][z];
								//	ans %= mod;
								}
							}
						}
					}
				}
			}
		}
	}
	cout << ans;
	return 0;
}