#include <bits/stdc++.h>

bool query(int u, int v) {
	std::cout << 1 << " " << u << " " << v << std::endl;
	int res;
	std::cin >> res;
	return res;
}

bool query(int u, std::vector<int> v) {
	std::cout << 2 << " " << u << " " << v.size() << " ";
	for (int x : v) {
		std::cout << x << " ";
	}
	std::cout << std::endl;
	int res;
	std::cin >> res;
	return res;
}

void solve() {
	int n;
	std::cin >> n;

	std::vector<int> p;
	for (int i = 0; i < n; ++i) {
		int l = 0, r = p.size();
		while (l < r) {
			int mid = (l + r - 1) >> 1;
			if (query(i, p[mid])) {
				r = mid;
			} else {
				l = mid + 1;
			}
		}
		p.insert(p.begin() + r, i);
	}

	std::vector<int> sta;
	for (int i = 0; i < n; ++i) {
		while (!sta.empty() && query(p[i], std::vector<int>(p.begin(), p.begin() + sta.back()))) {
			sta.pop_back();
		}
		sta.push_back(i + 1);
	}

	std::vector<std::vector<bool>> ans(n, std::vector<bool>(n));
	int lst = 0;
	for (int x : sta) {
		for (int i = lst; i < x; ++i) {
			for (int j = lst; j < n; ++j) {
				ans[p[i]][p[j]] = true;
			}
		}
		lst = x;
	}

	std::cout << 3 << "\n";
	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < n; ++j) {
			std::cout << (int)ans[i][j];
		}
		std::cout << "\n";
	}
	std::cout << std::flush;
	int res;
	std::cin >> res;
	assert(res == 1);
}

int main() {
	std::ios_base::sync_with_stdio(false);

	int T;
	std::cin >> T;
	while (T--) {
		solve();
	}
}