#include <bits/stdc++.h>

int main() {
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(0);

	int n, m;
	std::cin >> n >> m;
	std::vector<std::string> a(n);
	int mni = n, mxi = 0, mnj = m, mxj = 0;
	for (int i = 0; i < n; ++i) {
		std::cin >> a[i];
		for (int j = 0; j < m; ++j) {
			if (a[i][j] == 'B') {
				mni = std::min(mni, i);
				mxi = std::max(mxi, i);
				mnj = std::min(mnj, j);
				mxj = std::max(mxj, j);
			}
		}
	}
	std::cout << (mni + mxi) / 2 + 1 << " " << (mnj + mxj) / 2 + 1 << "\n";
}