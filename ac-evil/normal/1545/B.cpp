#include <bits/stdc++.h>
const int N = 1e5 + 5, P = 998244353;
int T, n, inv[N * 2], fac[N * 2], ifac[N * 2]; char str[N];
int C(int n, int m) {
	return 1ll * fac[n] * ifac[m] % P * ifac[n - m] % P;
}
int main() {
	scanf("%d", &T);
	while (T--) {
		scanf("%d%s", &n, str + 1);
		inv[1] = fac[0] = ifac[0] = 1;
		for (int i = 2; i <= n * 2; i++)
			inv[i] = 1ll * (P - P / i) * inv[P % i] % P;
		for (int i = 1; i <= n * 2; i++)
			fac[i] = 1ll * fac[i - 1] * i % P,
			ifac[i] = 1ll * ifac[i - 1] * inv[i] % P;
		int cnt = 0, tot = 0, zero = 0;
		for (int i = 1; i <= n; i++)
			if (str[i] == '1') cnt++;
			else tot += cnt / 2, zero++, cnt = 0;
		tot += cnt / 2;
		// printf("%d %d %d\n", cnt, tot, zero);
		printf("%d\n", C(tot + zero, tot));
	}
	return 0;
}