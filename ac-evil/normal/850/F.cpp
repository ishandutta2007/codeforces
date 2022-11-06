#include <bits/stdc++.h>
const int N = 2505, M = 1e5 + 5, P = 1e9 + 7;
int n, s, A, mW, a[N], e[M];
int qpow(int a, int b) {
	int c = 1;
	for (; b; b >>= 1, a = 1ll * a * a % P)
		if (b & 1) c = 1ll * c * a % P;
	return c;
}
int main() {
	scanf("%d", &n);
	for (int i = 1; i <= n; i++)
		scanf("%d", &a[i]), s += a[i], mW = std::max(mW, a[i]);
	A = 1ll * s * (s - 1) % P;
	e[1] = 1ll * (s - 1) * (s - 1) % P;
    for (int i = 1; i < mW; i++)
		e[i + 1] = 1ll * qpow(i + 1, P - 2) * ((2ll * i * e[i] - (i - 1ll) * e[i - 1] % P + P - 1ll * A * qpow(s - i, P - 2) % P + P) % P) % P;
	int ans = 0;
	for (int i = 1; i <= n; i++)
		ans = (ans + 1ll * a[i] * qpow(s, P - 2) % P * e[a[i]]) % P;
	printf("%d\n", ans);
	return 0;
}