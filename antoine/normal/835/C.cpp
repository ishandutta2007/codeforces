#include <iostream>
#include <algorithm>
#include <cstring>
#include <map>
#include <vector>
#include <string>
#include <stack>
#include <queue>

int n, q, c;

int ans[101][101][11];

int main() {
	std::ios::sync_with_stdio(false);
	std::cin.tie(nullptr);
	std::memset(ans, 0, sizeof ans);
	std::cin >> n >> q >> c;
	for (int i = 0; i < n; ++i) {
		int x, y, s;
		std::cin >> x >> y >> s;
		for (int t = 0; t <= c; ++t)
			ans[x][y][t] += (s + t) % (c + 1);
	}

	for (int t = 0; t <= c; ++t)
		for (int x = 1; x <= 100; ++x)
			for (int y = 1; y <= 100; ++y)
				ans[x][y][t] += ans[x - 1][y][t] + ans[x][y - 1][t] - ans[x - 1][y - 1][t];

	for (; q > 0; --q) {
		int t, x1, y1, x2, y2;
		std::cin >> t >> x1 >> y1 >> x2 >> y2;
		t %= (c + 1);
		std::cout << (ans[x2][y2][t] - ans[x1 - 1][y2][t] - ans[x2][y1 - 1][t] + ans[x1 - 1][y1 - 1][t]) << '\n';
	}
	return 0;
}