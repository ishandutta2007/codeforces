#include <bits/stdc++.h>
using namespace std;
typedef bool boolean;

//#define double long double
//#define local

#define pii pair<int, int>

const double eps = 1e-7;

int dcmp(double x) {
	return (fabs(x) < eps) ? (0) : ((x < 0) ? (-1) : (1));
} 

typedef class Point {
	public:
		double x, y;
		int id;

		Point(double x = 0.0, double y = 0.0, int id = 0) : x(x), y(y), id(id) {	}

		double length();
		Point normal();
		void normalize();
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

const int N = 2e5 + 4;

vector<Point> build_convex(vector<Point> V) {
	static Point S[N];
	sort(V.begin(), V.end(), [&] (const Point& a, const Point& b) {
			return (dcmp(a.x - b.x)) ? (a.x < b.x) : (a.y < b.y);
		});
	int tp = 0, n = V.size();
	for (int i = 0; i < n; i++) {
		while (tp >= 2 && dcmp(cross(S[tp] - S[tp - 1], V[i] - S[tp])) >= 0)
			tp--;
		S[++tp] = V[i];
	}
	int m = tp;
	for (int i = n - 2; i > 0; i--) {
		while (tp > m && dcmp(cross(S[tp] - S[tp - 1], V[i] - S[tp])) >= 0)
			tp--;
		S[++tp] = V[i];
	}
	while (tp >= 3 && dcmp(cross(S[tp] - S[tp - 1], S[1] - S[tp])) >= 0)
		tp--;
	return vector<Point>(S + 1, S + tp + 1);
}

int n;
vector<boolean> ban;
vector<Point> S, _S;

inline void init() {
	scanf("%d", &n);
	S.resize(n + 1);
	S[0] = Point(0, 0, 0);
	for (int i = 1, x, y; i <= n; i++) {
		scanf("%d%d", &x, &y);
		S[i] = Point(x, y, i);
	}
}

int _round(double x) {
	return (int) (x + 0.5);
}

void check(vector<Point> &_S) {
	for (auto& P : _S) {
		if ((_round(P.x) & 1) || (_round(P.y) & 1)) {
			puts("Ani");
			exit(0);
		}
	}
}

inline void solve() {
	_S = build_convex(S);
	ban.resize(n + 1, false);
	check(_S);
	for (int i = 0; i < (signed) _S.size(); i += 2) {
		if (_S[i].id) {
			ban[_S[i].id] = true;
		}
	}
	vector<Point> V;
	for (int i = 0; i <= n; i++) {
		if (!ban[i]) {
			V.push_back(S[i]);
		} else {
			ban[i] = false;
		}
	}
	V = build_convex(V);
	check(V);
	
	V.clear();
	for (int i = 1; i < (signed) _S.size(); i += 2) {
		if (_S[i].id) {
			ban[_S[i].id] = true;
		}
	}
	for (int i = 0; i <= n; i++) {
		if (!ban[i]) {
			V.push_back(S[i]);
		}
	}
	V = build_convex(V);
	check(V);
	puts("Borna");
}

int main() {
	init();
	solve();
	return 0;
}