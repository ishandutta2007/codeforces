#include <bits/stdc++.h>
using namespace std;

const int MAXN = 2e5 + 5;
const int MOD = 998244353;

int N, K;
vector <int> p[2];
int dp[MAXN][2];
int pot[MAXN];

void load() {
	scanf("%d%d", &N, &K);
	for (int i = 0; i < 2; i++)
		p[i].push_back(0);
	for (int i = 0; i < N; i++) {
		int x;
		scanf("%d", &x);
		p[i % 2].push_back(x);
	}
}

inline int add(int x, int y) {
	x += y;
	if (x >= MOD)
		return x - MOD;
	return x;
}

inline int mul(int x, int y) {
	return (long long)x * y % MOD;
}

int get(int len, int a, int b) {
	if (a && b)
		return dp[len][a != b];
	if (!a && !b)
		return mul(K, pot[len - 1]);
	return pot[len];
}

int calc(vector <int> v) {
	v.push_back(0);
	int lst = 0, res = 1;
	for (int i = 1; i < v.size(); i++)
		if (v[i] != -1) {
			res = mul(res, get(i - lst - 1, v[lst], v[i]));
			lst = i;
		}
	return res;
}

int solve() {
	dp[0][1] = 1;
	pot[0] = 1;
	for (int i = 1; i <= N; i++) {
		dp[i][0] = mul(K - 1, dp[i - 1][1]);
		dp[i][1] = add(dp[i - 1][0], mul(K - 2, dp[i - 1][1]));
		pot[i] = mul(pot[i - 1], K - 1);
	}
	
	return mul(calc(p[0]), calc(p[1]));
}

int main() {
	load();
	printf("%d\n", solve());
	return 0;
}