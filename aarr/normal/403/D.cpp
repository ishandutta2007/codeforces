#include <iostream>
using namespace std;

const int N = 1005, SQ = 48, mod = 1000 * 1000 * 1000 + 7;

int dp[N][N][SQ];
long long fac[N];


int main() {
	fac[0] = 1;
	for (int i = 1; i < N; i++) {
		fac[i] = fac[i - 1] * i;
		fac[i] %= mod;
	} 
	dp[0][0][0] = 1;
	for (int j = 0; j < N; j++) {
		dp[0][j][0] = 1;
	}
	for (int i = 1; i < N; i++) {
		for (int k = 0; k < SQ; k++) {
			for (int j = 1; j < N; j++) {
				dp[i][j][k] = dp[i][j - 1][k];
				if (i >= j && k > 0) {
					dp[i][j][k] += dp[i - j][j - 1][k - 1];
				}
				dp[i][j][k] %= mod;
			}
			for (int j = 0; j < N; j++) {
				dp[i][j][k] += dp[i - 1][j][k];
				dp[i][j][k] %= mod;
			//	cout << "73 " << i << " " << j << " " << k << " " << dp[i][j][k] << endl;
			}
		}
	}
	int q;
	cin >> q;
	for (int ii = 0; ii < q; ii++) {
		int n, k;
		cin >> n >> k;
		if (k >= SQ) {
			cout << "0\n";
			continue;
		}
	//	long long ans = 0;
	//	for (int i = 0; i < N; i++) {
	//		ans += dp[n][i][k];
	//	}
		cout << (1ll * fac[k] * dp[n][N - 1][k]) % mod << '\n';
	}
	return 0;
}