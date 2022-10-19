#include <bits/stdc++.h>
using namespace std;

const int MAXN = 5005;
const int MOD = 1e9 + 7;

int N, K;
int a[MAXN];
int fact[MAXN];
int dp[MAXN][MAXN];

void load() {
	scanf("%d%d", &N, &K);
	for (int i = 1; i <= N; i++)
		scanf("%d", a + i);
}

inline int add(int x, int y) {
	x += y;
	if (x >= MOD)
		x -= MOD;
	else if (x < 0)
		x += MOD;
	return x;
}

inline int mul(int x, int y) {
	return (long long)x * y % MOD;
}

int pot(int x, int y) {
	int res = 1;
	for (; y; y /= 2) {
		if (y % 2)
			res = mul(res, x);
		x = mul(x, x);
	}
	return res;
}

int choose(int x) {
	int res = 1;
	for (int i = 0; i < x; i++)
		res = mul(res, K - i);
	res = mul(res, pot(fact[x], MOD - 2));
	return res;
}

int calc(int i) {
	int coef = mul(fact[i], pot(pot(N, i + 1), MOD - 2));
	coef = mul(coef, choose(i + 1));
	coef = mul(coef, i + 1);
	int res = mul(coef, dp[N][N - i - 1]);
	if (i % 2)
		res = add(0, -res);
	return res;
}

int solve() {
	dp[0][0] = 1;
	for (int i = 1; i <= N; i++) {
		dp[i][0] = 1;
		for (int j = 1; j <= i; j++)
			dp[i][j] = add(dp[i - 1][j], mul(a[i], dp[i - 1][j - 1]));
	}
	
	fact[0] = 1;
	for (int i = 1; i <= N; i++)
		fact[i] = mul(fact[i - 1], i);
		
	int sol = 0;
	for (int i = 0; i < N; i++)
		sol = add(sol, calc(i));
		
	return sol;
}

int main() {
	load();
	printf("%d\n", solve());
	return 0;
}