#include <bits/stdc++.h>
using namespace std;
 
template <class TH>
void _dbg(const char *sdbg, TH h) { cerr << sdbg << '=' << h << endl; }
 
template <class TH, class... TA>
void _dbg(const char *sdbg, TH h, TA... a)
{
	while (*sdbg != ',')
		cerr << *sdbg++;
	cerr << '=' << h << ',';
	_dbg(sdbg + 1, a...);
}
 
template <class L, class R>
ostream &operator<<(ostream &os, pair<L, R> p)
{
	return os << "(" << p.first << ", " << p.second << ")";
}
 
template <class Iterable, class = typename enable_if<!is_same<string, Iterable>::value>::type>
auto operator<<(ostream &os, Iterable v) -> decltype(os << *begin(v))
{
	os << "[";
	for (auto vv : v)
		os << vv << ", ";
	return os << "]";
}
 
#define debug(...) _dbg(#__VA_ARGS__, __VA_ARGS__)
 
typedef pair<int, int> pii;
typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;
 
const int inf = 0x3f3f3f3f;
const long long infll = 0x3f3f3f3f3f3f3f3fll;
 
#define sz(x) ((int)(x).size())
 
// Return 1 if x > 0, 0 if x == 0 and -1 if x < 0.
template <class T>
int sign(T x) { return (x > 0) - (x < 0); }
 
template <class T>
T abs(const T &x) { return (x < T(0)) ? -x : x; }
 
// Pretty good compilation command:
// g++ -g a.cpp --std=c++14 -Wall -Wextra -Wno-unused-result -Wconversion -Wfatal-errors -fsanitize=undefined,address -o a.out
 
 
// 2D geometry operations. This file should not have algorithms.
// Author: some of it by Arthur Pratti Dadalto.
// Source: some of it from https://github.com/kth-competitive-programming/kactl/blob/master/content/geometry/.
// Usage: avoid int unless necessary.
 
// When increasing EPS, keep in mind that sqrt(1e9^2 + 1) = 1e9 + 5e-10.
const long double EPS = 1e-2;
 
// Point struct implementation. Some methods are useful only when using this to represent vectors.
template <class T>
struct point
{
	typedef point<T> P;
	T x, y;
 
	explicit point(T x = 0, T y = 0) : x(x), y(y) {}
	bool operator<(P p) const { return tie(x, y) < tie(p.x, p.y); }
	bool operator==(P p) const { return tie(x, y) == tie(p.x, p.y); }
	P operator+(P p) const { return P(x + p.x, y + p.y); }
	P operator-(P p) const { return P(x - p.x, y - p.y); }
	P operator*(T d) const { return P(x * d, y * d); }
	P operator/(T d) const { return P(x / d, y / d); }
	T dot(P p) const { return x * p.x + y * p.y; }
	T cross(P p) const { return x * p.y - y * p.x; }
	T cross(P a, P b) const { return (a - *this).cross(b - *this); } // product sign: right hand rule from a to b.
	T dist2() const { return x * x + y * y; }						 // Distance squared to origin.
	long double dist() const { return sqrt((long double)dist2()); }			 // Vector norm (distance to origin).
	long double angle() const { return atan2(y, x); }					 // angle to x-axis in interval [-pi, pi]
	point<long double> unit() const { return *this / dist(); }			 // makes dist()=1 (unit vector).
	P perp() const { return P(-y, x); }								 // rotates +90 degrees around origin.
	point<long double> normal() const { return perp().unit(); }			 // perpendicular unit vector.
	point<long double> rotate(long double a) const							 // returns point rotated 'a' radians ccw around the origin.
	{
		return P(x * cos(a) - y * sin(a), x * sin(a) + y * cos(a));
	}
	long double angle(P p) const { return p.rotate(-angle()).angle(); } // Angle between the vectors in interval [-pi, pi]. Positive if p is ccw from this.
};
 
// Solves the linear system {a * x + b * y = e
//                          {c * x + d * y = f
// Returns {1, {x, y}} if solution is unique, {0, {0,0}} if no solution and {-1, {0,0}} if infinite solutions.
// If using integer function type, this will give wrong answer if answer is not integer.
// TODO: test me with integer and non-integer.
template <class T>
pair<int, point<T>> linear_solve2(T a, T b, T c, T d, T e, T f)
{
	point<T> retv;
	T det = a * d - b * c;
 
	if (det == 0) // Maybe do EPS compare if using floating point.
	{
		if (b * f == d * e && a * f == c * e)
			return {-1, point<T>()};
		return {0, point<T>()};
	}
 
	// In case solution needs to be integer, use something like the line below.
	// assert((e * d - f * b) % det == 0 && (a * f - c * e) % det == 0);
 
	return {1, point<T>((e * d - f * b) / det, (a * f - c * e) / det)};
}
 
// Represents line segments defined by two points.
template <class T>
struct segment
{
	typedef point<T> P;
	P pi, pf; // Initial and final points.
 
	explicit segment(P a = P(), P b = P()) : pi(a), pf(b) {}
 
