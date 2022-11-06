#include <iostream>
#include <algorithm>
#include <cstring>
#include <string>
#include <vector>
#include <set>
#include <map>

long long mod = 1000000007;

long long modPow(long long n, long long k) {
	n %= mod;
	if (k == 0)
		return 1;
	if (k & 1)
		return (n*modPow(n, k - 1)) % mod;
	return modPow(n*n, k >> 1);
}

int main() {
	std::ios::sync_with_stdio(false);
	std::cin.tie(nullptr);
	std::cout.tie(nullptr);
	long long n, m, k;
	std::cin >> n >> m >> k;
	std::cout << ((((n^m) & 1) && k == -1) ? 0 : modPow(2, (((n - 1) % (mod - 1)) * ((m - 1) % (mod - 1)))%(mod-1)));

	return 0;
}