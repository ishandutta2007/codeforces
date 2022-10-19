#include <bits/stdc++.h>
using namespace std;

const int MAXN = 2e3 + 5;
const int MOD = 998244353;

int N, M, K;
int dp[MAXN][MAXN];

inline int add(int x, int y) {
	x += y;
	if (x >= MOD)
		x -= MOD;
	return x;
}

inline int mul(int x, int y) {
	return (long long)x * y % MOD;
}

int rec(int pos, int cnt) {
	int &ref = dp[pos][cnt];
	if (ref != -1)
		return ref;
	ref = rec(pos - 1, cnt);
	if (cnt)
		ref = add(ref, mul(rec(pos - 1, cnt - 1), M - 1));
	return ref;
}

int main() {
	scanf("%d%d%d", &N, &M, &K);
	
	memset(dp, -1, sizeof dp);
	dp[1][0] = M;
	for (int i = 1; i < MAXN; i++)
		dp[1][i] = 0;
		
	printf("%d\n", rec(N, K));
	
	return 0;
}