	// Distance from this segment to a given point. TODO: test me.
	long double dist(P p)
	{
		if (pi == pf)
			return (p - pi).dist();
		auto d = (pf - pi).dist2();
		auto t = min(d, max(.0, (p - pi).dot(pf - pi)));
		return ((p - pi) * d - (pf - pi) * t).dist() / d;
	}
 
	// Checks if given point belongs to segment. Use dist(p) <= EPS instead when using point<long double>.
	bool on_segment(P p)
	{
		return p.cross(pi, pf) == 0 && (pi - p).dot(pf - p) <= 0;
	}
 
	// If a unique intersection point between the line segments exists then it is returned.
	// If no intersection point exists an empty vector is returned.
	// If infinitely many exist a vector with 2 elements is returned, containing the endpoints of the common line segment.
	// The wrong position will be returned if P is point<ll> and the intersection point does not have integer coordinates.
	// However, no problem in using it to check if intersects or not in this case (size of vector will be correct).
	// Products of **three** coordinates are used in intermediate steps so watch out for overflow if using int or long long.
	vector<P> intersect(segment rhs)
	{
		auto oa = rhs.pi.cross(rhs.pf, pi), ob = rhs.pi.cross(rhs.pf, pf),
			 oc = pi.cross(pf, rhs.pi), od = pi.cross(pf, rhs.pf);
 
		// Checks if intersection is single non-endpoint point.
		if (sign(oa) * sign(ob) < 0 && sign(oc) * sign(od) < 0)
			return {(pi * ob - pf * oa) / (ob - oa)};
 
		set<P> s;
		if (rhs.on_segment(pi))
			s.insert(pi);
		if (rhs.on_segment(pf))
			s.insert(pf);
		if (on_segment(rhs.pi))
			s.insert(rhs.pi);
		if (on_segment(rhs.pf))
			s.insert(rhs.pf);
		return vector<P>(s.begin(), s.end());
	}
};
 
// Represents a line by its equation in the form a * x + b * y = c.
// Can be created from two points or directly from constants.
template <class T>
struct line
{
	typedef point<T> P;
	T a, b, c; // line a * x + b * y = c
 
	explicit line(P p1, P p2) // TODO: test me.
	{
		assert(!(p1 == p2));
		a = p2.y - p1.y;
		b = p1.x - p2.x;
		c = a * p1.x + b * p1.y;
 
		// In case of int, it is useful to scale down by gcd (e.g to use in a set).
		// Might be useful to normalize here.
	}
 
	explicit line(T _a, T _b, T _c) : a(_a), b(_b), c(_c) {}
 
	// Distance from this line to a given point. TODO: test me.
	long double dist(P p)
	{
		return abs(a * p.x + b * p.y - c) / sqrt((long double)(a * a + b * b));
	}
 
	// Intersects this line with another given line. See linear_solve2 for usage. TODO: test me.
	pair<int, P> intersect(line rhs)
	{
		return linear_solve2(a, b, rhs.a, rhs.b, c, rhs.c);
	}
 
	// Normalize line to c >= 0, a*a + b*b == 1. Only use with long double.
	line normalize()
	{
		long double d = /*P(a, b).dist() * */ (c < 0 ? -1 : 1);
		return line(a / d, b / d, c / d);
	}
};
 
// Represents a circle by its center and radius. Mostly only works with long double.
template <class T>
struct circle
{
	typedef point<T> P;
	P center;
	T r;
	T r2;
 
	// Intersects circle with a given line. This does not work with integer types.
	// If there is no intersection, returns 0 and retv is whatever.
	// If intersection is a single point, returns 1 and retv is a pair of equal points.
	// If intersection is two points, return 2 and retv is the two intersection points.
	// Assume points are given in no particular order. If you really need it, should be leftmost first when looking from center of the circle.
	int intersect(line<T> l, pair<P, P> &retv)
	{
		l.c -= l.a * center.x + l.b * center.y; // Recenter so that we can consider circle center in origin.
		l = l.normalize();
		P v(l.a, l.b);
		P p0(l.a*l.c / P(l.a,l.b).dist2(), l.b*l.c / P(l.a,l.b).dist2()); // p0 is the point in the line closest to origin.
 
		if (p0.dist2() > r2 * (1 + EPS)) // No intersection.
			return 0;
		else if (p0.dist2() > r2) // dist in [r - EPS, r + EPS] -> single point intersection at p0.
		{
			retv = {p0, p0};
			return 1;
		}
 
		long double d = sqrt(r2 - p0.dist2()); // d is distance from p0 to the intersection points.
		retv = {center + p0 + v.normal() * d, center + p0 - v.normal() * d};
		return 2;
	}
 
