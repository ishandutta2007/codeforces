#include <cstdio>
#include <cctype>
#include <cstring>
#include <algorithm>
int read(){
	register int x = 0;
	register char f = 1, ch = getchar();
	for (; !isdigit(ch); ch = getchar()) if (ch == '-') f ^= 1;
	for (; isdigit(ch); ch = getchar()) x = (x << 1) + (x << 3) + (ch ^ '0');
	return f ? x : -x;
}
const int N = 55, P = 998244353;
int n, l[N], r[N], m, a[N << 1], dp[N][N << 1], inv[N], ans;
int qpow(int a, int b = P - 2){
	int s = 1;
	for (; b; b >>= 1, a = 1ll * a * a % P) if (b & 1) s = 1ll * s * a % P;
	return s;
}
int C(int n, int m){
	int res = 1;
	for (register int i = 1; i <= m; ++i)
		res = 1ll * res * (n - i + 1) % P * inv[i] % P;
	return res;
}
int main(){
	n = read(), ans = 1, m = 0, inv[1] = 1;
	for (register int i = 2; i <= n; ++i) inv[i] = 1ll * (P - P / i) * inv[P % i] % P;
	for (register int i = 1; i <= n; ++i){
		l[i] = read(), r[i] = read() + 1;
		ans = 1ll * ans * (r[i] - l[i]) % P;
	}
	ans = qpow(ans, P - 2);
	for (register int i = 2; i <= n; ++i) r[i] = std::min(r[i - 1], r[i]);
	for (register int i = n - 1; i; --i) l[i] = std::max(l[i + 1], l[i]);
	for (register int i = 1; i <= n; ++i){
		if (l[i] >= r[i]) return puts("0"), 0;
		a[++m] = l[i], a[++m] = r[i];
	}
	std::sort(a + 1, a + 1 + m);
	m = std::unique(a + 1, a + 1 + m) - a - 1;
	for (register int i = 1; i <= n; ++i){
		l[i] = std::lower_bound(a + 1, a + 1 + m, l[i]) - a;
		r[i] = std::lower_bound(a + 1, a + 1 + m, r[i]) - a;
	}
	for (register int i = 1; i <= m; ++i) dp[0][i] = 1;
	for (register int i = 1; i <= n; ++i){
		for (register int j = r[i] - 1; j >= l[i]; --j)
			for (register int k = i; ~k; --k){
				dp[i][j] = (dp[i][j] + 1ll * dp[k][j + 1] * C(a[j + 1] - a[j] + i - k - 1, i - k)) % P;
				if (l[k] > j) break;
			}
		for (register int j = l[i] - 1; j; --j) dp[i][j] = dp[i][j + 1];
	}
	ans = 1ll * ans * dp[n][1] % P;
	printf("%d\n", ans);
}