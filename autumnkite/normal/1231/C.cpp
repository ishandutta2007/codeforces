#include <cstdio>
#include <cctype>
#include <cstring>
#include <algorithm>
#include <vector>
int read(){
	register int x = 0;
	register char f = 1, ch = getchar();
	for (; !isdigit(ch); ch = getchar()) if (ch == '-') f ^= 1;
	for (; isdigit(ch); ch = getchar()) x = (x << 1) + (x << 3) + (ch ^ '0');
	return f ? x : -x;
}
int n, m, a[505][505], sum;
bool check(){
	for (register int i = 1; i <= n; ++i)
		for (register int j = 1; j <= m; ++j)
			if ((i < n && a[i][j] >= a[i + 1][j]) || (j < m && a[i][j] >= a[i][j + 1])) return 0;
	return 1;
}
int main(){
	n = read(), m = read();
	for (register int i = 1; i <= n; ++i)
		for (register int j = 1; j <= m; ++j)
			a[i][j] = read();
	for (register int i = n; i; --i)
		for (register int j = m; j; --j){
			if (a[i][j] == 0) a[i][j] = std :: min(a[i + 1][j], a[i][j + 1]) - 1;
			sum += a[i][j];
		}
	if (check()) printf("%d\n", sum); else printf("-1\n");
}