	// Intersects circle with another circle. This does not work with integer types.
	// This assumes the circles do not have the same center. Check this case if needed, can have 0 or infinite intersection points.
	// If there is no intersection, returns 0 and retv is whatever.
	// If intersection is a single point, returns 1 and retv is a pair of equal points.
	// If intersection is two points, return 2 and retv is the two intersection points.
	// Assume points are given in no particular order. If you really need it, should be leftmost first when looking from center of the rhs circle.
	int intersect(circle rhs, pair<P, P> &retv)
	{
		rhs.center = rhs.center - center;
		int num = rhs.intersect(line<T>(2 * rhs.center.x, 2 * rhs.center.y, rhs.center.x * rhs.center.x + rhs.center.y * rhs.center.y + r2 - rhs.r2), retv);
		retv.first = retv.first + center;
		retv.second = retv.second + center;
		return num;
	}
 
	// Returns a pair of the two points on the circle whose tangent lines intersect p.
	// If p lies within the circle NaN-points are returned. P is intended to be Point<long double>.
	// The first point is the one to the right as seen from the point p towards the circle.
	pair<P, P> tangents(P p)
	{
		p = p - center;
		long double k1 = r * r / p.dist2();
		long double k2 = sqrt(k1 - k1 * k1);
		return {center + p * k1 + p.perp() * k2, center + p * k1 - p.perp() * k2};
	}
 
	// TODO: find pair of tangent lines passing two circles.
};
 
// The circumcircle of a triangle is the circle intersecting all three vertices.
// Returns the unique circle going through points A, B and C (given in no particular order).
// This assumes that the triangle has non-zero area.
// TODO: test specifically.
circle<long double> circumcircle(const point<long double> &A, const point<long double> &B, const point<long double> &C)
{
	circle<long double> retv;
	point<long double> a = C - B, b = C - A, c = B - A;
	retv.r = a.dist() * b.dist() * c.dist() / abs(c.cross(b)) / 2;
	retv.center = A + (b * c.dist2() - c * b.dist2()).perp() / b.cross(c) / 2;
	return retv;
}
 
#define pointll point<ll>
#define pointld point<ld>
#define MAXN 112345
 
int n;
pointll p[MAXN];
ll d[MAXN];
pointld center;
set<pointll> ans;
ll tmp_d[MAXN];
 
void check(pointll b)
{
	for (int i = 0; i < n; i++)
		tmp_d[i] = ((b.x - p[i].x)*(b.x - p[i].x) + (b.y - p[i].y)*(b.y - p[i].y));
	sort(tmp_d, tmp_d + n);
	for (int i = 0; i < n; i++)
		if (d[i] != tmp_d[i])
			return;
 
	ans.insert(b);
}
 
template <class T>
ostream &operator<<(ostream &os, point<T> p)
{
	return os << "(" << p.x << ", " << p.y << ")";
}
 
int main()
{
	cin.sync_with_stdio(0);
	cin.tie(0);
    cin >> n;
    for (int i = 0; i < n; i++)
        cin >> p[i].x >> p[i].y;
 
    for (int i = 0; i < n; i++)
		center.x += p[i].x;
    for (int i = 0; i < n; i++)
		center.y += p[i].y;
	
	// center.x /= n;
	// center.y /= n;
 
	cerr << fixed << setprecision(10);
 
    int q;
    cin >> q;
    while (q--)
    {
		// pointll seed(rand() % 100000000, rand() % 100000000);
		// for (int i = 0; i < n; i++)
		// {
		// 	d[i] = (seed - p[i]).dist2();
		// 	cout << d[i] << " ";
		// }
		// cout << endl;
		// debug(seed.x, seed.y);
		for (int i = 0; i < n; i++)
			cin >> d[i];
		sort(d, d + n);
 
		circle<ld> c;
		c.center = pointld(0,0);
		c.r2 = 0;
		for (int i = 0; i < n; i++)
			c.r2 += (n*1.0L*n*d[i] - (n*p[i].x - center.x)*(n*p[i].x - center.x) - (n*p[i].y - center.y)*(n*p[i].y - center.y));
		c.r2 /= n;
		c.r = sqrt(c.r2);
 
		ans.clear();
		for (int i = 0; i < n; i++)
		{
			circle<ld> c2;
			c2.center = pointld(n*p[0].x, n*p[0].y) - center;
			c2.r2 = n*1.0L*n*d[i];
			c2.r = sqrt(c2.r2);
			
			pair<pointld,pointld> pts;
			if (c2.intersect(c, pts) > 0)
			{
 
				pointld tmp = (pts.first + center) / n;
 
				// debug(tmp);
				int lim = 16;
				for (int j = -lim; j <= lim; j++)
					for (int k = -lim; k <= lim; k++)
					{
						pointll u(tmp.x + j, tmp.y + k);
						if ((u - p[0]).dist2() == d[i])
							check(u);
					}
 
				tmp = (pts.second + center) / n;
 
				// debug(tmp);
				for (int j = -lim; j <= lim; j++)
					for (int k = -lim; k <= lim; k++)
					{
						pointll u(tmp.x + j, tmp.y + k);
						if ((u - p[0]).dist2() == d[i])
							check(u);
					}
 
			}
		}
 
		// assert(ans.find(seed) != ans.end());
		cout << ans.size();
		for (pointll tmp : ans)
			cout << " " << tmp.x << " " << tmp.y;
		cout << endl;
    }
}