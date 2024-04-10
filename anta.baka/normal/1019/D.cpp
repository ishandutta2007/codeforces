#define _CRT_SECURE_NO_WARNINGS

#pragma GCC optimize("O3")

#include <iostream>
#include <vector>
#include <algorithm>
#include <numeric>
#include <cassert>
#include <cmath>

#define sz(a) (int)((a).size())
#define all(a) (a).begin(), (a).end()
#define mp make_pair
#define pb push_back

using namespace std;
using ll = long long;
using pii = pair<int, int>;
using vi = vector<int>;

struct Point {
	ll x, y;
	Point() : x(0), y(0) {}
	Point(ll x, ll y) : x(x), y(y) {}
	Point operator - (const Point& o) const { return Point(x - o.x, y - o.y); }
	ll dot(const Point& o) const { return x * o.y - y * o.x; }
	bool operator < (const Point& o) const { return dot(o) > 0; }
};

ll area(const Point& a, const Point& b, const Point& c) {
	return abs((b - a).dot(c - a));
}

void print(Point a, Point b, Point c) {
	cout << "Yes\n";
	cout << a.x << ' ' << a.y << '\n';
	cout << b.x << ' ' << b.y << '\n';
	cout << c.x << ' ' << c.y << '\n';
	exit(0);
}

int32_t main() {
	ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	int n;
	ll s;
	cin >> n >> s;
	s *= 2;
	vector<Point> a(n);
	for (auto& p : a) {
		cin >> p.x >> p.y;
	}
	struct Prokek {
		Point vec;
		int i, j;
		bool operator < (const Prokek& o) const {
			return vec < o.vec;
		}
	};
	vector<Prokek> dirs;
	dirs.reserve(n * (n - 1) / 2);
	for (int i = 0; i < n; i++) {
		for (int j = i + 1; j < n; j++) {
			dirs.pb({ a[i].y < a[j].y || a[i].y == a[j].y && a[i].x > a[j].x ? a[j] - a[i] : a[i] - a[j], i, j });
		}
	}
	sort(all(dirs));
	vi ord(n);
	iota(all(ord), 0);
	sort(all(ord), [&](int i, int j) { return a[i].y < a[j].y || a[i].y == a[j].y && a[i].x > a[j].x; });
	vi pos(n);
	for (int i = 0; i < n; i++) {
		pos[ord[i]] = i;
	}
	for (const auto& dir : dirs) {
		int l = pos[dir.i];
		int r = pos[dir.j];
		if (l > r) {
			swap(l, r);
		}
		assert(abs(l - r) == 1);
		Point u = a[ord[l]], v = a[ord[r]];
		int lf = 0, rg = l;
		while (lf < rg) {
			int md = (lf + rg) >> 1;
			if (area(a[ord[md]], u, v) <= s) {
				rg = md;
			}
			else {
				lf = md + 1;
			}
		}
		if (area(a[ord[lf]], u, v) == s) {
			print(a[ord[lf]], u, v);
		}
		lf = r, rg = n - 1;
		while (lf < rg) {
			int md = (lf + rg + 1) >> 1;
			if (area(a[ord[md]], u, v) <= s) {
				lf = md;
			}
			else {
				rg = md - 1;
			}
		}
		if (area(a[ord[lf]], u, v) == s) {
			print(a[ord[lf]], u, v);
		}
		swap(ord[pos[dir.i]], ord[pos[dir.j]]);
		swap(pos[dir.i], pos[dir.j]);
	}
	cout << "No";
}