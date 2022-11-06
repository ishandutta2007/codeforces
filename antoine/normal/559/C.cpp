#include <iostream>
#include <algorithm>
#include <cstring>

// chess
//http://codeforces.com/problemset/problem/559/C
const int mod = 1000000007;

long long modPow(long long n, int p) {
	long long ans = 1;
	while (p != 0) {
		if (p & 1)
			ans = (ans * n) % mod;
		n = (n * n) % mod;
		p >>= 1;
	}
	return ans;
}

long long fact[200001];
long long invFact[200001];

long long choose(int n, int k) {
	return (((fact[n] * invFact[k]) % mod) * invFact[n - k]) % mod;
}

int h, w, n;
int r[2001];
int c[2001];
long long dp[2001];

int main() {
	std::ios::sync_with_stdio(false);
	std::cin.tie(nullptr);
	std::cin >> h >> w >> n;
	static std::pair<int, int> blacks[2000];
	for (int i = 0; i < n; ++i)
		std::cin >> blacks[i].first >> blacks[i].second;
	std::sort(blacks, blacks + n, [](const std::pair<int, int> &lhs, const std::pair<int, int> &rhs) {
		return lhs.first + lhs.second < rhs.first + rhs.second;
	});
	for (int i = 0; i < n; ++i) {
		r[i] = blacks[i].first;
		c[i] = blacks[i].second;
	}
	r[n] = h;
	c[n] = w;

	// fact
	fact[0] = 1;
	invFact[0] = 1;
	for (int i = 1; i <= w + h; ++i) {
		fact[i] = fact[i - 1] * i;
		fact[i] %= mod;
		invFact[i] = modPow(fact[i], mod - 2);
	}

	// dp
	for (int i = 0; i <= n; ++i)
		dp[i] = choose(r[i] + c[i] - 2, r[i] - 1);

	for (int i = 0; i < n; ++i) {
		for (int j = i + 1; j <= n; ++j) {
			if (r[i] + c[i] == r[j] + c[j] || r[i] > r[j] || c[i] > c[j])
				continue;
			int dR = r[j] - r[i];
			int dC = c[j] - c[i];
			dp[j] -= (dp[i] * choose(dR + dC, dR)) % mod;
			dp[j] += mod;
			dp[j] %= mod;
		}
	}
	std::cout << dp[n];
	return 0;
}