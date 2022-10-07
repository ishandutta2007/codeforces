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
int n, x, s[2], now;
long long ans0, ans1;
int main(){
	n = read();
	for (register int i = 1; i <= n; ++i){
		x = read(), ++s[now];
		if (x < 0) ++now, now &= 1;
		ans0 += s[now], ans1 += s[now ^ 1];
	}
	printf("%lld %lld\n", ans1, ans0);
}