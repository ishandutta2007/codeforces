#include<bits/stdc++.h>
using namespace std;

const int N = 80;

int n, m, k;
int a[N][N];
int dp[N][N][N];
int f[N][N];
int ans[N][N];

int main() {
	ios::sync_with_stdio(false); cin.tie(0);

	cin >> n >> m >> k;

	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= m; j++)
			cin >> a[i][j];
	}

	for (int rep = 1; rep <= n; rep++) {

		for (int i = 0; i < k; i++)
			f[rep][i] = -1e9;

		for (int i = 0; i <= m; i++)
			for (int j = 0; j <= m / 2; j++)
				for (int jj = 0; jj < k; jj++)
					dp[i][j][jj] = -1e9;

		dp[0][0][0] = 0;
		for (int i = 1; i <= m; i++) {
			for (int j = 0; j <= m / 2; j++) {
				for (int r = 0; r < k; r++) {
					dp[i][j][r] = dp[i - 1][j][r];
					// if (i == 3 && j == 2 && r == 2)
					// 	cout << a[rep][i] << endl;
					if (j != 0) {
						dp[i][j][r] = max(dp[i][j][r], dp[i - 1][j - 1][(r - a[rep][i] % k + k) % k] + a[rep][i]);
					}
					f[rep][r] = max(f[rep][r], dp[i][j][r]);
				}
			}
		}
	}

	// cout << dp[4][2][0] << endl;

	for (int i = 0; i <= n; i++) {
		for (int j = 0; j < k; j++)
			ans[i][j] = -1e9;
	}
	ans[0][0] = 0;
	for (int i = 1; i <= n; i++) {
		for (int j = 0; j < k; j++) {
			ans[i][j] = ans[i - 1][j];
			for (int r = 0; r < k; r++) {
				ans[i][j] = max(ans[i][j], ans[i - 1][(j - r + k) % k] + f[i][r]);
			}
		}
	}

	cout << ans[n][0] << endl;

	return 0;
}