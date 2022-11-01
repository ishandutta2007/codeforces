#include <bits/stdc++.h>
#define rep(i, n) for(int i = 0; i < (int)(n); i ++)
#define rep1(i, n) for(int i = 1; i <= (int)(n); i ++)
#define MP make_pair

using namespace std;
typedef long long LL;
typedef pair<int, int> PII;
const int MOD = 1e9 + 7;
int power(int x, int t)
{
	int ret = 1;
	while(t > 0) {
		if(t & 1) ret = 1ULL * ret * x % MOD;
		x = 1ULL * x * x % MOD;
		t >>= 1;
	}
	return ret;
}

int n, a[15], prob[15][15], to[15][16384];
int dp[16384];

int main()
{
	scanf("%d", &n);
	rep(i, n) scanf("%d", &a[i]);
	rep(i, n) rep(j, n) prob[i][j] = 1ULL * a[i] * power(a[i] + a[j], MOD - 2) % MOD;
	rep(i, n) {
		rep(j, n) to[i][1 << j] = prob[i][j];
		to[i][0] = 1;
		rep(j, 1 << n) to[i][j] = 1ULL * to[i][j & -j] * to[i][j & (j - 1)] % MOD;
	}
	
	rep(i, 1 << n) {
		dp[i] = 1;
		for(int j = (i - 1) & i; j > 0; j = (j - 1) & i) {
			int coef = (MOD - dp[j]) % MOD;
			rep(k, n) if(j >> k & 1) coef = 1ULL * coef * to[k][i ^ j] % MOD;
			dp[i] = (dp[i] + coef) % MOD;
		}
	}
	
	int ans = 0;
	rep(i, 1 << n) {
		int coef = 1ULL * dp[i] * __builtin_popcount(i) % MOD;
		rep(j, n) if(i >> j & 1) coef = 1ULL * coef * to[j][((1 << n) - 1) ^ i] % MOD;
		ans = (ans + coef) % MOD;
	}
	printf("%d\n", ans);
	return 0;
}