#include <bits/stdc++.h>
using namespace std;
const double EPS = 1e-8;
inline int dcmp(double x) {
	return (x < -EPS) ? -1 : (x > EPS);
}
struct Point {
	double x, y;
	inline Point(double _x = 0, double _y = 0): x(_x), y(_y) {}
	inline Point operator + (const Point &oth) const { return Point(x + oth.x, y + oth.y); }
	inline Point operator - (const Point &oth) const { return Point(x - oth.x, y - oth.y); }
	inline Point operator * (const double &oth) const { return Point(x * oth, y * oth); }
	inline bool operator < (const Point &oth) const {
		if (dcmp(x - oth.x)) return x < oth.x;
		else return y < oth.y;
	}
	inline bool operator == (const Point &oth) const {
		return !dcmp(x - oth.x) && !dcmp(y - oth.y);
	}
	inline double norm() const { return sqrt(x * x + y * y); }
};
inline double dot(const Point &a, const Point &b) {
	return a.x * b.x + a.y * b.y;
}
inline double cross(const Point &a, const Point &b) {
	return a.x * b.y - a.y * b.x;
}
struct Line {
	Point p, vec;
};
Point its(const Line &L1, const Line &L2) {
	Point u = L1.p - L2.p;
	double k = cross(L2.vec, u) / cross(L1.vec, L2.vec);
	return L1.p + L1.vec * k;
}
inline bool On(Point a, Point b, Point p) {
	return dcmp(dot(a - p, b - p)) <= 0;
}
int n;
Point a[1005];
inline double solve(Point p, Point q) {
	Line L = (Line){p, q - p};
	vector<pair<Point, int> > vec;
	double ans = 0;
	for (int i = 1; i <= n; i++) {
		Line cur = (Line){a[i], a[i + 1] - a[i]};
		if (!dcmp(cross(L.vec, cur.vec))) {
			if (!dcmp(cross(L.vec, L.p - cur.p))) {
				if (dcmp(cross(L.vec, a[(i + 1) % n + 1] - a[i + 1])) * dcmp(cross(L.vec, a[i - 1] - a[i])) < 0) {
					ans += (a[i + 1] - a[i]).norm() / 2;
					vec.emplace_back((a[i + 1] + a[i]) * 0.5, 0);
				} else {
					vec.emplace_back(a[i], i);
					vec.emplace_back(a[i + 1], i);
				}
			}
			continue;
		}
		Point b = its(L, cur);
		if (On(a[i], a[i + 1], b) && !(b == a[i + 1])) {
			if (b == a[i]) {
				if (dcmp(cross(L.vec, a[i + 1] - a[i])) * dcmp(cross(L.vec, a[i - 1] - a[i])) >= 0) {
					continue;
				}
			}
			vec.emplace_back(b, 0);
		}
	}
	sort(vec.begin(), vec.end());
	assert((int)vec.size() % 2 == 0);
	for (int i = 0; i < (int)vec.size() - 1; i += 2) {
		ans += (vec[i].first - vec[i + 1].first).norm();
		if (i < (int)vec.size() - 2 && vec[i + 1].second && vec[i + 1].second == vec[i + 2].second)
			ans += (vec[i + 1].first - vec[i + 2].first).norm();
	}
	return ans;
}
int main() {
	int m;
	scanf("%d%d", &n, &m);
	for (int i = 1; i <= n; i++) scanf("%lf%lf", &a[i].x, &a[i].y), a[i] = a[i] * 100;
	while (true) {
		a[n + 1] = a[1];
		a[0] = a[n];
		int fnd = 0;
		for (int i = 1; i <= n; i++) {
			if (!dcmp(cross(a[i] - a[i - 1], a[i + 1] - a[i]))) {
				fnd = i;
				break;
			}
		}
		if (!fnd) break;
		for (int i = fnd + 1; i <= n; i++) a[i - 1] = a[i];
		n--;
	}
	for (int i = 1; i <= m; i++) {
		Point a, b;
		scanf("%lf%lf%lf%lf", &a.x, &a.y, &b.x, &b.y);
		a = a * 100, b = b * 100;
		printf("%.10lf\n", solve(a, b) / 100);
	}
	return 0;
}