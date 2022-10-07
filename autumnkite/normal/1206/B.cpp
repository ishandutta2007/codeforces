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
#define N 100005
int n, x, sum, sum0;
long long ans;
int abs(int x){ return x >= 0 ? x : -x; }
int main(){
	n = read();
	for (register int i = 1; i <= n; ++i)
		x = read(), ans += abs(abs(x) - 1), sum += x < 0, sum0 += x == 0;
	if ((sum & 1) && !sum0) printf("%lld\n", ans + 2); else printf("%lld\n", ans);
}