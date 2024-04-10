#include <bits/stdc++.h>
const int N = 1e5 + 5, M = 3e5 + 5, P = 998244353;
int n, a[N], mW, f[M], inv[M], s = 0;
int main() {
	scanf("%d", &n);
	for (int i = 1; i <= n; i++)
		scanf("%d", &a[i]), s += a[i];
	inv[1] = 1;
	for (int i = 2; i <= s; i++)
		inv[i] = 1ll * (P - P / i) * inv[P % i] % P;
	for (int i = 1; i < s; i++)
		f[i + 1] = ((s + i * (n - 2ll)) % P * f[i] - (i * (n - 1ll) % P * (f[i - 1] + 1)) % P + P) % P * inv[s - i] % P;
	int ans = 0;
	for (int i = 1; i <= n; i++)
		ans = (ans + f[a[i]]) % P;
	ans = (ans - f[s] + P) % P;
	printf("%d\n", ans);
	return 0;
}