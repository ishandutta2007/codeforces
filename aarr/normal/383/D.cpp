#include <iostream>
using namespace std;

const int N = 1005, S = 10 * 1000 + 5, mod = 1000 * 1000 * 1000 + 7;

int a[N];
int dp[N][S * 2];

int main() {
	int n, ans = 0;
	cin >> n;
	dp[0][S] = 1;
	for (int i = 1; i <= n; i++) {
		cin >> a[i];
	//	for (int j = 0; j < S * 2; j++) {
	//		dp[i][j] += dp[i - 1][j];
	//	}
		for (int j = a[i]; j < S * 2; j++) {
			dp[i][j] += dp[i - 1][j - a[i]];
			dp[i][j] %= mod;
		}
		for (int j = S * 2 - a[i] - 1; j >= 0; j--) {
			dp[i][j] += dp[i - 1][j + a[i]];
			dp[i][j] %= mod;
		}
	//	for (int j = 0; j < S * 2; j++) {
	//		cout << i << " " << j << " " << dp[i][j] << endl;
	//	}
		ans += dp[i][S];
		ans %= mod;
		dp[i][S]++;
	}
	cout << ans << endl;
	
	return 0;
}