#include <bits/stdc++.h>
using namespace std;
typedef bool boolean;

const double eps = 1e-8;

int dcmp(double x) {
	return (fabs(x) <= eps) ? (0) : ((x < 0) ? (-1) : (1)); 
}

typedef class Point {
	public:
		double x, y;

		Point(double x = 0, double y = 0) : x(x), y(y) {	}

		void read() {
			scanf("%lf%lf", &x, &y);
		}
} Point;

Point operator - (Point a, Point b) {
	return Point(a.x - b.x, a.y - b.y);
}

double cross(Point a, Point b) {
	return a.x * b.y - a.y * b.x;
}

double dot(Point a, Point b) {
	return a.x * b.x + a.y * b.y;
}

#define ll long long

int n, m;
Point *rP, *P, *S;

int main() {
	scanf("%d", &n);
	rP = new Point[(n + 1)];
	P = new Point[(n + 1)];
	S = new Point[(n + 1)];
	for (int i = 1; i <= n; i++) {
		rP[i].read();
	}
	sort(rP + 1, rP + n + 1, [&] (const Point& a, const Point& b) {
		return (a.x != b.x) ? (a.x < b.x) : (a.y > b.y);		
	});
	P[m = 1] = rP[1];
	for (int i = 2; i <= n; i++) {
		if (P[m].x != rP[i].x) {
			P[++m] = rP[i];
		}
	}
	
	int tp = 0;
	for (int i = 1; i <= m; i++) {
		P[i].y -= P[i].x * P[i].x;
		while (tp >= 2 && dcmp(cross(S[tp] - S[tp - 1], P[i] - S[tp])) >= 0)
			tp--;
		S[++tp] = P[i];
	}
	printf("%d\n", tp - 1);
	return 0;
}