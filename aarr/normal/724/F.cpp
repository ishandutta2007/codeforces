#include <bits/stdc++.h>
using namespace std;

const int N = 1017, D = 12;
int n, d, mod;

long long dp[N][N][D], chs[N][N];
long long f[N][D];
long long fac[N];

int po(int x, int y) {
	if (y == 0)
		return 1;
	long long ans = po(x, y / 2);
	ans *= ans;
	ans %= mod;
	if (y % 2) {
		ans *= x;
		ans %= mod;
	}
	return ans;
}

int main() {
	cin >> n >> d >> mod;
	if (n == 1) {
		cout << 1;
		return 0;
	}
	chs[0][0] = 1;
	for (int i = 1; i <= n + d; i++) {
		for (int j = 0; j <= n + d; j++) {
			chs[i][j] = chs[i - 1][j];
			if (j) {
				chs[i][j] += chs[i - 1][j - 1];
			}
			chs[i][j] %= mod;
		}
	}
	fac[0] = 1;
	for (int i = 1; i <= d; i++) {
		fac[i] = fac[i - 1] * i;
		fac[i] %= mod;
	}
	dp[1][0][d - 1] = 1;
	dp[1][0][0] = 1;
	for (int i = 1; i <= n; i++) {
		for (int k = 0; k <= d; k++) {
			for (int j = 1; j <= n; j++) {
				dp[i][j][k] = dp[i][j - 1][k];
				for (int q = 1; q <= k && q * j <= i; q++) {
					dp[i][j][k] += 1ll * dp[i - q * j][j - 1][k - q] * f[j][q];//cs(dp[j][j - 1][d - 1] + q - 1, q);
					dp[i][j][k] %= mod;
				}
			//	cout << "73 " << i << " " << j << " " << k << " " << dp[i][j][k] << endl;
			}
		}
		for (int r = 0; r <= d; r++) {
			f[i][r] = po(fac[r], mod - 2);
			for (int l = dp[i][i - 1][d - 1]; l < dp[i][i - 1][d - 1] + r; l++) {
				f[i][r] *= l;
				f[i][r] %= mod;
			}
		//	cout << "72 " << i << " " << r << " " << f[i][r] << endl;
		}
		
	}
	long long ans = dp[n][n - n / 2 - 1][d];
//	cout << ans << endl;
	if (n % 2 == 0) {
		ans += (dp[n / 2][n / 2 - 1][d - 1] + 1) * dp[n / 2][n / 2 - 1][d - 1] / 2;
	}
	ans %= mod;
	cout << ans;
	return 0;
}