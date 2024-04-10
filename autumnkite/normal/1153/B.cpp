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
#define N 105
int n, m, h, a[N], b[N], c[N][N];
int main(){
	n = read(), m = read(), h = read();
	for (register int i = 1; i <= m; ++i) a[i] = read();
	for (register int i = 1; i <= n; ++i) b[i] = read();
	for (register int i = 1; i <= n; ++i)
		for (register int j = 1; j <= m; ++j){
			int x = read();
			if (x) c[i][j] = std :: min(a[j], b[i]);
		}
	for (register int i = 1; i <= n; ++i){
		for (register int j = 1; j <= m; ++j) printf("%d ", c[i][j]);
		putchar('\n');
	}
}