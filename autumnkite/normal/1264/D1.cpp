#include <cstdio>
#include <cstring>
#include <algorithm>
const int N = 1000005, P = 998244353;
char a[N];
int n, ans, fac[N], inv[N];
int qpow(int a, int b = P - 2){
	int s = 1;
	for (; b; b >>= 1, a = 1ll * a * a % P) if (b & 1) s = 1ll * s * a % P;
	return s;
}
void init(int n){
	fac[0] = 1;
	for (register int i = 1; i <= n; ++i) fac[i] = 1ll * fac[i - 1] * i % P;
	inv[n] = qpow(fac[n], P - 2);
	for (register int i = n; i; --i) inv[i - 1] = 1ll * inv[i] * i % P;
}
int C(int n, int m){
	if (m < 0 || m > n) return 0;
	return 1ll * fac[n] * inv[m] % P * inv[n - m] % P;
}
int main(){
	scanf("%s", a + 1), n = strlen(a + 1);
	init(n);
	int l = 0, r = 0, c = 0, c1 = 0, ans = 0;
	for (register int i = 1; i <= n; ++i) r += a[i] == ')', c += a[i] == '?';
	for (register int i = 1; i < n; ++i){
		l += a[i] == '(', r -= a[i] == ')', c1 += a[i] == '?';
		ans = (ans + 1ll * l * C(c, c1 + l - r) + 1ll * c1 * C(c - 1, c1 + l - r)) % P;
	}
	printf("%d\n", ans);
}