#include <bits/stdc++.h>
using namespace std;

const int N = 1505, mod = 1000 * 1000 * 1000 + 7;

int dp[N][N];

int main() {
	ios :: sync_with_stdio(false);
	int n, m;
	cin >> n >> m;
	dp[0][0] = 1;
	for (int i = 1; i <= n + 2 * m; i++) {
		for (int j = 0; j <= 2 * m; j++) {
			dp[i][j] = dp[i - 1][j];
			if (j > 0) {
				dp[i][j] += dp[i - 1][j - 1];
				dp[i][j] %= mod;
			}
		}
	}
	cout << dp[n + 2 * m - 1][2 * m] << endl;
	return 0;
}