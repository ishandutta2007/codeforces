#include <bits/stdc++.h>

std::mt19937_64 rnd(time(0));

int main() {
	std::ios_base::sync_with_stdio(false);

	int n, m;
	std::cin >> n >> m;
	std::vector<int> a(n);
	while (m--) {
		std::string s;
		std::cin >> s;
		double t[2] = {0, 0};
		for (int i = 0; i < n; ++i) {
			t[s[i] - '0'] += pow(0.75, a[i]);
		}
		if (1.0 * (rnd() % (long long)(1e18)) / 1e18 < t[0] / (t[0] + t[1])) {
			std::cout << 0 << std::endl;
		} else {
			std::cout << 1 << std::endl;
		}
		int x;
		std::cin >> x;
		for (int i = 0; i < n; ++i) {
			a[i] += s[i] - '0' != x;
		}
	}
}