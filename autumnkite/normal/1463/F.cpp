#include <bits/stdc++.h>

int solve(int n, int x, int y) {
	if (int g = std::__gcd(x, y); g != 1) {
		return solve(n / g + 1, x / g, y / g) * (n % g) +
		       solve(n / g, x / g, y / g) * (g - n % g);
	}

	int m = x + y;
	std::vector<int> w(m, n / m);
	for (int i = 0; i < m; ++i) {
		int v = 1ll * i * x % m;
		if (v < n % m) {
			++w[i];
		}
	}

	int ans = 0;
	for (int st = 0; st < 2; ++st) {
		std::array<int, 2> f = {-n, -n};
		f[st] = 0;
		for (int v : w) {
			f = std::array<int, 2>{std::max(f[0], f[1]), f[0] + v};
		}
		ans = std::max(ans, f[st]);
	}
	return ans;
}

int main() {
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(0);

	int n, x, y;
	std::cin >> n >> x >> y;
	std::cout << solve(n, x, y) << "\n";
}