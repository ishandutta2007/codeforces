#include <bits/stdc++.h>
using namespace std;

const int MAXN = 2e5 + 5;
const int MOD = 1e9 + 7;

int N, L, R;
int dp[MAXN][3];
int cnt[3];

inline int add(int x, int y) {
	x += y;
	if (x >= MOD)
		x -= MOD;
	return x;
}

inline int mul(int x, int y) {
	return (long long)x * y % MOD;
}

int get(int x, int rem) {
	if (!rem)
		return x / 3;
	if (x < rem)
		return 0;
	return (x - rem) / 3 + 1;
}

int main() {
	scanf("%d%d%d", &N, &L, &R);
	
	for (int i = 0; i < 3; i++)
		cnt[i] = get(R, i) - get(L - 1, i);
	
	dp[0][0] = 1;
	for (int i = 1; i <= N; i++)
		for (int j = 0; j < 3; j++)
			for (int k = 0; k < 3; k++)
				dp[i][j] = add(dp[i][j], mul(dp[i - 1][(j - k + 3) % 3], cnt[k]));
	
	printf("%d\n", dp[N][0]);
	
	return 0;
}