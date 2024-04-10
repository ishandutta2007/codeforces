#include <cstdio>
#include <cctype>
#include <algorithm>
#include <cstring>
long long read(){
	register long long x = 0;
	register char ch = getchar(), f = 1;
	for (; !isdigit(ch); ch = getchar()) if (ch == '-') f = !f;
	for (; isdigit(ch); ch = getchar()) x = (x << 1) + (x << 3) + (ch ^ '0');
	return f ? x : -x;
}
long long n, m, g, sx, sy, ex, ey;
int q;
long long gcd(long long a, long long b){
	return b ? gcd(b, a % b) : a;
}
int main(){
	n = read(), m = read(), q = read(), g = gcd(n, m);
	while (q--){
		sx = read(), sy = read() - 1, ex = read(), ey = read() - 1;
		if (sx == 1) sy /= n / g; else sy /= m / g;
		if (ex == 1) ey /= n / g; else ey /= m / g;
		if (sy == ey) puts("YES"); else puts("NO");
	}
}