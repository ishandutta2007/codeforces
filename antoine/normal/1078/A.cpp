#undef NDEBUG
#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

double sq(double x) {
	return x * x;
}

double doubleAbs(double x) {
	return x < 0 ? -x : x;
}

struct Point {
	double x, y;
	double eDist(Point p) const {
		return sqrt(sq(x - p.x) + sq(y - p.y));
	}
	double mDist(Point p) const {
		return doubleAbs(p.x - x) + doubleAbs(p.y - y);
	}
};

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);

	cout << fixed << setprecision(10);

	ll a, b, c;
	cin >> a >> b >> c;

	ll x1, y1, x2, y2;
	cin >> x1 >> y1 >> x2 >> y2;
	double ans = llabs(x1 - x2) + llabs(y1 - y2);

	if (a && b) {
		vector<Point> v(4);
		v[0] = {x1, (-a * x1 - c) / (double) (b)};
		v[1] = {x2, (-a * x2- c) / (double) (b)};
		v[2] = {(-b * y1 - c) / (double) (a), y1};
		v[3] = {(-b * y2 - c) / (double) (a), y2};

		for (auto &&p1 : v)
			for (auto &&p2 : v)
				ans = min(ans,
						Point { x1, y1 }.mDist(p1) + p1.eDist(p2)
								+ p2.mDist(Point { x2, y2 }));
	}

	cout << ans;
	return 0;
}