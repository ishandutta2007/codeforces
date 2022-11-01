#define _CRT_SECURE_NO_WARNINGS

#pragma GCC optimize("O3")

#include <iostream>
#include <vector>
#include <algorithm>
#include <numeric>
#include <cassert>
#include <cmath>
#include <string>
#include <cstring>
#include <set>

#define sz(a) (int)((a).size())
#define all(a) (a).begin(), (a).end()
#define mp make_pair
#define pb push_back

using namespace std;
using ll = long long;
using pii = pair<int, int>;
using vi = vector<int>;
using ld = long double;

struct Point {
	ll x, y;
	Point() : x(0), y(0) {}
	Point(ll x, ll y) : x(x), y(y) {}
	Point operator - (const Point& o) const { return Point(x - o.x, y - o.y); }
	ll dot(const Point& o) const { return x * o.y - y * o.x; }
	bool cw(const Point& o) const { return dot(o) < 0; }
	bool ccw(const Point& o) const { return dot(o) > 0; }
	bool operator < (const Point& o) const { return x < o.x; }
};

struct Line {
	ll A, B, C;
	Line(Point u, Point v) : A(u.y - v.y), B(v.x - u.x), C(u.x * v.y - u.y * v.x) {}
	bool onLine(Point p) const { return A * p.x + B * p.y + C == 0; }
	ld eval(ll x) const { return (-C - A * x) / (ld)B; }
};

set<Point> upper, lower;

bool upper_inside(Point p) {
	if (upper.empty()) return false;
	if (upper.count(p)) {
		return p.y <= upper.find(p)->y;
	}
	auto it = upper.upper_bound(p);
	if (it == upper.end() || it == upper.begin()) return false;
	Line l(*prev(it), *it);
	return l.onLine(p) || l.eval(p.x) > p.y;
}

bool lower_inside(Point p) {
	if (lower.empty()) return false;
	if (lower.count(p)) {
		return p.y >= lower.find(p)->y;
	}
	auto it = lower.upper_bound(p);
	if (it == lower.end() || it == lower.begin()) return false;
	Line l(*prev(it), *it);
	return l.onLine(p) || l.eval(p.x) < p.y;
}

bool inside(Point p) {
	return upper_inside(p) && lower_inside(p);
}

void upper_insert(Point p) {
	if (upper.count(p)) {
		upper.erase(p);
	}
	auto it = upper.insert(p).first;
	while (true) {
		if (it == upper.begin()) break;
		auto pit = prev(it);
		if (pit == upper.begin()) break;
		auto ppit = prev(pit);
		if ((*pit - *it).ccw(*ppit - *pit)) break;
		upper.erase(pit);
	}
	while (true) {
		auto nit = next(it);
		if (nit == upper.end()) break;
		auto nnit = next(nit);
		if (nnit == upper.end()) break;
		if ((*nit - *it).cw(*nnit - *nit)) break;
		upper.erase(nit);
	}
}

void lower_insert(Point p) {
	if (lower.count(p)) {
		lower.erase(p);
	}
	auto it = lower.insert(p).first;
	while (true) {
		if (it == lower.begin()) break;
		auto pit = prev(it);
		if (pit == lower.begin()) break;
		auto ppit = prev(pit);
		if ((*pit - *it).cw(*ppit - *pit)) break;
		lower.erase(pit);
	}
	while (true) {
		auto nit = next(it);
		if (nit == lower.end()) break;
		auto nnit = next(nit);
		if (nnit == lower.end()) break;
		if ((*nit - *it).ccw(*nnit - *nit)) break;
		lower.erase(nit);
	}
}

int32_t main() {
	ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	int q;
	cin >> q;
	while (q--) {
		int type;
		Point p;
		cin >> type >> p.x >> p.y;
		if (type == 1) {
			if (!upper_inside(p)) {
				upper_insert(p);
			}
			if (!lower_inside(p)) {
				lower_insert(p);
			}
		}
		else {
			cout << (inside(p) ? "YES\n" : "NO\n");
		}
	}
}