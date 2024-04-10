#undef NDEBUG
#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

struct Point {
	int x, y;
};

int f(Point p1, Point p2) {
	return abs(p1.x - p2.x) + abs(p1.y - p2.y);
}
int main() {
	ios::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);

	int n;
	cin >> n;
	vector<Point> a(n);
	for (int i = 0; i < n; ++i)
		cin >> a[i].x >> a[i].y;

	Point u, d, l, r;
	u = d = l = r = a[0];
	for (auto &&p : a) {
		if (p.x < l.x)
			l = p;
		if (p.x > r.x)
			r = p;
		if (p.y < d.y)
			d = p;
		if (p.y > u.y)
			u = p;
	}

	vector<Point> v = { u, d, l, r };

	int ans = 0;
	for (auto &&x : a)
		for (auto &&y : v)
			for (auto &&z : v)
				ans = max(ans, f(x, y) + f(y, z) + f(z, x));

	cout << ans << ' ';

	ans = max(ans, f(l, u) + f(u, r) + f(r, d) + f(d, l));

	for (int i = 4; i <= n; ++i)
		cout << ans << ' ';
	return 0;
}