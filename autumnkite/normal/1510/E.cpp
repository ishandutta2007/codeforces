#include <bits/stdc++.h>

int main() {
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(0);
	
	int n;
	double X, Y;
	std::cin >> n >> X >> Y;
	n /= 2;

	std::vector<std::vector<std::map<std::pair<int, int>, int>>> a(n + 1, 
	  std::vector<std::map<std::pair<int, int>, int>>(n * n + 1));
	for (int S = 0; S < (1 << n); ++S) {
		bool flag = true;
		int h = 0, x = 0, y = 0, s = 0;
		for (int i = 0; i < n; ++i) {
			if (S >> i & 1) {
				x += (6 * i + 3) * h + (3 * i + 2);
				y += (3 * h) * h + (3 * h + 1);
				s += 2 * h + 1;
				++h;
			} else {
				--h;
				if (h < 0) {
					flag = false;
					break;
				}
				x += (6 * i + 3) * h + (3 * i + 1);
				y += (3 * h) * h + (3 * h + 1);
				s += 2 * h + 1;
			}
		}
		if (!flag) {
			continue;
		}
		a[h][s][std::make_pair(x, y)] = S;
	}

	for (int h = 0; h <= n; ++h) {
		for (int s = 0; s <= n * n; ++s) {
			for (auto p : a[h][s]) {
				int x = p.first.first, y = p.first.second, S = p.second;
				for (int t = 0; t <= n * n; ++t) {
					double wx_ = X * 3 * (s + t), wy_ = Y * 3 * (s + t);
					int wx = wx_ + 0.5, wy = wy_ + 0.5;
					if (fabs(wx - wx_) / std::max(1, 3 * (s + t)) <= 1e-9 &&
					    fabs(wy - wy_) / std::max(1, 3 * (s + t)) <= 1e-6) {
						int nx = n * 6 * t - wx + x, ny = wy - y;
						if (a[h][t].count(std::make_pair(nx, ny))) {
							int T = a[h][t][std::make_pair(nx, ny)];
							for (int i = 0; i < n; ++i) {
								std::cout << ")("[S >> i & 1];
							}
							for (int i = n - 1; i >= 0; --i) {
								std::cout << "()"[T >> i & 1];
							}
							std::cout << "\n";
							return 0;
						}
					}
				}
			}
		}
	}
}