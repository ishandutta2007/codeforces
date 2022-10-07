#include <bits/stdc++.h>

int main() {
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(0);

	std::string s;
	std::cin >> s;
	s = '0' + s;
	int n = s.size();

	int lim_x = 5 * n, lim_c = lim_x / 9 + 1, inf = lim_x * n + 1;
	std::vector<std::vector<std::vector<std::array<int, 2>>>> f(n,
	  std::vector<std::vector<std::array<int, 2>>>(2 * lim_c + 1,
	  std::vector<std::array<int, 2>>(2 * lim_x + 1,
	  std::array<int, 2>({-1, -1}))));
	
	auto upd = [&](int &a, int b) {
		a = std::min(a, b);
	};

	std::function<int(int, int, int, int)> DP = [&](int k, int c, int x, int d) {
		if (k == n) {
			return c == 0 ? 0 : inf;
		}
		if (abs(c) > lim_c || abs(x) > lim_x) {
			return inf;
		}
		int &ans = f[k][c + lim_c][x + lim_x][d == 1];
		if (ans != -1) {
			return ans;
		}
		ans = inf;
		upd(ans, DP(k, c, x + d, d) + n - k);
		upd(ans, DP(k + 1, c * 10 + s[k] - '0' - x, x, 1));
		upd(ans, DP(k + 1, c * 10 + s[k] - '0' - x, x, -1));
		return ans;
	};

	std::cout << DP(0, 0, 0, 1) << "\n";
}