#include <bits/stdc++.h>

void solve() {
	std::array<std::array<bool, 8>, 8> a = {};
	for (int i = 0; i < 8; ++i) {
		for (int j = 0; j < 8; ++j) {
			a[i][j] = true;
		}
	}

	int x = 0, y = 0;
	std::cout << x + 1 << " " << y + 1 << std::endl;

	auto move = [&](int dx, int dy) {
		std::array<std::array<bool, 8>, 8> na = {};
		for (int i = 0; i < 8; ++i) {
			for (int j = 0; j < 8; ++j) {
				int ni = i + dx, nj = j + dy;
				if (0 <= ni && ni < 8 && 0 <= nj && nj < 8) {
					na[ni][nj] = a[i][j];
				}
			}
		}
		for (int i = 0; i < 8; ++i) {
			for (int j = 0; j < 8; ++j) {
				if (i == x || j == y || abs(i - x) == abs(j - y)) {
					na[i][j] = false;
				}
			}
		}
		a.swap(na);
	};
	while (1) {
		std::string s;
		std::cin >> s;
		if (s == "Done") {
			return;
		}
		int dx = 0, dy = 0;
		if (s.find('U') != s.npos) {
			dx = -1;
		}
		if (s.find('D') != s.npos) {
			dx = 1;
		}
		if (s.find('L') != s.npos) {
			dy = -1;
		}
		if (s.find('R') != s.npos) {
			dy = 1;
		}
		move(dx, dy);
		auto it = std::find(a[x + 1].begin(), a[x + 1].end(), true);
		if (it == a[x + 1].end()) {
			++x;
		} else {
			y = it - a[x + 1].begin();
		}
		std::cout << x + 1 << " " << y + 1 << std::endl;
	}
}

int main() {
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(0);
	
	int T;
	std::cin >> T;
	while (T--) {
		solve();
	}
}