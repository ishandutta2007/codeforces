#include <iostream>
using namespace std;

const int N = 105, K = 15, mod = 100 * 1000 * 1000;

int dp[N][N][K][3];

int main() {
	int n1, n2, k1, k2;
	cin >> n1 >> n2 >> k1 >> k2;
	dp[1][1][0][0] = 1;
	for (int i = 1; i <= n1 + 1; i++) {
		for (int j = 1; j <= n2 + 1; j++) {
			if (i > 0) {
				for (int k = 1; k <= k1; k++) {
					dp[i][j][k][0] += dp[i - 1][j][k - 1][0];
					dp[i][j][1][1] += dp[i][j - 1][k - 1][0];
					dp[i][j][k][0] %= mod;
					dp[i][j][1][1] %= mod;
				}
				dp[i][j][1][1] += dp[i][j - 1][k1][0];
			}
			if (j > 0) {
				for (int k = 1; k <= k2; k++) {
					dp[i][j][1][0] += dp[i - 1][j][k - 1][1];
					dp[i][j][1][0] %= mod;
					dp[i][j][k][1] += dp[i][j - 1][k - 1][1];
					dp[i][j][k][1] %= mod;
				}
				dp[i][j][1][0] += dp[i - 1][j][k2][1];
			}

		//	for (int k = 0; k <= k2; k++) {
		//		cout << i << " " << j << " " << k << " " << dp[i][j][k][1] << endl;
		//	}
		}
	}
	int ans = 0;
	for (int k = 0; k <= k1; k++) {
		ans += dp[n1 + 1][n2 + 1][k][0];
	}
	for (int k = 0; k <= k2; k++) {
		ans += dp[n1 + 1][n2 + 1][k][1];
	}
	cout << ans % mod << endl;
	return 0;
}