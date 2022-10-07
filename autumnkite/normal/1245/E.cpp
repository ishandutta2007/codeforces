#include <bits/stdc++.h>

int main() {
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(0);

	std::cout.setf(std::ios::fixed);
	std::cout.precision(12);

	const int n = 10, m = 10;
	std::vector<std::vector<int>> id(n, std::vector<int>(m));
	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < m; ++j) {
			if (i & 1) {
				id[i][j] = i * m + m - j - 1;
			} else {
				id[i][j] = i * m + j;
			}
		}
	}
	std::vector<int> nxt(n * m, -1);
	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < m; ++j) {
			int h;
			std::cin >> h;
			if (h != 0) {
				nxt[id[i][j]] = id[i - h][j];
			}
		}
	}
	
	std::vector<double> f(n * m);
	f[0] = 0;
	for (int i = 1; i < n * m; ++i) {
		int cnt = 0;
		for (int j = 1; j <= 6; ++j) {
			if (i >= j) {
				if (nxt[i - j] != -1) {
					f[i] += std::min(f[i - j], f[nxt[i - j]]);
				} else {
					f[i] += f[i - j];
				}
				++cnt;
			} else {
				++f[i];
			}
		}
		f[i] /= cnt;
		++f[i];
	}
	std::cout << f.back() << "\n";
}