#include <bits/stdc++.h>

using namespace std;

const int MX = (1 << 23);
const int md = 998244353;

int pow(int x, int p) {
	int r = 1;
	while (p) {
		if (p % 2 == 1) r = r * 1ll * x % md;
		x = x * 1ll * x % md;
		p /= 2;
	}
	return r;
}

int pow(int x, long long p) {
	return pow(x, (int)(p % (md - 1)));
}

long long f[MX], inv[MX], f_inv[MX];

int C(int n, int k) {
	return f[n] * f_inv[n - k] % md * f_inv[k] % md;
}

int a[MX];

int main() {
	f[0] = f_inv[0] = f[1] = f_inv[1] = inv[1] = 1;
	for (int i = 2; i < MX; i++) {
		inv[i] = md - inv[md % i] * (md / i) % md;
		f[i] = f[i - 1] * i % md;
		f_inv[i] = f_inv[i - 1] * inv[i] % md;
	}
	
	int n;
	ignore = scanf("%d", &n);
	
	int ans = pow((pow(3, n) + md - 3) % md, n);
	for (int k = 1, sgn = -1; k <= n; k++, sgn *= -1) {
		int mul = 3ll * pow(pow(3, n - k) - 1, n) % md;
		mul += (pow(3, k) + md - 3ll) * pow(pow(3, n - k), n) % md;
		int add = C(n, k) * 1ll * mul % md;
		ans += sgn * add;
		if (ans < 0) ans += md;
		if (ans >= md) ans -= md;
	}
	
	ans = pow(3, n * 1ll * n) - ans;
	if (ans < 0) ans += md;
	
	printf("%d\n", ans);
	
	return 0;
}