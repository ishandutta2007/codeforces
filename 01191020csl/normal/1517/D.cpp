#include<bits/stdc++.h>
using namespace std;
int ans[11][501][501];
int val[501][501][4];
const int dir[4][2] = {{0,1},{1,0},{0,-1},{-1,0}};
int main() {
	int n, m, k;
	cin >> n >> m >> k;
	if (k & 1) {
		for (int i = 1; i <= n; i++) {
			for (int j = 1; j <= m; j++)
				cout << -1 << ' ';
			cout << endl;
		}
		return 0;
	}
	memset(val, 0x3f, sizeof(val));
	for (int i = 1; i <= n; i++)
		for (int j = 1; j < m; j++) {
			int w;
			cin >> w;
			val[i][j][0] = val[i][j+1][2] = w;
		}
	for (int i = 1; i < n; i++)
		for (int j = 1; j <= m; j++) {
			int w;
			cin >> w;
			val[i][j][1] = val[i+1][j][3] = w;
		}
	memset(ans, 0x3f, sizeof(ans));
	for (int i = 1; i <= n; i++)
		for (int j = 1; j <= m; j++)
			ans[0][i][j] = 0;
	for (int t = 1; t <= k/2; t++)
		for (int i = 1; i <= n; i++)
			for (int j = 1; j <= m; j++)
				for (int u = 0; u < 4; u++) {
					if (val[i][j][u] >= 0x3f3f3f3f) continue;
					ans[t][i][j] = min(ans[t][i][j], ans[t-1][i+dir[u][0]][j+dir[u][1]]+val[i][j][u]);
				}
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= m; j++)
			cout << ans[k/2][i][j]*2 << ' ';
		cout << endl;
	}
}