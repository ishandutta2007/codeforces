#include <bits/stdc++.h>

#define all(x) begin(x), end(x)
#define int int64_t

using namespace std;

struct pt {
	int x, y;
};

bool cmp (pt a, pt b) {
	return (a.x < b.x) || (a.x == b.x && a.y < b.y);
}

bool cw (pt a, pt b, pt c) {
	return a.x*(b.y-c.y)+b.x*(c.y-a.y)+c.x*(a.y-b.y) < 0;
}

bool ccw (pt a, pt b, pt c) {
	return a.x*(b.y-c.y)+b.x*(c.y-a.y)+c.x*(a.y-b.y) > 0;
}

void convex_hull (vector<pt> & a) {
	if (a.size() == 1)  return;
	sort (a.begin(), a.end(), &cmp);
	pt p1 = a[0],  p2 = a.back();
	vector<pt> up, down;
	up.push_back (p1);
	down.push_back (p1);
	for (size_t i=1; i<a.size(); ++i) {
		if (i==a.size()-1 || cw (p1, a[i], p2)) {
			while (up.size()>=2 && !cw (up[up.size()-2], up[up.size()-1], a[i]))
				up.pop_back();
			up.push_back (a[i]);
		}
		if (i==a.size()-1 || ccw (p1, a[i], p2)) {
			while (down.size()>=2 && !ccw (down[down.size()-2], down[down.size()-1], a[i]))
				down.pop_back();
			down.push_back (a[i]);
		}
	}
	a = up;
}

signed main() {
	//freopen("input.txt", "r", stdin);
	ios::sync_with_stdio(0);
	cin.tie(0);
	int n;
	cin >> n;
	vector<pt> r(n);
	for(int i = 0; i < n; i++) {
		int x, y;
		cin >> x >> y;
		y -= x * x;
		r[i] = {x, y};
	}
	convex_hull(r);
	int ans = 0;
	for(size_t i = 1; i < r.size(); i++) {
		if(r[i].x != r[i - 1].x) {
			ans++;
		}
	}
	cout << ans << endl;
	return 0;
}