#include <iostream>
#define int long long
using namespace std;


const int N = 505, mod = 1000 * 1000 * 1000 + 7;

long long fac[N];

long long po(long long x, long long y) {
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

long long chs(int x, int y) {
	long long ans = fac[x];
	ans *= po(fac[y], mod - 2);
	ans %= mod;
	ans *= po(fac[x - y], mod - 2);
	ans %= mod;
	return ans;
}

int32_t main() {
	int n, k;
	cin >> n >> k;
	fac[0] = 1;
	for (int i = 1; i <= n; i++) {
		fac[i] = fac[i - 1] * i;
		fac[i] %= mod;
	}
//	cout << chs(10, 2) << endl;
	long long ans = po(po(k, n) - po(k - 1, n) + mod, n);
//	cout << ans << endl;
	for (int i = 1; i <= n; i++) {
		long long x = chs(n, i);
		x *= po(k - 1, 1ll * n * i);
		x %= mod;
		x *= po(po(k, n - i) - po(k - 1, n - i) + mod, n);
		x %= mod;
		if (i % 2) {
			ans -= x - mod;
		}
		else {
			ans += x;
		}
		ans %= mod;
	//	cout << i << " " << x << endl;
	}
	cout << ans;
	return 0;
}