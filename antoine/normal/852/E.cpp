#include <iostream>
#include <algorithm>
#include <string>
#include <unordered_map>
#include <cstring>
#include <unordered_set>

const long long mod = 1000000007;

long long modPow(long long n, int k) {
	n %= mod;
	long long res = 1;
	while (k != 0) {
		if (k & 1)
			res = (res * n) % mod;
		k >>= 1;
		n = (n * n) % mod;
	}
	return res;
}

long long N;
int adj[100001] = { 0 };

int main() {
	std::ios::sync_with_stdio(false);
	std::cin.tie(nullptr);

	std::cin >> N;
	for (int i = 1; i < N; ++i) {
		int a, b;
		std::cin >> a >> b;
		++adj[a]; ++adj[b];
	}

	long long leaves = 0;
	for (int i = 1; i <= N; ++i)
		if (adj[i] == 1)
			++leaves;

	if (N == 1) {
		std::cout << "1\n";
		return 0;
	}

	long long ans = 0;
	ans += ((N - leaves) * modPow(2, N - leaves)) % mod;
	ans += (leaves * modPow(2, N - (leaves - 1))) % mod;
	ans %= mod;
	std::cout << ans << '\n';
	
	return 0;
}