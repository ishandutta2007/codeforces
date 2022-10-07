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
int n, m, p[10], col[10], used[10][10], ans;
struct edge{
	int x, y;
}E[25];
int main(){
	n = read(), m = read();
	if (n <= 6) return printf("%d\n", m), 0;
	for (register int i = 1; i <= m; ++i)
		E[i].x = read(), E[i].y = read();
	for (register int i = 1; i <= 7; ++i) p[i] = i;
	while (1){
		for (register int i = 1; i <= 6; ++i) col[p[i]] = i;
		for (register int i = 1; i <= 6; ++i){
			col[p[7]] = i;
			memset(used, 0, sizeof used);
			int s = 0;
			for (register int j = 1; j <= m; ++j)
				if (!used[col[E[j].x]][col[E[j].y]])
					++s, used[col[E[j].x]][col[E[j].y]] = used[col[E[j].y]][col[E[j].x]] = 1;
			ans = std :: max(ans, s);
		}
		if (!std :: next_permutation(p + 1, p + 8)) break;
	}
	printf("%d\n", ans);
}