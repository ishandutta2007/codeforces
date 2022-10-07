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
#define N 150005
int T, n, a[N], mn, ans;
int main(){
	T = read();
	while (T--){
		n = read(), ans = 0;
		for (register int i = 1; i <= n; ++i) a[i] = read();
		mn = a[n];
		for (register int i = n - 1; i; --i) ans += a[i] > mn, mn = std :: min(mn, a[i]);
		printf("%d\n", ans);
	}
}