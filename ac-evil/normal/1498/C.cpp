#include <bits/stdc++.h>
using std::sort;
typedef long long LL;
const int N = 1005, P = 1e9 + 7;
int T, n, k, f[N][N];
int main() {
	//freopen("ques.in", "r", stdin);
	scanf("%d", &T);
	while (T--) {
		scanf("%d%d", &n, &k);
		for (int i = 0; i <= n; i++)
			for (int j = 1; j <= k; j++)
				f[i][j] = 0;
		f[0][k] = 1;
		int ans = 1;
		for (int i = k - 1; i; i--) {
			if ((k - i) & 1) {
				for (int j = 0; j < n; j++)
					f[j][i] = ((j ? f[j - 1][i] : 0) + f[j][i + 1]) % P;
			} else {
				for (int j = n; j; j--)
					f[j][i] = ((j < n ? f[j + 1][i] : 0) + f[j][i + 1]) % P;
			}
			for (int j = 0; j <= n; j++) ans = (ans + f[j][i]) % P;
			/*printf("[%d]\n", i);
			for (int j = 0; j <= n; j++) printf("%d ", f[j][i]);
			puts("");*/
		}
		printf("%d\n", ans);
	}
	return 0;
}