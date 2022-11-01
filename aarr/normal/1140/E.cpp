#include <iostream>
using namespace std;

const int N = 200 * 1000 + 5;
const int mod = 998244353;

int a[N];
int b[N];
long long dp[N][3];
int main() {
	int n, k;
	cin >> n >> k;
	for (int i = 1; i <= n; i++) {
		cin >> a[i];
	}
	for (int i = 1; i <= n - 2; i++) {
		if (a[i] == a[i + 2] && a[i] != -1) {
			cout << 0 << endl;
			return 0;
		}
	}
	for (int i = n; i > 0; i--) {
		b[i] = b[i + 2];
		if (a[i] != -1) {
			b[i] = a[i];
		}
	}
	if (a[1] != -1) {
		dp[1][0] = 1;
	}
	else {
		if (b[1] == 0) {
			dp[1][1] = k;
		}
		else {
			dp[1][0] = 1;
			dp[1][1] = k - 1;
		}
	}
	if (a[2] != -1) {
		dp[2][0] = 1;
	}
	else {
		if (b[2] == 0) {
			dp[2][1] = k;
		}
		else {
			dp[2][0] = 1;
			dp[2][1] = k - 1;
		}
	}
	for (int i = 3; i <= n; i++) {
		if (a[i] != -1) {
			if (a[i - 2] != -1) {
				dp[i][0] = dp[i - 2][0];
			}
			else {
				dp[i][0] = dp[i - 2][1];
			}
		}
		else {
			if (a[i - 2] == -1) {
				if (b[i] != 0) {
					dp[i][0] = dp[i - 2][1];
					dp[i][1] = 1ll * dp[i - 2][0] * (k - 1);
					dp[i][1] += 1ll * dp[i - 2][1] * (k - 2);
				}
				else {
					dp[i][1] = 1ll * dp[i - 2][1] * (k - 1);
				}
			
			}
			else {
				if (b[i] == 0 || b[i] == a[i - 2]) {
					dp[i][1] = 1ll * dp[i - 2][0] * (k - 1);
				}
				else /*(b[i] != 0 && b[i] != a[i - 2])*/ {
					dp[i][0] = dp[i - 2][0];
					dp[i][1] = 1ll * dp[i - 2][0] * (k - 2);
				}
			}
			
		}
		dp[i][0] %= mod;
		dp[i][1] %= mod;
	}
//	for (int i = 1; i <= n; i++) {
//		cout << i << " " << b[i] << " " << dp[i][0] << " " << dp[i][1] << endl;
//	}
	long long ans = 1ll * (dp[n][1] + dp[n][0]) * (dp[n - 1][1] + dp[n - 1][0]);
	ans %= mod;
	cout << ans << endl;
	return 0;
}