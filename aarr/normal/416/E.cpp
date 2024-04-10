#include <iostream>
using namespace std;

const int N = 505, inf = 1000 * 1000 * 1000 + 7;

long long adj[N][N];
long long dis[N][N];
int cnt[N][N];

int main() {
	int n, m;
	cin >> n >> m;
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j < i; j++) {
			adj[i][j] = inf;
			adj[j][i] = inf;
		}
	}
	for (int i = 0; i < m; i++) {
		int u, v, w;
		cin >> u >> v >> w;
		adj[u][v] = w;
		adj[v][u] = w;
	}
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			dis[i][j] = adj[i][j];
		}
	}
	for (int k = 1; k <= n; k++) {
		for (int i = 1; i <= n; i++) {
			for (int j = 1; j <= n; j++) {
				dis[i][j] = min(dis[i][j], dis[i][k] + dis[k][j]);
			}
		}
	}
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			for (int k = 1; k <= n; k++) {
				if (j != k && dis[i][j] + adj[j][k] == dis[i][k]) {
					cnt[i][k]++;
				}
			}
		//	cout << i << " " << j << " " << adj[i][j] << " " << dis[i][j] << " " << cnt[i][j] << endl;
		}
	}
	for (int i = 1; i <= n; i++) {
		for (int j = i + 1; j <= n; j++) {
			long long ans = 0;
			for (int k = 1; k <= n; k++) {
				if (dis[i][k] + dis[k][j] == dis[i][j]) {
					ans += cnt[i][k];
				}
			}
			if (dis[i][j] == inf) {
				ans = 0;
			}
			cout << ans << " ";
		}
	}
	return 0;
}