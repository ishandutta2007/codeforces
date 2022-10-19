#include <bits/stdc++.h>
using namespace std;

const int MAXN = 3e3 + 5;
const int MOD = 1e9 + 7;

int N, D;
vector <int> ch[MAXN];
int fact[MAXN], inv[MAXN];
int pre[MAXN];
int dp[MAXN][MAXN];
int actual[MAXN];

void load() {
	scanf("%d%d", &N, &D);
	for (int i = 2; i <= N; i++) {
		int par;
		scanf("%d", &par);
		ch[par].push_back(i);
	}
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

int choose(int n, int k) {
	return mul(fact[n], mul(inv[k], inv[n - k]));
}

void dfs(int x) {
	for (auto it : ch[x])
		dfs(it);
	
	for (int i = 1; i <= N; i++) {
		int prod = 1;
		for (auto it : ch[x])
			prod = mul(prod, dp[it][i]);
		dp[x][i] = add(dp[x][i - 1], prod);
	}
}

int solve() {
	dfs(1);
	
	fact[0] = inv[0] = 1;
	for (int i = 1; i <= N; i++) {
		fact[i] = mul(fact[i - 1], i);
		inv[i] = pot(fact[i], MOD - 2);
	}
	
	int ans = 0, prod = 1;
	for (int i = 1; i <= N; i++) {
		prod = mul(prod, D - i + 1);
		actual[i] = dp[1][i];
		for (int j = 1; j < i; j++)
			actual[i] = add(actual[i], -mul(choose(i, j), actual[j]));
		ans = add(ans, mul(mul(prod, inv[i]), actual[i]));
	}
	
	return ans;
}

int main() {
	load();
	printf("%d\n", solve());
	return 0;
}