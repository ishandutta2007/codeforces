#include <cstdio>
#define P 1000000007
long long n;
int k, inv[105], a[105], ans;
void inc(int &a, int b){
	(a += b) >= P ? a -= P : 0;
}
int qpow(int a, int b = P - 2){
	int s = 1;
	for (; b; b >>= 1, a = 1ll * a * a % P) if (b & 1) s = 1ll * s * a % P;
	return s;
}
int get(int p, int q){
	for (register int i = 0; i <= q; ++i) a[i] = inv[q + 1];
	for (register int i = 2; i <= k; ++i){
		for (register int j = 0; j <= q; ++j) a[j] = 1ll * a[j] * inv[j + 1] % P;
		for (register int j = q - 1; ~j; --j) inc(a[j], a[j + 1]);
	}
	int res = 0;
	for (register int i = 0, t = 1; i <= q; t = 1ll * t * p % P, ++i)
		inc(res, 1ll * t * a[i] % P);
	return res;
}
int main(){
	scanf("%lld%d", &n, &k);
	ans = 1;
	for (register int i = 1; i <= 100; ++i) inv[i] = qpow(i);
	for (register int i = 2; 1ll * i * i <= n; ++i)
		if (n % i == 0){
			int q = 0;
			while (n % i == 0) n /= i, ++q;
			ans = 1ll * ans * get(i, q) % P;
		}
	if (n > 1) ans = 1ll * ans * get(n % P, 1) % P;
	printf("%d\n", ans);
}