//n^5 for 100. What a nice problem.
#include <bits/stdc++.h>
#define rep(i, n) for(int i = 0; i < (int)(n); i ++)
#define rep1(i, n) for(int i = 1; i <= (int)(n); i ++)
#define MP make_pair

using namespace std;
typedef long long LL;
typedef pair<int, int> PII;
const int MOD = 998244353;

int n, m, k, p;
int dp[105][105], ndp[105][105];
int fac[105], comb[105][105];

int main()
{
	scanf("%d%d%d%d", &n, &m, &k, &p);
	if(m + k - 1 > n) {
		printf("0\n"); return 0;
	}
	fac[0] = 1;
	rep1(i, 100) fac[i] = 1LL * fac[i - 1] * i % p;
	comb[0][0] = 1;
	rep1(i, 100) {
		comb[i][0] = 1;
		rep1(j, i) comb[i][j] = (comb[i - 1][j - 1] + comb[i - 1][j]) % p;
	}
	
	dp[0][0] = 1;
	rep1(i, n) dp[1][i] = fac[i];
	for(int i = m - 1; i >= 1; i --) {
		memset(ndp, 0, sizeof(ndp));
		int maxn = n - i + 1, maxk = min(maxn, k);
		ndp[0][0] = 1;
		for(int u0 = 0; u0 <= maxk; u0 ++) rep1(v0, maxn) for(int u1 = 0; u1 <= u0; u1 ++) rep(v1, v0)
		ndp[u0][v0] = (ndp[u0][v0] + 1ULL * dp[u1][v1] * dp[u0 - u1][v0 - v1 - 1] % p * comb[v0 - 1][v1]) % p;
		memcpy(dp, ndp, sizeof(dp));
	}
	printf("%d\n", dp[k][n]);
	return 0;
}