#include <cstdio>
#include <cmath>
#include <cstring>
#include <algorithm>
#include <vector>

#define debug(...) fprintf(stderr, __VA_ARGS__)

namespace Geometry {
	const double eps = 1e-9;

	int sgn(double x) {
		return x >= eps ? 1 : (x <= -eps ? -1 : 0);
	}

	struct Point {
		double x, y;

		void read() {
			scanf("%lf%lf", &x, &y);
		}

		Point operator + (const Point &a) const {
			return {x + a.x, y + a.y};
		}

		Point operator - (const Point &a) const {
			return {x - a.x, y - a.y};
		}

		Point operator * (const double k) const {
			return {x * k, y * k};
		}

		Point operator / (const double k) const {
			return {x / k, y / k};
		}

		double len2() const {
			return x * x + y * y;
		}

		double len() const {
			return sqrt(len2());
		}
	};

	double cross(const Point &a, const Point &b) {
		return a.x * b.y - a.y * b.x;
	}
}
using namespace Geometry;

int n, k;

int get(Point a) {
	if (sgn(a.x) == 0 && sgn(a.y) == 0) {
		return 2;
	}
	return sgn(a.y) > 0 || (sgn(a.y) == 0 && sgn(a.x) > 0);
}

void solve() {
	scanf("%d%d", &n, &k);
	std::vector<Point> p1, p2;
	for (int i = 0; i < n; ++i) {
		Point p;
		p.read();
		int x = get(p);
		if (x == 2) {
			continue;
		} else if (x == 1) {
			p1.push_back(p);
		} else {
			p2.push_back(p);
		}
	}
	auto cmp_angle = [&](const Point &a, const Point &b) {
		return cross(a, b) > 0;
	};
	std::sort(p1.begin(), p1.end(), cmp_angle);
	std::sort(p2.begin(), p2.end(), cmp_angle);
	std::vector<std::vector<Point>> l;
	for (int i = 0; i < (int)p1.size(); ++i) {
		if (i == 0 || sgn(cross(p1[i], p1[i - 1])) != 0) {
			l.push_back({p1[i]});
		} else {
			l.back().push_back(p1[i]);
		}
	}
	for (int i = 0; i < (int)p2.size(); ++i) {
		if (i == 0 || sgn(cross(p2[i], p2[i - 1])) != 0) {
			l.push_back({p2[i]});
		} else {
			l.back().push_back(p2[i]);
		}
	}
	auto cmp_len = [&](const Point &a, const Point &b) {
		return a.len2() < b.len2();
	};
	std::vector<std::pair<double, int>> ct;
	int idx = 0;
	for (auto &v : l) {
		std::sort(v.begin(), v.end(), cmp_len);
		int cnt = (int)v.size();
		for (int i = 0; i < cnt; ++i) {
			ct.push_back({v[i].len() * (k - 1 - 2 * (cnt - i - 1)), idx++});
		}
	}
	std::sort(ct.begin(), ct.end());
	std::reverse(ct.begin(), ct.end());
	std::vector<int> vis(idx);
	double ans = 0;
	int now = 0;
	for (auto v : ct) {
		double c = v.first;
		int id = v.second;
		if (sgn(c) <= 0 || now == k) {
			break;
		}
		ans += c, vis[id] = 1, ++now;
	}
	if (now < k) {
		++now;
		idx = 0;
		int t = k / 2;
		for (auto &v : l) {
			int cnt = (int)v.size();
			double s = 0;
			for (int i = 0; i < cnt; ++i) {
				if (vis[idx++] || now == k) {
					continue;
				}
				double d = v[i].len();
				++now, ans += d * (k - 1 - 2 * t) - s * 2;
				s += d;
			}
		}
	}
	printf("%.10lf\n", ans);
}

int main() {
	int T = 1;
	// read(T);
	while (T--) {
		solve();
	}
}