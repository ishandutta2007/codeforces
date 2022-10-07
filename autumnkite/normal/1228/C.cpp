#include <cstdio>
#include <cctype>
#include <cstring>
#include <algorithm>
long long read(){
	register long long x = 0;
	register char f = 1, ch = getchar();
	for (; !isdigit(ch); ch = getchar()) if (ch == '-') f ^= 1;
	for (; isdigit(ch); ch = getchar()) x = (x << 1) + (x << 3) + (ch ^ '0');
	return f ? x : -x;
}
#define P 1000000007
int x, ans;
long long n;
int qpow(int a, int b){
	int s = 1;
	for (; b; b >>= 1, a = 1ll * a * a % P) if (b & 1) s = 1ll * s * a % P;
	return s;
}
void solve(int p){
	long long x = 1;
	while (x <= n / p) x *= p, ans = 1ll * ans * qpow(p, (n / x) % (P - 1)) % P;
}
int main(){
	x = read(), n = read(), ans = 1;
	for (register int i = 2; i * i <= x; ++i)
		if (x % i == 0){
			while (x % i == 0) x /= i;
			solve(i);
		}
	if (x > 1) solve(x);
	printf("%d\n", ans);
}