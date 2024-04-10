#include <bits/stdc++.h>

int main() {
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(0);

	int n;
	std::cin >> n;
	std::vector<int> a(n);
	for (int i = 0; i < n; ++i) {
		std::cin >> a[i];
	}
	std::string s;
	std::cin >> s;
	std::sort(s.begin(), s.end());

	if ((int)s.size() == 1 || s == "+-") {
		for (int i = 0; i < n; ++i) {
			std::cout << a[i];
			if (i < n - 1) {
				std::cout << s[0];
			}
		}
		std::cout << "\n";
		return 0;
	}

	s.resize(2);
	if (s == "*-") {
		bool flag = false;
		for (int i = 0; i < n; ++i) {
			std::cout << a[i];
			if (i < n - 1) {
				if (!flag && a[i + 1] == 0) {
					std::cout << "-";
					flag = true;
				} else {
					std::cout << "*";
				}
			}
		}
		std::cout << "\n";
		return 0;
	}
	
	std::string ans(n - 1, '+');
	auto solve = [&](int L, int R) {
		std::vector<std::pair<int, int>> vec;
		std::vector<int> val;
		const int INF = 2 * (R - L) + 1;
		for (int i = L; i < R; ++i) {
			if (a[i] >= 2) {
				int l = i, r = i;
				int mul = 1;
				while (r < R && a[r] >= 2) {
					mul = std::min<long long>(1ll * mul * a[r], INF);
					if (r > l) {
						ans[r - 1] = '*';
					}
					++r;
				}
				vec.emplace_back(l, r);
				val.push_back(mul);
				i = r;
			}
		}
		int m = vec.size();
		if (!m) {
			for (int i = L; i < R - 1; ++i) {
				ans[i] = '+';
			}
			return;
		}
		for (int i = L; i < vec[0].first; ++i) {
			ans[i] = '+';
		}
		for (int i = vec[m - 1].second; i < R; ++i) {
			ans[i - 1] = '+';
		}
		int mul = 1;
		for (int v : val) {
			mul = std::min<long long>(INF, 1ll * mul * v);
		}
		if (mul == INF) {
			for (int i = vec[0].first; i < vec[m - 1].second - 1; ++i) {
				ans[i] = '*';
			}
			return;
		}
		int mx_val = 0, mx_S = 0;
		for (int S = 0; S < (1 << (m - 1)); ++S) {
			int pro = val[0], sum = 0;
			for (int i = 0; i < m - 1; ++i) {
				if (S >> i & 1) {
					sum += pro + vec[i + 1].first - vec[i].second;
					pro = 1;
				}
				pro *= val[i + 1];
			}
			sum += pro;
			if (sum > mx_val) {
				mx_val = sum;
				mx_S = S;
			}
		}
		for (int i = 0; i < m - 1; ++i) {
			for (int j = vec[i].second - 1; j < vec[i + 1].first; ++j) {
				ans[j] = mx_S >> i & 1 ? '+' : '*';
			}
		}
	};
	int lst = 0;
	for (int i = 0; i < n; ++i) {
		if (a[i] == 0) {
			if (i > 0) {
				ans[i - 1] = '+';
			}
			if (i < n - 1) {
				ans[i] = '+';
			}
			if (lst < i) {
				solve(lst, i);
			}
			lst = i + 1;
		}
	}
	if (lst < n) {
		solve(lst, n);
	}
	
	for (int i = 0; i < n; ++i) {
		std::cout << a[i];
		if (i < n - 1) {
			std::cout << ans[i];
		}
	}
	std::cout << "\n";
}