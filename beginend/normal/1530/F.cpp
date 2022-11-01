#include<bits/stdc++.h>
using namespace std;

const int N = 30;
const int MOD = 31607;

int n, a[N][N], b[N][N], pos[N][N][2], ans, s[N], vis[N][N];

int ksm(int x, int y) {
	int ans = 1;
	while (y) {
		if (y & 1) (ans *= x) %= MOD;
		(x *= x) %= MOD; y >>= 1;
	}
	return ans;
}

void dfs(int x, int f, int val) {
	if (x > n + 2) {
		int res = 1;
		for (int i = 1; i <= n; i++)
			(res *= 1 + MOD - s[i]) %= MOD;
		(ans += f * res * val % MOD) %= MOD;
		return;
	}
	dfs(x + 1, f, val);
	for (int i = 1; i <= n; i++) {
		int u = pos[x][i][0], v = pos[x][i][1];
		if (!vis[u][v]) (s[u] *= b[u][v]) %= MOD, (val *= a[u][v]) %= MOD;
		vis[u][v]++;
	}
	dfs(x + 1, -f, val);
	for (int i = 1; i <= n; i++) {
		int u = pos[x][i][0], v = pos[x][i][1];
		vis[u][v]--;
		if (!vis[u][v]) (s[u] *= a[u][v]) %= MOD, (val *= b[u][v]) %= MOD;
	}
}

int main() {
	scanf("%d", &n);
	int inv = ksm(10000, MOD - 2);
	for (int i = 1; i <= n; i++) s[i] = 1;
	for (int i = 1; i <= n; i++)
		for (int j = 1; j <= n; j++) {
			scanf("%d", &a[i][j]);
			(a[i][j] *= inv) %= MOD;
			b[i][j] = ksm(a[i][j], MOD - 2);
			(s[i] *= a[i][j]) %= MOD;
		}
	for (int i = 1; i <= n; i++) {
		pos[1][i][0] = pos[1][i][1] = pos[2][i][0] = i;
		pos[2][i][1] = n - i + 1;
		for (int j = 1; j <= n; j++) {
			pos[i + 2][j][0] = j;
			pos[i + 2][j][1] = i;
		}
	}
	dfs(1, 1, 1);
	printf("%d\n", (1 + MOD - ans) % MOD);
	return 0;
}