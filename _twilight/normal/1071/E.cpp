#include <bits/stdc++.h>
using namespace std;
typedef bool boolean;

#define double long double
#define local

const double eps = 1e-6;
const double dinf = 1e100;

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

typedef class Segment Segment;

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
		boolean on_right(Point P) {
			return dcmp(cross(v, P - A)) <= 0;
		}
		Segment intersect(vector<Point>&);
} Line;

class Segment {
	public:
		Point L, R;
		boolean flag;

		Segment() {	}
		Segment(boolean flag) : flag(flag) {	}
		Segment(Point x) : L(x), R(x), flag(true) { 	}
		Segment(Point x, Point y) : L(x), R(y), flag(true) {
		}

		boolean empty() {
			return !flag;
		}
		boolean on(Point P) {
			if (P == L || P == R) return true;
			return !dcmp(cross(R - L, P - L)) && dcmp(dot(L - P, R - P)) < 0;
		}
};

// the point on the polygon is given by clockwise
Segment Line :: intersect(vector<Point>& Conv) {
	int N = Conv.size();
	if (N == 1) {
		return (on(Conv[0])) ? (Segment(Conv[0])) : (Segment(false));
	}
	Point P, dir;
	vector<Point> vec;
	for (int i = 0; i < N; i++) {
		dir = Conv[(i + 1) % N] - Conv[i];
		if (!dcmp(cross(dir, v))) {
			if (on(Conv[0])) {
				return Segment(Conv[i], Conv[(i + 1) % N]);
			}
			continue;
		}
		P = intersect(Line(Conv[i], dir));
		if (Segment(Conv[i], Conv[(i + 1) % N]).on(P)) {
			vec.push_back(P);
		}
	}
	sort(vec.begin(), vec.end(), [&] (const Point& a, const Point& b) {
			if (!dcmp(a.x - b.x)) 
				return a.y < b.y;
			return a.x < b.x;
		});
	vec.erase(unique(vec.begin(), vec.end()), vec.end());
	if (vec.size() == 1) {
		return Segment(vec[0]);
	} else if (vec.size() == 2) {
		return Segment(vec[0], vec[1]);
	}
	return Segment(false);
}

ostream& operator << (ostream& os, Point b) {
	os << '(' << b.x << " ," << b.y << ')';
	return os;
}

typedef class RainDrop {
	public:
		int t;
		Point P;

		void read() {
			int x, y;
			scanf("%d%d%d", &t, &x, &y);
			P = Point(x, y);
		}

		boolean operator < (RainDrop b) const {
			return t < b.t;
		}
} RainDrop;

const int N = 1e5 + 5;

vector<Point> build_convex_hull(vector<Point> V) {
	static Point S[N];
	sort(V.begin(), V.end(), [&] (const Point& a, const Point& b) {
			if (!dcmp(a.x - b.x)) 
				return a.y < b.y;
			return a.x < b.x;
		});
	V.erase(unique(V.begin(), V.end()), V.end());
	int tp = 0;
	for (auto& P : V) {
		while (tp >= 2 && dcmp(cross(S[tp] - S[tp - 1], P - S[tp])) >= 0) {
			tp--;
		}
		S[++tp] = P;
	}
	int m = tp;
	for (int i = (signed) V.size() - 2; i > 0; i--) {
		Point P = V[i];
		while (tp > m && dcmp(cross(S[tp] - S[tp - 1], P - S[tp])) >= 0) {
			tp--;
		}
		S[++tp] = P;
	}
	while (tp > m && dcmp(cross(S[tp] - S[tp - 1], S[1] - S[tp])) >= 0) {
		tp--;
	} 
	return vector<Point>(S + 1, S + tp + 1);
}

int n, W, H;
int ex, ey;
Line *dl;
RainDrop *rd;

inline void init() {
	scanf("%d%d%d", &n, &W, &H);
	scanf("%d%d", &ex, &ey);
	dl = new Line[(n + 1)];
	rd = new RainDrop[(n + 1)];
	for (int i = 1; i <= n; i++) {
		rd[i].read();
		//		cerr << dl[i].A << " " << dl[i].v << '\n';
	}
	sort(rd + 1, rd + n + 1);
	for (int i = 1; i <= n; i++) {
		Point& P = rd[i].P;
		Point P1 (0, H * P.x / P.y);
		Point P2 (1, (H * P.x - (H - P.y)) / P.y);
		dl[i] = Line(P1, P2 - P1);
	}
}

boolean check(double v) {
	Segment seg (Point(ex, ey));
	vector<Point> area;
	int last_t = 0, t;
	for (int i = 1; i <= n && !seg.empty(); i++) {
		t = rd[i].t - last_t;

		Point L = seg.L;
		Point R = seg.R;
		double D = v * t;
		area.clear();
		area.push_back(Point(L.x - D, L.y - D));
		area.push_back(Point(L.x - D, L.y + D));
		area.push_back(Point(L.x + D, L.y - D));
		area.push_back(Point(L.x + D, L.y + D));
		area.push_back(Point(R.x - D, R.y - D));
		area.push_back(Point(R.x - D, R.y + D));
		area.push_back(Point(R.x + D, R.y - D));
		area.push_back(Point(R.x + D, R.y + D));
		area = build_convex_hull(area);

		seg = dl[i].intersect(area);
		last_t = rd[i].t;
		if (seg.empty()) {
			return false;
		}

		area.clear();
		area.push_back(Point(0, 0));
		area.push_back(Point(0, W));
		area.push_back(Point(W, W));
		area.push_back(Point(W, 0));
		Line l = Line(seg.L, seg.R - seg.L);
		Segment seg1 = l.intersect(area);
		if (seg1.empty()) {
			return false;
		}

		if (!dcmp(seg.L.x - seg.R.x)) {
			if (seg.L.y > seg.R.y) {
				swap(seg.L, seg.R);
			}
			if (seg1.L.y > seg1.R.y) {
				swap(seg.L, seg.R);
			}
			if (dcmp(seg.R.y - seg1.L.y) < 0 || dcmp(seg.L.y - seg1.R.y) > 0) {
				return false;
			} else {
				if (seg.L.y + eps < seg1.L.y) {
					seg.L = seg1.L;
				} 
				if (seg.R.y - eps> seg1.R.y) {
					seg.R = seg1.R;
				}
			}
		} else {
			if (seg.L.x > seg.R.x) {
				swap(seg.L, seg.R);
			}
			if (seg1.L.x > seg1.R.x) {
				swap(seg.L, seg.R);
			}
			if (dcmp(seg.R.x - seg1.L.x) < 0 || dcmp(seg.L.x - seg1.R.x) > 0) {
				return false;
			}
			if (seg.L.x + eps < seg1.L.x) {
				seg.L = seg1.L;
			} 
			if (seg.R.x - eps > seg1.R.x) {
				seg.R = seg1.R;
			}
		}
	}
	return !seg.empty();
}

inline void solve() {
	double l = 0, r = W + 3, mid;
	for (int _ = 0; l + eps < r && _ < 128; _++) {
		mid = (l + r) / 2;
		if (check(mid)) {
			r = mid;
		} else {
			l = mid;
		}
	}
	if (!check(r)) {
		puts("-1");
	} else {
//		printf("%.9LF\n", r);
		cout << fixed << setprecision(6) << r << endl;
	}
}

int main() {
	init();
	solve();
	return 0;
}