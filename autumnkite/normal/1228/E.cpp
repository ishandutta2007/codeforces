#include <cstdio>
#include <cctype>
#include <cstring>
#include <algorithm>
#include <vector>
int read(){
	register int x = 0;
	register char f = 1, ch = getchar();
	for (; !isdigit(ch); ch = getchar()) if (ch == '-') f ^= 1;
	for (; isdigit(ch); ch = getchar()) x = (x << 1) + (x << 3) + (ch ^ '0');
	return f ? x : -x;
}
#define N 255
#define P 1000000007
int n, k, fac[N], inv[N], ans;
int qpow(int a, int b){
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
	return 1ll * fac[n] * inv[m] % P * inv[n - m] % P;
}
void inc(int &a, int b){ (a += b) >= P ? a -= P : 0; }
void dec(int &a, int b){ (a -= b) < 0 ? a += P : 0; }
int main(){
	n = read(), k = read(), init(n);
	for (register int i = 0; i <= n; ++i)
		for (register int j = 0; j <= n; ++j){
			int s = 1ll * C(n, i) * C(n, j) % P * qpow(k, (n - i) * (n - j)) % P * qpow(k - 1, n * n - (n - i) * (n - j)) % P;
			if ((i + j) & 1) dec(ans, s);
			else inc(ans, s);
		}
	printf("%d\n", ans);
}