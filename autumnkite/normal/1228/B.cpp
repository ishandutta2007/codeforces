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
#define N 1005
#define P 1000000007
int n, m, r[N], c[N], a[N][N];
int main(){
	n = read(), m = read();
	for (register int i = 1; i <= n; ++i) r[i] = read();
	for (register int i = 1; i <= m; ++i) c[i] = read();
	for (register int i = 1; i <= n; ++i){
		for (register int j = 1; j <= r[i]; ++j) a[i][j] = 2;
		if (r[i] < m) a[i][r[i] + 1] = 1;
	}
	for (register int j = 1; j <= m; ++j){
		for (register int i = 1; i <= c[j]; ++i)
			if (a[i][j] == 1) return printf("0\n"), 0; else a[i][j] = 2;
		if (c[j] < n) if (a[c[j] + 1][j] == 2) return printf("0\n"), 0; else a[c[j] + 1][j] = 1;
	}
	int ans = 1;
	for (register int i = 1; i <= n; ++i)
		for (register int j = 1; j <= m; ++j)
			if (!a[i][j]) ans <<= 1, ans %= P;
	printf("%d\n", ans);
}