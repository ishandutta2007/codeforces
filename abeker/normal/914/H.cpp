#include <bits/stdc++.h>
using namespace std;

const int MAXN = 205;

int N, D, M;
int dp[MAXN][MAXN][MAXN];
int pref[MAXN][MAXN];
int choose[MAXN][MAXN];
int pre[MAXN][MAXN];

void load() {
	scanf("%d%d%d", &N, &D, &M);
}

inline int add(int x, int y) {
	return x >= M - y ? x - (M - y) : x + y;
}

inline int mul(int x, int y) {
	return (long long)x * y % M;
}

int solve() {
	if (D == 1)
		return N == 2 ? 4 % M : 0;
	
	choose[0][0] = 1;
	for (int i = 1; i <= N; i++) {
		choose[i][0] = 1;
		for (int j = 1; j <= i; j++)
			choose[i][j] = add(choose[i - 1][j - 1], choose[i - 1][j]);
	}
	
	pref[1][0] = 1;
	for (int i = 1; i <= N; i++) {
		dp[i][0][0] = 1;
		for (int j = 1; j <= min(D, i - 1); j++) 
			for (int k = 1; k < i; k++)
				for (int l = 1; l <= k; l++)
					dp[i][j][k] = add(dp[i][j][k], mul(dp[i][j - 1][k - l], pre[k][l]));
		for (int j = 1; j <= D; j++)
			pref[i][j] = add(pref[i][j - 1], dp[i][j][i - 1]);
		for (int k = i; k < N; k++)
			pre[k][i] = mul(choose[k - 1][i - 1], pref[i][D - 1]);
	}

	int sol = 0;
	for (int i = 1; i <= N; i++)
		for (int j = 2; j < D; j++)
			for (int k = 1; j + k <= D; k++)
				sol = add(sol, mul(dp[i][j][i - 1], dp[N - i + 1][k][N - i]));

	for (int i = 1; i <= D; i++)
		sol = add(sol, dp[N][i][N - 1]);
	
	for (int i = 2; i <= D; i++)
		sol = add(sol, dp[N][i][N - 1]);
		
	return mul(sol, mul(2, mul(N, N - 1))); 
}

int main() {
	load();
	printf("%d\n", solve());
	return 0;
}