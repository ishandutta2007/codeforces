#include <bits/stdc++.h>

using namespace std;

const int MX = 300000;

long long f[MX], inv[MX], f_inv[MX];

int main() {
	int n, md;
	ignore = scanf("%d %d", &n, &md);
	
	f[0] = f[1] = inv[1] = f_inv[0] = f_inv[1] = 1;
	for (int i = 2; i <= n; i++) {
		f[i] = f[i - 1] * i % md;
		inv[i] = md - inv[md % i] * (md / i) % md;
		f_inv[i] = f_inv[i - 1] * inv[i] % md;
	}
	
	int ans = 0;
	for (int k = 1; k <= n; k++) {
		int x = (n + 1LL - k) * (n + 1LL - k) % md;
		x = x * f[k] % md;
		x = x * f[n - k] % md;
		ans = (ans + x) % md;
	}
	
	printf("%d\n", ans);
	
	return 0;
}