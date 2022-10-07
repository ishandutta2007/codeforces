#include <bits/stdc++.h>

int main() {
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(0);

	int T;
	std::cin >> T;
	while (T--) {
		long long n, a, b, c;
		std::cin >> n >> a >> b >> c;
		auto calc = [&](long long x) {
			return (x - n % x) % x;
		};
		std::cout << std::min({calc(a), calc(b), calc(c)}) << "\n";
	}
}