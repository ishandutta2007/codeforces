#include <iostream>
using namespace std;

const int N = 205, A = 28;

int dp[N][N * A];
int b[N];
int c[N];

int main() {
	int n, k;
	cin >> n >> k;
	for (int i = 1; i <= n; i++) {
		long long x;
		cin >> x;
		while (x % 5 == 0) {
			x /= 5;
			b[i]++;
		}
		while (x % 2 == 0) {
			x /= 2;
			c[i]++;
		}
	}
	dp[0][0] = 0;
	for (int j = 0; j <= n; j++) {
		for (int q = 1; q <= n * 70; q++) {
			dp[j][q] = -n * 70;
		}
	}
	for (int i = 1; i <= n; i++) {
		for (int j = n; j; j--) {
			for (int q = b[i]; q <= n * A; q++) {
				dp[j][q] = max(dp[j][q], dp[j - 1][q - b[i]] + c[i]);
			}
		}
	}
	int ans = 0;
	for (int i = 0; i <= n * A; i++) {
		ans = max(ans, min(i, dp[k][i]));
	}
	cout << ans;
	return 0;
}