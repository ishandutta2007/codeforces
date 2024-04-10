#include <cstdio>
#include <cctype>
#include <algorithm>
int read(){
	register int x = 0;
	register char f = 1, ch = getchar();
	for (; !isdigit(ch); ch = getchar()) if (ch == '-') f = !f;
	for (; isdigit(ch); ch = getchar()) x = (x << 1) + (x << 3) + (ch ^ '0');
	return f ? x : -x;
}
#define N 200005
int n, a[N], b[N], ex[N], p, flag, ans;
int main(){
	n = read();
	for (register int i = 1; i <= n; ++i) a[i] = read(), ex[a[i]] = 1;
	for (register int i = 1; i <= n; ++i) b[i] = read(), b[i] ? ans = std :: max(ans, i + 1 - b[i]) : 0;
	p = n + 1, flag = 1;
	for (register int i = 1; i <= n; ++i) if (b[i] == 1){ p = i; break; }
	if (p > n) flag = 0;
	for (register int i = p + 1; i <= n; ++i) if (b[i] != i - p + 1) flag = 0;
	for (register int i = 1; i < p; ++i) !ex[n - p + 1 + i] ? flag = 0 : 0, ex[b[i]] = 1;
	if (flag) printf("%d", p - 1);
	else printf("%d", n + ans);
}