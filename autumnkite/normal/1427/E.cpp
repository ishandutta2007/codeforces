#include <bits/stdc++.h>

int main() {
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(0);

	int x;
	std::cin >> x;
	std::vector<std::tuple<long long, long long, int>> ans;
	long long y = x;
	for (int i = 0; x >> (i + 1); ++i) {
		ans.emplace_back(y, y, 0);
		y <<= 1;
	}
	ans.emplace_back(x, y, 1);
	long long z = x ^ y;

	long long k = 0;
	while (k * z % (2 * x) != 1) {
		++k;
	}
	long long p = (k * z - 1) / x;
	
	auto mul = [&](long long a, long long b) {
		long long s = 0;
		bool flag = true;
		for (; b; b >>= 1) {
			if (b & 1) {
				if (!flag) {
					ans.emplace_back(s, a, 0);
				}
				flag = false;
				s += a;
			}
			ans.emplace_back(a, a, 0);
			a += a;
		}
	};

	mul(x, p), mul(z, k);
	ans.emplace_back(k * z, p * x, 1);

	std::cout << ans.size() << "\n";
	for (auto [x, y, op] : ans) {
		std::cout << x << " " << (op == 0 ? '+' : '^') << " " << y << "\n";
	}
}