#include <bits/stdc++.h>

int get_log(int n) {
	int res = 1;
	while ((1 << res) < n) {
		++res;
	}
	return res;
}

class sparse_table {
	int n, LG;
	std::vector<int> Log;
	std::vector<std::vector<long long>> st;

public:
	sparse_table(std::vector<long long> a) : n(a.size()), LG(get_log(n + 1)), Log(n + 1),
	                                         st(LG, std::vector<long long>(n)) {
		Log[1] = 0;
		for (int i = 2; i <= n; ++i) {
			Log[i] = Log[i >> 1] + 1;
		}
		for (int i = 0; i < n; ++i) {
			st[0][i] = a[i];
		}
		for (int i = 1; i < LG; ++i) {
			for (int j = 0; j + (1 << i) <= n; ++j) {
				st[i][j] = std::max(st[i - 1][j], st[i - 1][j + (1 << (i - 1))]);
			}
		}
	}

	long long range_max(int l, int r) {
		int t = Log[r - l];
		return std::max(st[t][l], st[t][r - (1 << t)]);
	}
};

int main() {
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(0);

	int n, a;
	std::cin >> n >> a;
	std::vector<int> d(n), c(n);
	for (int i = 0; i < n; ++i) {
		std::cin >> d[i] >> c[i];
		c[i] = a - c[i];
	}

	std::vector<long long> sum(n + 1);
	for (int i = 0; i < n; ++i) {
		sum[i + 1] = sum[i] + c[i];
	}
	std::vector<long long> tmp(n + 1);
	for (int i = 0; i <= n; ++i) {
		tmp[i] = -sum[i];
	}

	sparse_table st1(sum), st2(tmp);

	std::vector<int> sta;
	std::vector<int> l(n - 1), r(n - 1);
	auto calc = [&](int i) {
		return 1ll * (d[i] - d[i + 1]) * (d[i] - d[i + 1]);
	};
	sta.push_back(-1);
	for (int i = 0; i < n - 1; ++i) {
		while ((int)sta.size() > 1 && calc(sta.back()) <= calc(i)) {
			sta.pop_back();
		}
		l[i] = sta.back();
		sta.push_back(i);
	}
	sta.clear();
	sta.push_back(n - 1);
	for (int i = n - 2; i >= 0; --i) {
		while ((int)sta.size() > 1 && calc(sta.back()) <= calc(i)) {
			sta.pop_back();
		}
		r[i] = sta.back();
		sta.push_back(i);
	}

	long long ans = std::max(0, *std::max_element(c.begin(), c.end()));
	for (int i = 0; i < n - 1; ++i) {
		ans = std::max(ans, st2.range_max(l[i] + 1, i + 1) + st1.range_max(i + 2, r[i] + 2) - calc(i));
	}
	std::cout << ans << "\n";
}