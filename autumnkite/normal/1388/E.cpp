#include <bits/stdc++.h>

const double eps = 1e-9;

struct segment {
	int l, r, y;
};

int main() {
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(0);

	int n;
	std::cin >> n;
	std::vector<segment> a(n);
	for (int i = 0; i < n; ++i) {
		std::cin >> a[i].l >> a[i].r >> a[i].y;
	}

	std::vector<std::pair<double, double>> t;
	t.emplace_back(0, 0);
	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < n; ++j) {
			if (a[i].y < a[j].y) {
				t.emplace_back(1.0 * (a[i].l - a[j].r) / (a[j].y - a[i].y), 
				               1.0 * (a[i].r - a[j].l) / (a[j].y - a[i].y));
			}
		}
	}
	std::sort(t.begin(), t.end());
	std::vector<std::pair<double, double>> s;
	for (auto p : t) {
		if (!s.empty() && p.first <= s.back().second - eps) {
			s.back().second = std::max(s.back().second, p.second);
		} else {
			s.push_back(p);
		}
	}

	std::vector<double> pos;
	for (auto p : s) {
		pos.push_back(p.first);
		pos.push_back(p.second);
	}
	int sz = 0;
	for (auto p : pos) {
		if (!sz || fabs(pos[sz - 1] - p) >= eps) {
			pos[sz++] = p;
		}
	}
	pos.resize(sz);

	auto calc = [&](double x) {
		double l = 1e100, r = -1e100;
		for (int i = 0; i < n; ++i) {
			l = std::min(l, a[i].l + a[i].y * x);
			r = std::max(r, a[i].r + a[i].y * x);
		}
		return r - l;
	};

	int l = 1, r = (int)pos.size() - 1, ans = 0;
	while (l <= r) {
		int mid = (l + r) >> 1;
		if (calc(pos[mid]) <= calc(pos[mid - 1]) - eps) {
			ans = mid;
			l = mid + 1;
		} else {
			r = mid - 1;
		}
	}

	std::cout.setf(std::ios::fixed);
	std::cout.precision(12);
	std::cout << calc(pos[ans]) << "\n";
}