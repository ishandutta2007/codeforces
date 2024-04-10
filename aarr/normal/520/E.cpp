#include <iostream>
using namespace std;

const int N = 100 * 1000 + 5;
const int mod = 1000 * 1000 * 1000 + 7;

long long fac[N];
int a[N];
int ps[N];

int po(int x, int y) {
	if (y < 0)
		return 0;
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
int chs(int x, int y) {
	if (x < y)
		return 0;
	long long ans = fac[x];
	ans *= po(fac[y], mod - 2);
	ans %= mod;
	ans *= po(fac[x - y], mod - 2);
	ans %= mod;
	return ans;
}
int main() {
	int n, k;
	cin >> n >> k;
	for (int i = 1; i <= n; i++) {
		char c;
		cin >> c;
		a[i] = c - '0';
		ps[i] = ps[i - 1] + a[i];
	}
	fac[0] = 1;
	for (int i = 1; i <= n; i++) {
		fac[i] = fac[i - 1] * i;
		fac[i] %= mod;
	}
	long long ans = 0;
	for (int i = 1; i <= n; i++) {
		long long x = 1ll * (po(10, n - i) - po(10, n - i - 1) + mod) * chs(i - 1, k);
		x %= mod;
		x *= ps[i];
		x %= mod;
	//	cout << i << " " << x << endl;
		ans += x;
		ans %= mod;
	}
	cout << ans << endl;
	return 0;
}