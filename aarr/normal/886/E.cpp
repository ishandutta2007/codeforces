#include <iostream>
using namespace std;

const int N = 1000 * 1000 + 5, mod = 1000 * 1000 * 1000 + 7;

long long fac[N];
long long dp[N], ps[N];

int po(int x, int y) {
	if (y == 0) {
		return 1;
	}
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
	int n, k;
	cin >> n >> k;
	fac[0] = 1;
	for (int i = 1; i <= n; i++) {
		fac[i] = fac[i - 1] * i;
		fac[i] %= mod;
	}
	long long ans = 0;
	for (int i = k + 1; i <= n; i++) {
		dp[i] = 1ll * (i - k - 1) * fac[i - 2];
		dp[i] %= mod;
		dp[i] += (ps[i - 1] - ps[i - k - 1] + mod) * fac[i - 2];
		dp[i] %= mod;
		ps[i] = ps[i - 1] + 1ll * dp[i] * po(fac[i - 1], mod - 2);
		ps[i] %= mod;
		long long q = 1ll * fac[n - 1] * po(fac[i - 1], mod - 2);
		q %= mod;
		q *= dp[i];
		q %= mod;
	//	cout << "73 " << i << " " << dp[i] << " " << q << endl;
		ans += q;
	}
	cout << ans % mod << endl;
	return 0;
}