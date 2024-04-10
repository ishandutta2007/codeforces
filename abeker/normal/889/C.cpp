#include <bits/stdc++.h>
using namespace std;

const int MAXN = 1e6 + 5;
const int MOD = 1e9 + 7;

int N, K;
int fact[MAXN], inv[MAXN];
int pref[MAXN];
int dp[MAXN];

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

int main() {
	scanf("%d%d", &N, &K);
	
	fact[0] = inv[0] = 1;
	for (int i = 1; i <= N; i++) {
		fact[i] = mul(fact[i - 1], i);
		inv[i] = pot(fact[i], MOD - 2);
	}
	
	pref[0] = 1;
	for (int i = 1; i <= N; i++) {
		int tmp = pref[i - 1];
		if (i > K)
			tmp = add(tmp, -pref[i - K - 1]);
		dp[i] = mul(fact[i - 1], tmp);
		pref[i] = add(pref[i - 1], mul(dp[i], inv[i]));
	}
	
	printf("%d\n", add(fact[N], -mul(fact[N - 1], pref[N - 1])));
	
	return 0;
}