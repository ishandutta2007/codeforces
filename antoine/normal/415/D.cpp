#include <iostream>
#include <algorithm>
#include <cstring>

long long dp[2001][2001];

int N;

long long f(int n, int k) {
	if (n < 1 || n > N) return 0;
	if (k == 1) return 1;
	if (dp[n][k] != -1) return dp[n][k];

	long long ans = 0;
	for (int i = 1; n*i <= N; ++i)
		ans = (ans + f(n*i, k - 1)) % 1000000007LL;

	return dp[n][k] = ans;
}

int main() {
	int K;
	std::cin >> N >> K;
	long long ans = 0;
	std::memset(dp, -1, sizeof dp);
	for (int n = 1; n <= N; ++n)
		ans = (ans + f(n, K)) % 1000000007LL;
	std::cout << ans;
	return 0;
}