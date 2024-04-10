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
int n, mx;
long long sum;
int main(){
	n = read();
	for (register int i = 1, x; i <= n; ++i)
		sum += (x = read()), mx = std :: max(mx, x);
	if (sum & 1 || sum - mx < mx) puts("NO"); else puts("YES");
}