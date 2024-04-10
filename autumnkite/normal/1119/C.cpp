#include <cstdio>
#include <algorithm>
int n, m, a[505][505], b[505][505];
int main(){
	scanf("%d%d", &n, &m);
	for (register int i = 1; i <= n; ++i)
		for (register int j = 1; j <= m; ++j){
			scanf("%d", &a[i][j]);
			a[i][j] = a[i - 1][j] ^ a[i][j - 1] ^ a[i - 1][j - 1] ^ a[i][j];
		}
	for (register int i = 1; i <= n; ++i)
		for (register int j = 1; j <= m; ++j){
			scanf("%d", &b[i][j]);
			b[i][j] = b[i - 1][j] ^ b[i][j - 1] ^ b[i - 1][j - 1] ^ b[i][j];
		}
	for (register int i = 1; i <= m; ++i) if (a[n][i] != b[n][i]) return printf("No\n"), 0;
	for (register int i = 1; i <= n; ++i) if (a[i][m] != b[i][m]) return printf("No\n"), 0;
	printf("Yes\n");
}