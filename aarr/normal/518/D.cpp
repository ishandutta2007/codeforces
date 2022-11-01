#include <iostream>
using namespace std;

const int N = 2005;

double dp[N][N];
int main() {
	int n, t;
	double p;
	cin >> n >> p >> t;
	dp[0][0] = 1;
	for (int i = 0; i <= n; i++) {
		for (int j = 1; j <= t; j++) {
			dp[i][j] = (1 - p) * dp[i][j - 1];
			if (i > 0) {
				dp[i][j] += p * dp[i - 1][j - 1];
			}
			if (i == n) {
				dp[i][j] += p * dp[n][j - 1];
			}
		}
	}
	long double ans = 0;
	for (int i = 0; i <= n; i++) {
		ans += dp[i][t] * i;
	}
	cout << fixed;
	cout << ans;
	return 0;
}