#include <bits/stdc++.h>
using namespace std;
typedef bool boolean;

#define ll long long

typedef class Point {
	public:
		int x, y;

		Point() {	}
		Point(int x, int y) : x(x), y(y) {	}
} Point;

typedef class Line {
	public:
		Point v;
		int a, b;
		double ang;

		Line(Point v, int a, int b) : v(v), a(a), b(b) {
			ang = atan2(v.y, v.x);
		}

		boolean operator < (Line b) const {
			return ang < b.ang;
		}
} Line;

Point operator - (Point a, Point b) {
	return Point(a.x - b.x, a.y - b.y);
}

const int N = 303;

int n;
Point P[N];
ll dp[N][5][N];
vector<Line> E;

int main() {
	scanf("%d", &n);
	for (int i = 1; i <= n; i++) {
		scanf("%d%d", &P[i].x, &P[i].y);
	}
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			if (i ^ j) {
				E.emplace_back(P[j] - P[i], i, j);
			}
		}
	}
	sort(E.begin(), E.end());
	for (auto e : E) {
		int a = e.a, b = e.b;
		dp[b][0][a] = 1;
		for (int t = 0; t < 4; t++) {
			for (int c = 1; c <= n; c++) {
				dp[b][t + 1][c] += dp[a][t][c];
			}
		}
	}
	ll ans = 0;
	for (int i = 1; i <= n; i++)
		ans += dp[i][4][i];
	printf("%lld\n", ans);
	return 0;
}