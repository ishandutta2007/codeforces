#include <cstdio>
#include <cmath>
#include <algorithm>
#include <set>

namespace Geometry {
	long double eps = 1e-9;

	int sgn(long double x) {
		return x >= eps ? 1 : (x <= -eps ? -1 : 0);
	}

	struct Point {
		long double x, y;

		void read() {
			double _x, _y;
			scanf("%lf%lf", &_x, &_y);
			x = _x, y = _y;
		}

		Point operator + (const Point &rhs) const {
			return {x + rhs.x, y + rhs.y};
		}

		Point operator - (const Point &rhs) const {
			return {x - rhs.x, y - rhs.y};
		}

		Point operator * (const long double k) const {
			return {x * k, y * k};
		}

		Point operator / (const long double k) const {
			return {x / k, y / k};
		}

		long double len() {
			return sqrt(x * x + y * y);
		}

		Point unit() {
			return *this / len();
		}
	};

	long double dot(const Point &a, const Point &b) {
		return a.x * b.x + a.y * b.y;
	}

	long double cross(const Point &a, const Point &b) {
		return a.x * b.y - a.y * b.x;
	}

	struct Line {
		Point a, b;

		long double get_y(long double x) {
			return (a + (b - a) * (x - a.x) / (b.x - a.x)).y;
		}
	};

	bool __segment_intersection(const Line &a, const Line &b) {
		if (sgn(std::min(a.a.x, a.b.x) - std::max(b.a.x, b.b.x)) > 0) {
			return 0;
		}
		if (sgn(std::min(a.a.y, a.b.y) - std::max(b.a.y, b.b.y)) > 0) {
			return 0;
		}
		long double t1 = cross(b.a - a.a, a.b - a.a);
		long double t2 = cross(b.b - a.a, a.b - a.a);
		if (sgn(t1) * sgn(t2) > 0) {
			return 0;
		}
		return 1;
	}

	bool segment_intersection(const Line &a, const Line &b) {
		return __segment_intersection(a, b) && __segment_intersection(b, a);
	}
}
using namespace Geometry;

const int N = 25005;

int n;
Point a[N], d[N];
Line s[N];
long double X;

struct Cmp {
	bool operator () (int i, int j) {
		long double v1 = s[i].get_y(X);
		long double v2 = s[j].get_y(X);
		if (sgn(v1 - v2) == 0) {
			return i < j;
		}
		return sgn(v1 - v2) < 0;
	}
};

bool check(long double t) {
	eps = t * 1e-12;
	std::vector<std::pair<long double, int>> op;
	for (int i = 1; i <= n; ++i) {
		s[i].a = a[i];
		s[i].b = a[i] + d[i] * t;
		if (s[i].a.x > s[i].b.x) {
			std::swap(s[i].a, s[i].b);
		}
		op.push_back({s[i].a.x, i});
		op.push_back({s[i].b.x, -i});
	}
	std::sort(op.begin(), op.end());
	X = 0;
	std::set<int, Cmp> S;
	for (auto p : op) {
		X = p.first;
		if (p.second < 0) {
			int id = -p.second;
			S.erase(id);
			auto nx = S.upper_bound(id), pr = nx;
			if (nx != S.end() && pr != S.begin()) {
				--pr;
				if (segment_intersection(s[*pr], s[*nx])) {
					return 1;
				}
			}
		} else {
			int id = p.second;
			auto nx = S.upper_bound(id), pr = nx;
			if (nx != S.end()) {
				if (segment_intersection(s[id], s[*nx])) {
					return 1;
				}
			}
			if (pr != S.begin()) {
				--pr;
				if (segment_intersection(s[id], s[*pr])) {
					return 1;
				}
			}
			S.insert(id);
		}
	}
	return 0;
}

int main() {
	scanf("%d", &n);
	for (int i = 1; i <= n; ++i) {
		a[i].read(), d[i].read();
		double s;
		scanf("%lf", &s);
		d[i] = d[i].unit() * (long double)s;
	}
	long double l = 0, r = 1e12, md;
	for (int i = 0; i < 64; ++i) {
		md = (l + r) / 2;
		if (check(md)) {
			r = md;
		} else {
			l = md;
		}
	}
	if (r < 1e12 - 1e3) {
		printf("%.15lf\n", (double)r);
	} else {
		puts("No show :(");
	}
}