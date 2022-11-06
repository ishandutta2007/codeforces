#include <iostream>
#include <algorithm>
#include <cstring>


long long gcd(long long a, long long b) {
	return 0LL;
}
long long mod = 1000000007LL;

int main() {
	std::ios::sync_with_stdio(false);
	std::cin.tie(nullptr);
	int n, k;
	std::cin >> n >> k;
	int curr = 0;
	for (int i = 1; i <= n; ++i) {
		int a;
		std::cin >> a;
		curr += a;
		if (curr >= 8) {
			curr -= 8;
			k -= 8;
		}
		else {
			k -= curr;
			curr = 0;
		}
		if (k <= 0) {
			std::cout << i << '\n';
			return 0;
		}
	}
	std::cout << "-1\n";
	return 0;
}