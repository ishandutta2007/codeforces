#include <bits/stdc++.h>
using namespace std;

const int N = 250 * 1000 + 5;

long long fac[N];
int main() {
	ios :: sync_with_stdio(false);
	long long ans = 0;
	long long n, m;
	cin >> n >> m;
	fac[0] = 1;
	for (int i = 1; i <= n; i++) {
		fac[i] = 1ll * fac[i - 1] * i;
		fac[i] %= m;
	}
	for (int i = 1; i <= n; i++) {
		long long x = 1ll * (n - i + 1) * (n - i + 1);
		x %= m;
		x *= fac[i];
		x %= m;
		x *= fac[n - i];
		x %= m;
		ans += x;
		ans %= m;
	}
	cout << ans << endl;
	return 0;
}