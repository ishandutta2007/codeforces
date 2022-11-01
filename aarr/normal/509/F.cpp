#include <iostream>
using namespace std;

const int N = 505, mod = 1000 * 1000 * 1000 + 7;

int a[N];
long long dp[N][N];

int main() {
	int n;
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> a[i];
		dp[i + 1][i + 1] = 1;
	}
	for (int i = 1; i < n; i++) {
		for (int l = 0; l + i <= n; l++) {
			int r = l + i;
			dp[l][r] = dp[l + 1][r];
			for (int j = l + 1; j < r; j++) {
				if (a[l] < a[j]) {
					dp[l][r] += 1ll * dp[l + 1][j] * dp[j][r];
					dp[l][r] %= mod;
				}
			}
		//	cout << "73 " << l << " " << r << " " << dp[l][r] << endl;
		}
	}
	cout << dp[1][n];
	return 0;
}