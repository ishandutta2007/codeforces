#include <bits/stdc++.h>
typedef long long LL;
const int N = 505;
using std::min; using std::max;
int n, m, a[N][N], b[N][N];
int main() {
	scanf("%d%d", &n, &m);
	for (int i = 1; i <= n; i++)
		for (int j = 1; j <= m; j++)
			scanf("%d", &a[i][j]);
	for (int i = 1; i <= n; i++)
		for (int j = 1; j <= m; j++)
			b[i][j] = 720720;
	for (int i = 1; i <= n; i++)
		for (int j = 1; j <= m; j++)
			if ((i + j) & 1) b[i][j] += a[i][j] * a[i][j] * a[i][j] * a[i][j];
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= m; j++)
			printf("%d ", b[i][j]);
		puts("");
	}
	return 0;
}