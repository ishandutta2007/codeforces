#include <iostream>
using namespace std;

const int N = 1005, mod = 1000 * 1000 * 1000 + 7;

long long dp[N][N];


int main() {
	int n, m, x;
	cin >> n >> m >> x;
	if (n > m) {
		cout << 0;
		return 0;
	}
	dp[0][0] = 1;
	for (int i = 1; i <= m; i++) {
		for (int j = n; j >= 0; j--) {
			for (int k = j; k >= 0; k--) {
				if (i == x) {
					dp[j][k] = 0;
				}
				if (j > k) {
					dp[j][k] += dp[j - 1][k];
				}
				
				if (k > 0 && i != x) {
					dp[j][k] += dp[j][k - 1];
				}
				if (k > 0) {
					dp[j][k] += dp[j - 1][k - 1];
				}
				dp[j][k] %= mod;
			//	cout << "73 " << i << " " << j << " " << k << " " << dp[j][k] << endl;
			}
		}
	}
	long long ans = dp[n][n];
//	cout << ans << endl;
	for (int i = 1; i <= n; i++) {
		ans *= i;
		ans %= mod;
	}
	cout << ans;
	return 0;
}