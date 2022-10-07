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
int T;
long long n, m, k, s, ans;
int main(){
	T = read();
	while (T--){
		n = read(), m = read(), k = n / m + 1, m %= 10, ans = 0;
		s = 0;
		for (register int i = 1; i <= 10; ++i) ans += s, (s += m) %= 10;
		ans *= k / 10;
		s = 0;
		for (register int i = 1; i <= k % 10; ++i) ans += s, (s += m) %= 10;
		printf("%lld\n", ans);
	}
}