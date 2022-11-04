#include <bits/stdc++.h>
using namespace std;
const int N = 505;
int n, m, k, go[N][10], wt[N], dep[N];
int f[N][N][12];
void dfs(int u) {
	for (int x = 0; x < 10; x++) if (go[u][x]) {
		int v = go[u][x];
		dfs(v);
		for (int d = 0; d <= dep[u]; d++) {
			for (int i = k; i >= 0; i--) {
				int cur = 0x3f3f3f3f;
				for (int j = 0; j <= i; j++)
					cur = min(cur, f[u][d][j] + f[v][d + 1][i - j]);
				f[u][d][i] = cur;
			}
		}
	}
	for (int d = 0; d <= dep[u]; d++)
		for (int i = 0; i <= k; i++)
			f[u][d][i] += d * wt[u];
	for (int d = 1; d <= dep[u]; d++)
		for (int i = 1; i <= k; i++)
			f[u][d][i] = min(f[u][d][i], f[u][0][i - 1]);
}
char str[N];
int main() {
	scanf("%d%d", &n, &k);
	m = 1;
	dep[1] = 0;
	for (int i = 1; i <= n; i++) {
		int x;
		scanf(" %s %d", str, &x);
		int len = strlen(str);
		int p = 1;
		for (int i = 0; i < len; i++) {
			if (!go[p][str[i] - '0']) dep[go[p][str[i] - '0'] = ++m] = dep[p] + 1;
			p = go[p][str[i] - '0'];
		}
		wt[p] += x;
	}
	k = min(k, n);
	dfs(1);
	printf("%d\n", f[1][0][k]);
	return 0;
}