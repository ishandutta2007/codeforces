#include <bits/stdc++.h>

struct point {
	int x, y;

	point(int _x, int _y) : x(_x), y(_y) {}
	point() : point(0, 0) {}

	point operator+(const point &rhs) const {
		return point(x + rhs.x, y + rhs.y);
	}

	point operator-(const point &rhs) const {
		return point(x - rhs.x, y - rhs.y);
	}
};

long long cross(const point &a, const point &b) {
	return 1ll * a.x * b.y - 1ll * a.y * b.x;
}

int main() {
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(0);

	int n;
	std::cin >> n;
	long long S;
	std::cin >> S;
	std::vector<point> a(n);
	for (int i = 0; i < n; ++i) {
		std::cin >> a[i].x >> a[i].y;
	}
	for (int i = 1; i < n; ++i) {
		if (a[i].y < a[0].y || (a[i].y == a[0].y && a[i].x < a[0].x)) {
			std::swap(a[i], a[0]);
		}
	}
	std::sort(a.begin() + 1, a.end(), [&](point p, point q) {
		return cross(p - a[0], q - a[0]) > 0;
	});
	auto check = [&](point a, point b, point c) {
		return cross(b - a, c - b) > 0;
	};
	std::vector<point> p;
	for (int i = 0; i < n; ++i) {
		while ((int)p.size() > 1 && !check(p[p.size() - 2], p[p.size() - 1], a[i])) {
			p.pop_back();
		}
		p.push_back(a[i]);
	}

	n = p.size();
	auto prev = [&](int i) {
		if (i == 0) {
			return n - 1;
		} else {
			return i - 1;
		}
	};
	auto next = [&](int i) {
		if (i == n - 1) {
			return 0;
		} else {
			return i + 1;
		}
	};
	auto get_ans = [&](int i, int j, int k) {
		point a = p[i] + p[j] - p[k], b = p[i] + p[k] - p[j], c = p[j] + p[k] - p[i];
		std::cout << a.x << " " << a.y << "\n";
		std::cout << b.x << " " << b.y << "\n";
		std::cout << c.x << " " << c.y << "\n";
	};
	for (int i = 0; i < n; ++i) {
		for (int j = next(i), k = j; j != i; j = next(j)) {
			while (cross(p[i] - p[j], p[next(k)] - p[k]) < 0) {
				k = next(k);
			}
			while (cross(p[prev(k)] - p[k], p[j] - p[i]) >= 0) {
				if (cross(p[k] - p[i], p[next(j)] - p[j]) >= 0 && 
				    cross(p[prev(j)] - p[j], p[i] - p[k]) >= 0 &&
					cross(p[j] - p[k], p[next(i)] - p[i]) >= 0 &&
					cross(p[prev(i)] - p[i], p[k] - p[j]) >= 0) {
					get_ans(i, j, k);
					return 0;
				}
				k = next(k);
			}
			k = prev(k);
		}
	}
}