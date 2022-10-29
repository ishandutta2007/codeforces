#include <bits/stdc++.h>
using namespace std;
typedef bool boolean;

const double eps = 1e-7;

int dcmp(double x) {
	return (fabs(x) < eps) ? (0) : ((x < 0) ? (-1) : (1));
} 

typedef class Point {
	public:
		double x, y;

		Point(double x = 0.0, double y = 0.0) : x(x), y(y) {	}

		double length();
		Point normal();
		void normalize();

		void read() {
			scanf("%lf%lf", &x, &y);
		}
} Point, Vector;

Vector operator + (Vector a, Vector b) {
	return Vector(a.x + b.x, a.y + b.y);
}
Vector operator - (Vector a, Vector b) {
	return Vector(a.x - b.x, a.y - b.y);
}
Vector operator * (Vector a, double k) {
	return Vector(a.x * k, a.y * k);
}

boolean operator == (Point a, Point b) {
	return !dcmp(a.x - b.x) && !dcmp(a.y - b.y);
}

double dot(Vector a, Vector b) {
	return a.x * b.x + a.y * b.y;
}
double cross(Vector a, Vector b) {
	return a.x * b.y - a.y * b.x;
}

double Point :: length() {
	return sqrt(dot(*this, *this));
}
Point Point :: normal() {
	double len = length();
#ifdef local
	assert(dcmp(len));
#endif
	return Point(x / len, y / len);
}
void Point :: normalize() {
	*this = normal();
}

typedef class Line {
	public:
		Point A;
		Vector v;

		Line() {	}
		Line(Point A, Vector v) : A(A), v(v) {	}

		static Point get_intersection(Line a, Line b) {
#ifdef local
			assert(dcmp(cross(a.v, b.v)));
#endif
			Vector w = Vector(b.v.y, -b.v.x);
			double t = dot(b.A - a.A, w) / dot(a.v, w);
			return a.A + a.v * t;
		}

		Point intersect(Line b) {
			return get_intersection(*this, b);
		}
		boolean on(Point P) {
			return !dcmp(cross(P - A, v));
		}
		boolean on_left(Point P) {
			return dcmp(cross(v, P - A)) > 0;
		}
		boolean on_right(Point P) {
			return dcmp(cross(v, P - A)) < 0;
		}
} Line;

ostream& operator << (ostream& os, Point b) {
	os << '(' << b.x << " ," << b.y << ')';
	return os;
}

double a, b, c;
Point A, B;

int main() {
	scanf("%lf%lf%lf", &a, &b, &c);
	A.read(), B.read();
	
	Line l;
	double ans = fabs(B.x - A.x) + fabs(B.y - A.y);
	if (dcmp(b) && dcmp(a)) {
		Point C = Point(0, -c / b), E, F;
		Point D = Point(1, -(c + a) / b);
		l = Line(C, D - C);
		
		E = Line(A, Vector(1, 0)).intersect(l);
		F = Line(B, Vector(1, 0)).intersect(l);
		ans = min(ans, (A - E).length() + (E - F).length() + (B - F).length());
	
		E = Line(A, Vector(1, 0)).intersect(l);
		F = Line(B, Vector(0, 1)).intersect(l);
		ans = min(ans, (A - E).length() + (E - F).length() + (B - F).length());

		E = Line(A, Vector(0, 1)).intersect(l);
		F = Line(B, Vector(1, 0)).intersect(l);
		ans = min(ans, (A - E).length() + (E - F).length() + (B - F).length());

		E = Line(A, Vector(0, 1)).intersect(l);
		F = Line(B, Vector(0, 1)).intersect(l);
		ans = min(ans, (A - E).length() + (E - F).length() + (B - F).length());
	}

	printf("%.9lf", ans);
	return 0;
}