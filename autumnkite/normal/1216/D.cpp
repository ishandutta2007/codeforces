#include <cstdio>
#include <cctype>
#include <algorithm>
#include <cstring>
int read(){
	register int x = 0;
	register char ch = getchar(), f = 1;
	for (; !isdigit(ch); ch = getchar()) if (ch == '-') f = !f;
	for (; isdigit(ch); ch = getchar()) x = (x << 1) + (x << 3) + (ch ^ '0');
	return f ? x : -x;
}
int n, a[200005], mn, mx, g;
long long s;
int gcd(int a, int b){
	return b ? gcd(b, a % b) : a;
}
int main(){
	n = read(), mn = 1e9;
	for (register int i = 1; i <= n; ++i) a[i] = read(), mn = std :: min(mn, a[i]);
	for (register int i = 1; i <= n; ++i) a[i] -= mn;
	for (register int i = 1; i <= n; ++i) g = gcd(g, a[i]);
	for (register int i = 1; i <= n; ++i) mx = std :: max(mx, a[i]);
	for (register int i = 1; i <= n; ++i) s += (mx - a[i]) / g;
	printf("%lld %d\n", s, g);
}