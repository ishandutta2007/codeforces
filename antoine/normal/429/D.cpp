#undef NDEBUG
#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

ll sq(ll x) {
	return x * x;
}

struct Point {
	ll x, y;
	bool operator<(const Point &other) const {
		return y < other.y;
	}
	ll distSq(const Point other) const {
		return sq(x - other.x) + sq(y - other.y);
	}
};

ll ans = 1LL << 60;

void g(vector<Point> pts, const ll pivot) {

	pts.erase(remove_if(pts.begin(), pts.end(), [&pivot](const Point &p) {
		return sq(p.x - pivot) >= ans;
	}), pts.end());

	for (int i = 0; i < (int) pts.size(); ++i)
		for (int j = i + 1;
				j < (int) pts.size() && sq(pts[j].y - pts[i].y) < ans; ++j)
			ans = min(ans, pts[i].distSq(pts[j]));

}

void f(vector<Point> &pts) {
	if (pts.size() <= 1)
		return;

	const ll pivot = pts[pts.size() / 2].x;

	auto mid = pts.begin() + pts.size() / 2;
	vector<Point> leftPts(pts.begin(), mid);
	vector<Point> rightPts(mid, pts.end());
	f(leftPts);
	f(rightPts);
	pts.resize(leftPts.size() + rightPts.size());
	merge(leftPts.begin(), leftPts.end(), rightPts.begin(), rightPts.end(),
			pts.begin());

	g(pts, pivot);
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);

	int n;
	cin >> n;
	vector<Point> pts(n);
	for (int i = 0; i < n; ++i) {
		pts[i].x = i;
		cin >> pts[i].y;
		if (i)
			pts[i].y += pts[i - 1].y;
	}

	f(pts);

	cout << ans;
	return 0;
}