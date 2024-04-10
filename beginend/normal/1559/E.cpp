#include<bits/stdc++.h>
using namespace std;

const int N = 55;
const int M = 100005;
const int MOD = 998244353;

int n, m, l[N], r[N], dp[N][M], mu[M], prime[M], tot;
bool not_prime[M];

void get_prime(int n) {
	mu[1] = 1;
	for (int i = 2; i <= n; i++) {
		if (!not_prime[i]) prime[++tot] = i, mu[i] = -1;
		for (int j = 1; j <= tot && i * prime[j] <= n; j++) {
			not_prime[i * prime[j]] = 1;
			if (i % prime[j] == 0) break;
			mu[i * prime[j]] = -mu[i];
		}
	}
}

int solve(int div) {
	int m1 = m / div;
	for (int i = 0; i <= m1; i++) dp[0][i] = 1;
	for (int i = 1; i <= n; i++) {
		int l1 = (l[i] + div - 1) / div, r1 = r[i] / div;
		for (int j = 0; j <= m1; j++)
			if (j < l1) dp[i][j] = 0;
			else if (j < r1 + 1) dp[i][j] = dp[i - 1][j - l1];
			else dp[i][j] = (dp[i - 1][j - l1] - dp[i - 1][j - r1 - 1]) % MOD;
		for (int j = 1; j <= m1; j++) (dp[i][j] += dp[i][j - 1]) %= MOD;
	}
	return dp[n][m1];
}

int main() {
	scanf("%d%d", &n, &m);
	for (int i = 1; i <= n; i++) scanf("%d%d", &l[i], &r[i]);
	get_prime(m);
	int ans = 0;
	for (int i = 1; i <= m; i++)
		if (mu[i]) (ans += solve(i) * mu[i]) %= MOD;
	printf("%d\n", (ans + MOD) % MOD);
	return 0;
}