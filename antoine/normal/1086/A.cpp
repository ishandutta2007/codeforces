#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

struct Point {
	int x, y;
	bool operator<(const Point &other) const {
		return x != other.x ? x < other.x : y < other.y;

	}
	bool operator==(const Point &other) const {
		return x == other.x && y == other.y;
	}
};

set<Point> res;

void f(Point p1, Point p2) {
	res.insert(p2);
	for (;;) {
		res.insert(p1);
		if (p1 == p2)
			return;
		if (p1.x < p2.x) {
			p1.x++;
		} else if (p1.y < p2.y) {
			p1.y++;
		} else if (p1.x > p2.x) {
			--p1.x;
		} else if (p1.y > p2.y)
			--p1.y;
		else
			assert(false);
	}
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);

	vector<Point> pts(3);
	for (auto &&p : pts)
		cin >> p.x >> p.y;

	sort(pts.begin(), pts.end());

	const int y1 = min(pts[0].y, pts[2].y);
	const int y2 = max(pts[0].y, pts[2].y);

	while (pts[1].y < y1) {
		res.insert(pts[1]);
		++pts[1].y;
	}
	while (pts[1].y > y2) {
		res.insert(pts[1]);
		--pts[1].y;
	}

	f(pts[0], pts[1]);
	f(pts[1], pts[2]);

	cout << res.size() << endl;
	for (auto &&p : res)
		cout << p.x << ' ' << p.y << '\n';
	return 0;
}