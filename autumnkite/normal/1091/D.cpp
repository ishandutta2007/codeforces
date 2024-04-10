#include <cstdio>
#define P 998244353
int n, fac[1000005], inv[1000005];
int qpow(int a, int b){
	int s = 1;
	for (; b; b >>= 1, a = 1ll * a * a % P) if (b & 1) s = 1ll * s * a % P;
	return s;
}
void pre(){
	fac[0] = 1;
	for (register int i = 1; i <= n; ++i) fac[i] = 1ll * fac[i - 1] * i % P;
	inv[n] = qpow(fac[n], P - 2);
	for (register int i = n; i; --i) inv[i - 1] = 1ll * inv[i] * i % P;
}
int main(){
	scanf("%d", &n), pre();
	int ans = 1;
	for (register int i = 1; i <= n; ++i)
		ans = (ans + 1ll * (fac[i] + P - 1) % P * inv[i] % P * fac[n] % P) % P;
	printf("%d", ans);
}