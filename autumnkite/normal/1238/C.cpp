#include <cstdio>
#include <cctype>
#include <cstring>
#include <algorithm>
int read(){
	register int x = 0;
	register char f = 1, ch = getchar();
	for (; !isdigit(ch); ch = getchar()) if (ch == '-') f ^= 1;
	for (; isdigit(ch); ch = getchar()) x = (x << 1) + (x << 3) + (ch ^ '0');
	return f ? x : -x;
}
int T, n, h, a[200005], ans;
void solve(){
	h = read(), n = read(), ans = 0;
	for (register int i = 1; i <= n; ++i) a[i] = read();
	a[n + 1] = 0, h = 1;
	while (h < n)
		if (a[h + 1] - 1 == a[h + 2]) h += 2;
		else ++h, ++ans, a[h] = a[h + 1] - 1;
	printf("%d\n", ans);
}
int main(){
	T = read();
	while (T--) solve();
}