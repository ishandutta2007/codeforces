#include <iostream>
#include <algorithm>
#include <cstring>
#include <string>
#include <vector>
#include <set>
#include <map>
#include <queue>
#include <cmath>
#include <stack>
#include <iomanip>
#include <functional>
#include <array>
#include <stack>

using namespace std;
typedef long long ll;

struct Point {
	int x, y; bool operator<(const Point &p) const {
		return x != p.x ? x < p.x : y < p.y;
	}
};

int gcd(int a, int b) {
	return b ? gcd(b, a%b) : a;
}

pair<int, int> fract(int a, int b) {
	if (!b)
		return{ 1, 0 };
	int g = gcd(a, b);
	a /= g;
	b /= g;
	if (a < 0) {
		a = -a;
		b = -b;
	}
	return{ a, b };
}

bool g(vector<Point> &pts) {
	map<pair<int, int>, vector<Point>> mp;
	for (int i = 1; i < pts.size(); ++i) {
		mp[fract(pts[i].x - pts[0].x, pts[i].y - pts[0].y)].push_back(pts[i]);
	}
	return mp.size() <= 1;
}

void f(vector<Point> &pts) {
	map<pair<int, int>, vector<Point>> mp;
	for(int i = 1; i < pts.size(); ++i) {
		mp[fract(pts[i].x - pts[0].x, pts[i].y - pts[0].y)].push_back(pts[i]);
	}
	for(auto &&x : mp)
		if (x.second.size() >= 2) {
			set<Point> s(x.second.begin(), x.second.end());
			pts.erase(pts.begin());
			pts.erase(remove_if(pts.begin(), pts.end(), [&](Point p) {
				return s.count(p);
			}), pts.end());
			cout << (g(pts) ? "YES" : "NO");
			exit(0);
		}
}

bool f() {
	int n;
	cin >> n;
	if (n < 5)
		return true;

	vector<Point> pts(n);
	for (int i = 0; i < n; ++i) {
		cin >> pts[i].x >> pts[i].y;
	}
	for (int i = 1; i < 4; ++i) {
		swap(pts[0], pts[i]);
		f(pts);
	}
	return false;
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	cout << (f() ? "YES" : "NO");

	return 0;
}