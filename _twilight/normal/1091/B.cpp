#include <bits/stdc++.h>
using namespace std;
typedef bool boolean;

typedef pair<int, int> Point;

Point operator + (Point x, Point y) {
	return Point(x.first + y.first, x.second + y.second);
}

Point operator - (Point x, Point y) {
	return Point(x.first - y.first, x.second - y.second);
}

const int N = 1e3 + 5;

int n;
Point a[N], b[N];
set<Point> s;

inline void init() {
	scanf("%d", &n);
	for (int i = 1; i <= n; i++)
		scanf("%d%d", &a[i].first, &a[i].second);
	for (int i = 1; i <= n; i++) {
		scanf("%d%d", &b[i].first, &b[i].second);
		s.insert(b[i]);
	}
}

boolean check(Point target) {
	for (int i = 1; i <= n; i++)
		if (!s.count(target - a[i]))
			return false;
	return true;
}

inline void solve() {
	for (int i = 1; i <= n; i++) {
		Point q = a[1] + b[i];
		if (check(q)) {
			printf("%d %d\n", q.first, q.second);
			return ;
		}
	}
}

int main() {
	init();
	solve();
	return 0;
}