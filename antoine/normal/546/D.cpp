#include <iostream>
#include <algorithm>
#include <cstring>
#include <functional>
#include <vector>
#include <map>

#define SIEVE_MAX 5000000

int dp[SIEVE_MAX + 1];

int main() {
	std::ios::sync_with_stdio(false);
	std::cin.tie(nullptr);
	std::cout.tie(nullptr);
	
	for (int i = 2; i*i <= SIEVE_MAX; ++i)
		if (dp[i] == 0) {
			for (int j = i*i; j <= SIEVE_MAX; j += i)
				dp[j] = i;
		}

	dp[1] = 0;
	for (int i = 2; i <= SIEVE_MAX; ++i) {
		if (dp[i] == 0)
			dp[i] = 1;
		else
			dp[i] = 1 + dp[i / dp[i]];
	}

	for (int i = 2; i <= SIEVE_MAX; ++i)
		dp[i] += dp[i - 1];

	int t;
	std::cin >> t;
	for (; t > 0; --t) {
		int a, b;
		std::cin >> a >> b;
		std::cout << dp[a] - dp[b] << "\n";
	}
	return 0;
}