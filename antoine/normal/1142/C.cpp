#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

struct Point {
	ll x, y;
	bool operator<(const Point &other) const {
		return x != other.x ? x < other.x : y < other.y;
	}
	Point minus(const Point other) const {
		return {x - other.x, y - other.y};
	}
	ll cross(const Point other) const { // vector cross product
		return x * other.y - other.x * y;
	}
	bool operator==(const Point &other) const {
		return x == other.x && y == other.y;
	}
};

vector<Point> cHull(vector<Point> points) {
	sort(points.begin(), points.end());
	points.erase(unique(points.begin(), points.end()), points.end());
	const int n = points.size();
	vector<Point> ans(2 * n);
	int k = 0, start = 0;
	for (int i = 0; i < n; ++i) {
		Point p = points[i];
		while (k - start >= 2 && p.minus(ans[k - 1]).cross(p.minus(ans[k - 2])) >= 0)
			k--;
		ans[k++] = p;
	}
	start = --k;
	for (int i = n - 1; i >= 0; --i) {
		Point p = points[i];
		while (k - start >= 2 && p.minus(ans[k - 1]).cross(p.minus(ans[k - 2])) >= 0)
			k--;
		ans[k++] = p;
	}
	ans.resize(--k);
	return ans;
}

vector<Point> subVec(const vector<Point> &pts, vector<Point>::const_iterator lo, vector<Point>::const_iterator hi) {

	if (pts.empty())
		return {};
	assert(!pts.empty());
	vector<Point> res;
	for (auto it = lo;; ++it) {
		if (it == pts.end())
			it = pts.cbegin();
		res.push_back(*it);
		if (it - pts.begin() == hi - pts.begin())
			break;
	}
	return res;
}

auto invCmp = [](const Point &lhs, const Point &rhs) {
	if(lhs.x != rhs.x) return lhs.x < rhs.x;
	return lhs.y > rhs.y;
};

vector<Point> getUpperHull(vector<Point> pts) {
	reverse(pts.begin(), pts.end());
	auto lo = min_element(pts.begin(), pts.end(), invCmp);
	auto hi = max_element(pts.begin(), pts.end());
	return subVec(pts, lo, hi);
}

void checkHull(vector<Point> &pts) {
	assert(pts.size() >= 1);
	for (int i = 0; i + 1 < (int) pts.size(); ++i)
		assert(pts[i].x < pts[i + 1].x);
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);

	int n;
	cin >> n;

	vector<Point> pts(n);
	for (Point &p : pts) {
		ll x, y;
		cin >> x >> y;
		p = {x, y-x*x};
	}

	pts = cHull(pts);
	if (pts.size() <= 1)
		cout << 0;
	else {
		pts = getUpperHull(pts);
		cout << pts.size() - 1;
	}
	return 0;
}