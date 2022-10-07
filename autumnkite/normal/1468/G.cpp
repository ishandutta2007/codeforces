#include <bits/stdc++.h>

namespace geo {
	struct point {
		int x, y;

		point() : x(0), y(0) {}
		point(int _x, int _y) : x(_x), y(_y) {}
	};

	std::istream &operator>>(std::istream &in, point &a) {
		in >> a.x >> a.y;
		return in;
	}

	point operator-(const point &a, const point &b) {
		return point(a.x - b.x, a.y - b.y);
	}

	long long cross(const point &a, const point &b) {
		return 1ll * a.x * b.y - 1ll * a.y * b.x;
	}

	struct line {
		point a, b;

		line() {}
		line(const point &_a, const point &_b) : a(_a), b(_b) {}
	};

	std::pair<double, double> line_cross_point(const line &a, const line &b) {
		point u = a.a - b.a, v = a.b - a.a, w = b.b - b.a;
		double t = 1.0 * cross(w, u) / cross(v, w);
		return std::make_pair(a.a.x + v.x * t, a.a.y + v.y * t);
	}
}

int main() {
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(0);

	std::cout.setf(std::ios::fixed);
	std::cout.precision(12);

	int n, H;
	std::cin >> n >> H;
	std::vector<geo::point> a(n);
	for (int i = 0; i < n; ++i) {
		std::cin >> a[i];
	}

	geo::point O(a[n - 1].x, a[n - 1].y + H);

	std::vector<int> sta(1, n - 1);
	auto dist = [&](std::pair<double, double> a, std::pair<double, double> b) {
		return sqrt((a.first - b.first) * (a.first - b.first) + (a.second - b.second) * (a.second - b.second));
	};
	double ans = 0;
	for (int i = n - 2; i >= 0; --i) {
		long long type = geo::cross(a[i] - O, a[sta.back()] - O);
		if (type > 0) {
			auto tmp = geo::line_cross_point(geo::line(a[sta.back()], O), geo::line(a[i], a[i + 1]));
			ans += dist(std::make_pair(a[i].x, a[i].y), tmp);
			sta.push_back(i);
		} else if (type == 0) {
			if (sta.back() == i + 1) {
				ans += dist(std::make_pair(a[i].x, a[i].y), std::make_pair(a[i + 1].x, a[i + 1].y));
			}
			sta.push_back(i);
		}
	}
	std::cout << ans << "\n";
}