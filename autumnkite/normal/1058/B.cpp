#include <cstdio>
int n, d, m, a[105][105];
int main(){
	scanf("%d%d%d", &n, &d, &m);
	for (register int i = 0; i <= d; ++i){
		for (register int x = i, y = d - i, k = 0; k <= n - d; ++x, ++y, ++k)
			a[x][y] = 1;
		if (i == d) break;
		for (register int x = i + 1, y = d - i, k = 1; k <= n - d; ++x, ++y, ++k)
			a[x][y] = 1;
	}
	while (m--){
		int x, y;
		scanf("%d%d", &x, &y);
		if (a[x][y]) printf("YES\n"); else printf("NO\n");
	}
}