#include <bits/stdc++.h>

struct Point {
	int x, y;

	Point() : x(0), y(0) {}
	Point(int _x, int _y) : x(_x), y(_y) {}

	Point operator-(const Point &rhs) const {
		return Point(x - rhs.x, y - rhs.y);
	}
};

long long cross(const Point &a, const Point &b) {
	return 1ll * a.x * b.y - 1ll * a.y * b.x;
}

long long C3(int n) {
	return 1ll * n * (n - 1) * (n - 2) / 6;
}

long long C4(int n) {
	return 1ll * n * (n - 1) * (n - 2) * (n - 3) / 24;
}

long long solve(std::vector<Point> a) {
	int n = a.size();
	std::vector<Point> t1, t2;
	t1.reserve(n), t2.reserve(n);
	for (int i = 0; i < n; ++i) {
		if (a[i].x > 0) {
			t1.push_back(a[i]);
		} else {
			t2.push_back(a[i]);
		}
	}
	auto cmp = [&](const Point &a, const Point &b) {
		return cross(a, b) > 0;
	};
	std::sort(t1.begin(), t1.end(), cmp);
	std::sort(t2.begin(), t2.end(), cmp);
	std::copy(t1.begin(), t1.end(), a.begin());
	std::copy(t2.begin(), t2.end(), a.begin() + t1.size());
	long long ans = C4(n);
	a.insert(a.end(), a.begin(), a.end());
	for (int i = 0, j = 0; i < n; ++i) {
		while (j <= i || (j < i + n && cross(a[i], a[j]) > 0)) {
			++j;
		}
		ans -= C3(j - i - 1);
	}
	return ans;
}

int main() {
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(0);

	int n;
	std::cin >> n;
	std::vector<Point> a(n);
	for (int i = 0; i < n; ++i) {
		std::cin >> a[i].x >> a[i].y;
	}
	long long ans = 0;
	for (int i = 0; i < n; ++i) {
		std::vector<Point> p;
		p.reserve(n - 1);
		for (int j = 0; j < n; ++j) {
			if (j != i) {
				p.push_back(a[j] - a[i]);
			}
		}
		ans += solve(p);
	}
	std::cout << ans << "\n";
}