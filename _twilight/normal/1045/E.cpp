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

const int N = 1e3 + 4;

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
int *c;
vector<Point> V;
vector<Point> conv;

inline void init() {
	scanf("%d", &n);
	V.resize(n);
	c = new int[n];
	for (int i = 0, x, y; i < n; i++) {
		scanf("%d%d%d", &x, &y, c + i);
		V[i] = Point(x, y, i);
	}
}

boolean check_in(Point A, Point B, Point C, Point P) {
	boolean sgn1 = (dcmp(cross(B - A, P - A)) == -1);
	boolean sgn2 = (dcmp(cross(C - B, P - B)) == -1);
	boolean sgn3 = (dcmp(cross(A - C, P - C)) == -1);
	return sgn1 && sgn2 && sgn3;
}

vector<pii> ans;
void dividing(Point A, Point B, Point C, vector<Point>& Vert) { // clockwise
	if (!Vert.size()) {
		return;	
	}
	int ca = c[A.id], cb = c[B.id], cc = c[C.id];
	if (cb == cc) {
		swap(cb, ca), swap(B, A);
		swap(cc, cb), swap(C, B);
	}
	if (cc == ca) {
		swap(cb, cc), swap(B, C);
		swap(ca, cb), swap(A, B);
	}
	assert(ca == cb);
	assert(cc != ca);
	Point Q (0, 0, -1);
	for (auto& P : Vert) {
		if (c[P.id] == cc) {
			Q = P;
			break;
		}	
	}
	if (Q.id == -1) {
		for (auto& P : Vert) {
			ans.emplace_back(P.id, A.id);
		}
		return;
	}
	vector<Point> PAB, PBC, PCA;
	ans.emplace_back(Q.id, C.id);
	for (auto& P : Vert) {
		if (P.id == Q.id) {
			continue;
		}
		if (check_in(Q, A, B, P)) {
			PAB.push_back(P);
		} else if (check_in(Q, B, C, P)) {
			PBC.push_back(P);
		} else {
			PCA.push_back(P);
		}
	}
	dividing(Q, A, B, PAB);
	dividing(Q, B, C, PBC);
	dividing(Q, C, A, PCA);
}

inline void solve() {
	boolean have0 = false, have1 = false;
	for (int i = 0; i < n; i++) {
		have0 = have0 || !c[i];
		have1 = have1 || c[i]; 
	}
	
	if (!have0 || !have1) {
		printf("%d\n", n - 1);
		for (int i = 1; i < n; i++) {
			printf("0 %d\n", i);
		}
		return;
	}
	if (n == 2) {
		puts("0");
		return;
	}
	
	conv = build_convex(V);
//	for (auto& P : conv) {
//		cerr << P << '\n';
//	}

	assert(conv.size() >= 3);
	int dif = (c[conv[0].id] != c[conv[conv.size() - 1].id]);
	for (int i = 0; i < (signed) conv.size() - 1; i++) {
		dif += (c[conv[i].id] != c[conv[i + 1].id]);
	}
	if (dif > 2) {
		puts("Impossible");
		return;
	}

	vector<boolean> used(n, false);
	if (dif == 0) {
		for (int i = 0; i < (signed) conv.size() - 1; i++) {
			ans.emplace_back(conv[i].id, conv[i + 1].id);
		}
		for (auto& P : conv) {
			used[P.id] = true;
		}
		
		int col = c[conv[0].id], m = conv.size();
		Point P;
		for (int i = 0; i < n; i++) {
			if (col != c[i]) {
				P = V[i];
				break;
			}
		}
		used[P.id] = true;
		for (int i = 0; i < m; i++) {
			Point &A = conv[i], &B = conv[((i == m - 1) ? (0) : (i + 1))];
			vector<Point> vec;
			for (auto& Q : V) {
				if (!used[Q.id] && check_in(P, A, B, Q)) {
					vec.push_back(Q);
					used[Q.id] = true;
				}
			}
			dividing(P, A, B, vec);
		}
	} else {
		int m = conv.size();
		int idx_1 = -1, idx_2 = -1;
		for (int i = 0; i < m; i++) {
			Point &A = conv[i], &B = conv[((i == m - 1) ? (0) : (i + 1))];
			if (c[A.id] == c[B.id]) {
				ans.emplace_back(A.id, B.id);
			} else {
				(idx_1 == -1) ? (idx_1 = i) : (idx_2 = i);
			}
			used[A.id] = true;
		}
		assert(idx_1 != -1 && idx_2 != -1);
		for (int i = (idx_1 + 1) % m, j; i != idx_2; i = j) {
			Point &A = conv[idx_1], &B = conv[i], &C = conv[j = (i + 1) % m];
			vector<Point> vec;
			for (auto& P : V) {
				if (!used[P.id] && check_in(A, B, C, P)) {
					vec.push_back(P);
					used[P.id] = true;
				}
			}
			dividing(A, B, C, vec);
		}
		for (int i = (idx_2 + 1) % m, j; i != idx_1; i = j) {
			Point &A = conv[idx_2], &B = conv[i], &C = conv[j = (i + 1) % m];
			vector<Point> vec;
			for (auto& P : V) {
				if (!used[P.id] && check_in(A, B, C, P)) {
					vec.push_back(P);
					used[P.id] = true;
				}
			}
			dividing(A, B, C, vec);
		}
	}
	printf("%d\n", (signed) ans.size());
	for (auto& par : ans) {
		printf("%d %d\n", par.first, par.second);
	}
}

int main() {
	init();
	solve();
	return 0;
}