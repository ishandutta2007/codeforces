#include <bits/stdc++.h>
using namespace std;
typedef bool boolean;

#define ll long long

const ll lim = 2e16 + 3;

typedef class Point {
	public:
		ll x, y;

		Point() {	}
		Point(ll x, ll y) : x(x), y(y) {	}

		void read() {
			scanf("%lld%lld", &x, &y);
		}
} Point;

ll _abs(ll x) {
	return (x < 0) ? (-x) : (x); 
}

ll dis(Point x, Point y) {
	return _abs(x.x - y.x) + _abs(x.y - y.y);
}

ll ax, ay, bx, by, t;
Point p0, ps;
vector<Point> P;

int main() {
	p0.read();
	scanf("%lld%lld%lld%lld", &ax, &ay, &bx, &by);
	ps.read();
	scanf("%lld", &t);
	while (p0.x <= lim && p0.y <= lim) {
		P.push_back(p0);
		p0.x = p0.x * ax + bx;
		p0.y = p0.y * ay + by;
	}
	int m = P.size(), ans = 0;
	for (int i = 0; i < m; i++) {
		for (int l = 0; l <= i; l++) {
			for (int r = i; r < m; r++) {
				if (dis(ps, P[i]) + dis(P[i], P[l]) + dis(P[l], P[r]) <= t) {
					ans = max(ans, r - l + 1);
				}
				if (dis(ps, P[i]) + dis(P[i], P[r]) + dis(P[r], P[l]) <= t) {
					ans = max(ans, r - l + 1);
				}
			}
		}
	}
	printf("%d\n", ans);
	return 0;
}