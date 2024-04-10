#include <bits/stdc++.h>

int main() {
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(0);

	int n, m, k;
	std::cin >> n >> m >> k;
	std::vector<std::set<int>> Sx(n), Sy(m);
	for (int i = 0; i < k; ++i) {
		int x, y;
		std::cin >> x >> y;
		--x, --y;
		Sx[x].insert(y);
		Sy[y].insert(x);
	}

	int sx = 0, sy = 0, tx = n, ty = m, d = 0;
	while (sx < tx && sy < ty) {
		if (d == 0) {
			auto it = Sx[sx].lower_bound(sy);
			int y = it == Sx[sx].end() ? ty : *it;
			while (ty > y) {
				--ty;
				if ((int)Sy[ty].size() != tx - sx) {
					std::cout << "No\n";
					return 0;
				}
				for (int x : Sy[ty]) {
					Sx[x].erase(ty);
				}
				Sy[ty].clear();
			}
			++sx;
			d = 1;
		} else if (d == 1) {
			auto it = Sy[ty - 1].lower_bound(sx);
			int x = it == Sy[ty - 1].end() ? tx : *it;
			while (tx > x) {
				--tx;
				if ((int)Sx[tx].size() != ty - sy) {
					std::cout << "No\n";
					return 0;
				}
				for (int y : Sx[tx]) {
					Sy[y].erase(tx);
				}
				Sx[tx].clear();
			}
			--ty;
			d = 2;
		} else if (d == 2) {
			auto it = Sx[tx - 1].upper_bound(ty);
			int y = it == Sx[tx - 1].begin() ? sy : *std::prev(it) + 1;
			while (sy < y) {
				if ((int)Sy[sy].size() != tx - sx) {
					std::cout << "No\n";
					return 0;
				}
				for (int x : Sy[sy]) {
					Sx[x].erase(sy);
				}
				Sy[sy].clear();
				++sy;
			}
			--tx;
			d = 3;
		} else if (d == 3) {
			auto it = Sy[sy].upper_bound(tx);
			int x = it == Sy[sy].begin() ? sx : *std::prev(it) + 1;
			while (sx < x) {
				if ((int)Sx[sx].size() != ty - sy) {
					std::cout << "No\n";
					return 0;
				}
				for (int y : Sx[sx]) {
					Sy[y].erase(sx);
				}
				Sx[sx].clear();
				++sx;
			}
			++sy;
			d = 0;
		}
	}
	std::cout << "Yes\n";
}