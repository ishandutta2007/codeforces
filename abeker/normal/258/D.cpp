#include <bits/stdc++.h>
using namespace std;

typedef long double ld;

const int MAXN = 1e3 + 5;

int N, M;
int perm[MAXN];
ld dp[MAXN][MAXN], tmp[MAXN][MAXN];

void update(int a, int b) {
	for (int i = 1; i <= N; i++) {
		tmp[a][i] = (dp[a][i] + dp[b][i]) / 2;
		tmp[i][a] = (dp[i][a] + dp[i][b]) / 2;
		tmp[b][i] = (dp[b][i] + dp[a][i]) / 2;
		tmp[i][b] = (dp[i][b] + dp[i][a]) / 2;
	}
	tmp[a][b] = tmp[b][a] = (dp[a][b] + dp[b][a]) / 2;
	
	for (int i = 1; i <= N; i++) {
		dp[a][i] = tmp[a][i];
		dp[i][a] = tmp[i][a];
		dp[b][i] = tmp[b][i];
		dp[i][b] = tmp[i][b];
	}
}

int main() {
	scanf("%d%d", &N, &M);
	for (int i = 1; i <= N; i++)
		scanf("%d", perm + i);
	
	for (int i = 1; i <= N; i++)
		for (int j = 1; j <= N; j++)
			dp[i][j] = perm[i] > perm[j];
	
	while (M--) {
		int a, b;
		scanf("%d%d", &a, &b);
		update(a, b);
	}
	
	ld ans = 0;
	for (int i = 1; i <= N; i++)
		for (int j = i + 1; j <= N; j++)
			ans += dp[i][j];
	
	printf("%.10Lf\n", ans);
	
	return 0;
}