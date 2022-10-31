#include "bits/stdc++.h"
using namespace std;



struct P {
	typedef int T; typedef long long T2;	//T2{a*b | a:T, b:T}
	T x, y;
	P(T x_, T y_) : x(x_), y(y_) {}
	P() : x(0), y(0) {}
};
inline bool operator==(const P& a, const P& b) { return a.x == b.x && a.y == b.y; }
inline bool operator<(const P& a, const P& b) { return a.x < b.x || (a.x == b.x && a.y < b.y); }
inline P operator+(const P& a, const P& b) { return P(a.x + b.x, a.y + b.y); }
inline P operator-(const P& a, const P& b) { return P(a.x - b.x, a.y - b.y); }
inline P operator-=(P& a, const P& b) { a.x -= b.x, a.y -= b.y; return a; }
inline P::T2 cross(const P& a, const P& b) { return (P::T2)a.x*b.y - (P::T2)a.y*b.x; }
inline P::T2 dot(const P& a, const P& b) { return (P::T2)a.x*b.x + (P::T2)a.y*b.y; }
inline P::T2 norm(const P& a) { return (P::T2)a.x*a.x + (P::T2)a.y*a.y; }
ostream& operator<<(ostream& out, const P& x) { out << "(" << x.x << ", " << x.y << ")"; return out; }

struct L {
	P a, b;
	L(const P &a_, const P &b_) : a(a_), b(b_) {}
	const P& operator[](size_t i) const { return i ? b : a; }
};

inline int ccw(const P& a, const P& b, const P& c) {
	int ax = b.x - a.x, ay = b.y - a.y, bx = c.x - a.x, by = c.y - a.y;
	P::T2 t = (P::T2)ax*by - (P::T2)ay*bx;
	if (t > 0) return 1;
	if (t < 0) return -1;
	if ((P::T2)ax*bx + (P::T2)ay*by < 0) return +2;
	if ((P::T2)ax*ax + (P::T2)ay*ay < (P::T2)bx*bx + (P::T2)by*by) return -2;
	return 0;
}
bool contains(const vector<P>& o, const P& p) {
	bool in = false;
	for (int i = 0; i < o.size(); ++i) {
		P a = o[i] - p, b = o[(i + 1) % o.size()] - p;
		if (a.y > b.y) swap(a, b);
		if (a.y <= 0 && 0 < b.y)
			if (cross(a, b) < 0) in = !in;
		if (cross(a, b) == 0 && dot(a, b) <= 0) return true;	//point on edge
	}
	return in;
}
int intersectSS(const L &s, const L &t) {
	assert(!(s.a == s.b || t.a == t.b));
	int a = ccw(s.a, s.b, t.a), b = ccw(s.a, s.b, t.b), c = ccw(t.a, t.b, s.a), d = ccw(t.a, t.b, s.b);
	int x = a * b, y = c * d;
	if (x == -1 && y == -1) return 0;	//cross
	else if (
		((abs(b) == 1 || b == -2) && s.b == t.a) ||
		((abs(b) == 1 || b == 2) && s.a == t.a) ||
		((abs(a) == 1 || a == -2) && s.b == t.b) ||
		((abs(a) == 1 || a == 2) && s.a == t.b)
		) return 2;	// point overlap ()
	else if (
		(x == 0 && (abs(a) + abs(b) == 1)) ||
		(y == 0 && (abs(c) + abs(d) == 1))
		) return 3;	// point overlap ()
	else if (x <= 0 && y <= 0) return 0;	//segment overlap
	else return 1;
}

int main() {
	array<vector<P>, 2> polys;
	for (int k = 0; k < 2; ++ k) {
		for (int i = 0; i < 4; ++ i) {
			int x; int y;
			scanf("%d%d", &x, &y);
			polys[k].push_back(P(x, y));
		}
	}
	bool ans = false;
	for (int i = 0; i < 4; ++ i) for (int j = 0; j < 4; ++ j)
		ans |= intersectSS(L(polys[0][i], polys[0][(i + 1) % 4]), L(polys[1][j], polys[1][(j + 1) % 4])) != 1;
	for (int i = 0; i < 4; ++ i)
		ans |= contains(polys[0], polys[1][i]);
	for (int j = 0; j < 4; ++ j)
		ans |= contains(polys[1], polys[0][j]);
	puts(ans ? "Yes" : "No");
}