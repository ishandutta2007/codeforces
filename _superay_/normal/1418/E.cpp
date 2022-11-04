#include <bits/stdc++.h>
using namespace std;
const int N = 200005;
const int mod = 998244353;
inline int qp(int a, int b) {
	int res = 1;
	while (b) {
		if (b & 1) res = 1ll * res * a % mod;
		a = 1ll * a * a % mod;
		b >>= 1;
	}
	return res;
}
int n, m, d[N], ps[N], a[N], b[N];
int main() {
	scanf("%d%d", &n, &m);
	for (int i = 1; i <= n; i++) scanf("%d", &d[i]);
	sort(d + 1, d + 1 + n);
	ps[0] = 0;
	for (int i = 1; i <= n; i++) ps[i] = (ps[i - 1] + d[i]) % mod;
	for (int i = 1; i <= m; i++) {
		scanf("%d%d", &a[i], &b[i]);
		int j = lower_bound(d + 1, d + 1 + n, b[i]) - d;
		if (n - j + 1 < a[i]) {
			puts("0");
			continue;
		}
		int res = 1ll * (n - j + 1 - a[i]) * qp(n - j + 1, mod - 2) % mod * (ps[n] - ps[j - 1] + mod) % mod;
		res = (res + 1ll * ps[j - 1] * qp(n - j + 2, mod - 2) % mod * (n - j + 2 - a[i])) % mod;
		printf("%d\n", res);
	}
	return 0;
}