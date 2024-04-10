// https://codeforces.com/problemset/problem/681/E
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
typedef long double ld;

const int inf = 0x3f3f3f3f;
const long long infll = 0x3f3f3f3f3f3f3f3fll;

// Source: https://github.com/kth-competitive-programming/kactl/blob/master/content/geometry/Point.h
// Usage: avoid int unless necessary.

const double EPS = 1e-12;

// Return 1 if x > 0, 0 if x == 0 and -1 if x < 0
template <class T>
int sign(T x) { return (x > 0) - (x < 0); }

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
	double dist() const { return sqrt((double)dist2()); }			 // Vector norm (distance to origin).
	double angle() const { return atan2(y, x); }					 // angle to x-axis in interval [-pi, pi]
	point<double> unit() const { return *this / dist(); }			 // makes dist()=1 (unit vector).
	P perp() const { return P(-y, x); }								 // rotates +90 degrees around origin.
	point<double> normal() const { return perp().unit(); }			 // perpendicular unit vector.
	point<double> rotate(double a) const							 // returns point rotated 'a' radians ccw around the origin.
	{
		return P(x * cos(a) - y * sin(a), x * sin(a) + y * cos(a));
	}
	double angle(P p) const { return p.rotate(-angle()).angle(); } // Angle between the vectors in interval [-pi, pi]. Positive if p is ccw from this.
};

// Solves the linear system {a * x + b * y = e
//                          {c * x + d * y = f
// Returns {1, {x, y}} if solution is unique, {0, {0,0}} if no solution and {-1, {0,0}} if infinite solutions.
// If using integer function type, this will give wrong answer if answer is not integer.
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

template <class T>
struct segment
{
	typedef point<T> P;
	P pi, pf; // Initial and final points.

	// explicit segment() : pi(), pf() {}
	explicit segment(P a = P(), P b = P()) : pi(a), pf(b) {}

	// Distance from this segment to a given point. TODO: test me.
	double dist(P p)
	{
		if (pi == pf)
			return (p - pi).dist();
		auto d = (pf - pi).dist2();
		auto t = min(d, max(.0, (p - pi).dot(pf - pi)));
		return ((p - pi) * d - (pf - pi) * t).dist() / d;
	}

	// Checks if given point belongs to segment. Use dist(p)<=EPS instead when using point<double>.
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

template <class T>
struct line
{
	typedef point<T> P;
	T a, b, c; // line a * x + b * y = c

	explicit line(P p1, P p2)
	{
		assert(!(p1 == p2));
		a = p2.y - p1.y;
		b = p1.x - p2.x;
		c = a * p1.x + b * p1.y;

		// In case of int, it is useful to scale down by gcd (e.g to use in a set).
	}

	explicit line(T _a, T _b, T _c) : a(_a), b(_b), c(_c) {}

	// Distance from this line to a given point.
	double dist(P p)
	{
		return abs(a * p.x + b * p.y - c) / sqrt((double)(a * a + b * b));
	}

	// See linear_solve2 for usage.
	pair<int, P> intersect(line rhs)
	{
		return linear_solve2(a, b, rhs.a, rhs.b, c, rhs.c);
	}

	// normalize line to c >= 0, a*a + b*b == 1. Only use with double.
	line normalize()
	{
		double d = P(a, b).dist() * (c < 0 ? -1 : 1);
		return line(a / d, b / d, c / d);
	}
};

template <class T>
struct circle
{
	typedef point<T> P;
	P center;
	T r;

	int intersect(line<T> l, pair<P, P> &retv)
	{
		l = l.normalize();
		l.c -= l.a * center.x + l.b * center.y; // Recenter so that we can consider circle center in origin.
		P v(l.a, l.b);
		P p0 = v * l.c; // p0 is the point in the line closest to origin.

		if (p0.dist() > r + EPS)
			return 0;
		else if (p0.dist() > r - EPS)
		{
			retv = {p0, p0};
			return 1;
		}

		double d = sqrt(r * r - l.c * l.c); // d is distance from p0 to the intersection points.
		retv = {center + p0 + v.normal() * d, center + p0 - v.normal() * d};
		return 2;
	}

	// This assumes the circles do not have the same center. Check this case if needed, can have 0 or infinite intersection points.
	int intersect(circle rhs, pair<P, P> &retv)
	{
		rhs.center = rhs.center - center;
		int num = rhs.intersect(line<T>(2 * rhs.center.x, 2 * rhs.center.y, rhs.center.x * rhs.center.x + rhs.center.y * rhs.center.y + r * r - rhs.r * rhs.r), retv);
		retv.first = retv.first + center;
		retv.second = retv.second + center;
		return num;
	}

	// Returns a pair of the two points on the circle whose tangent lines intersect p.
	// If p lies within the circle NaN-points are returned. P is intended to be Point<double>.
	// The first point is the one to the right as seen from the p towards c.
	pair<P, P> tangents(P p)
	{
		p = p - center;
		double k1 = r*r / p.dist2();
		double k2 = sqrt(k1 - k1*k1);
		return {center + p * k1 + p.perp() * k2, center + p * k1 - p.perp() * k2};
	}
};

template <class T>
ostream &operator<<(ostream &os, point<T> p)
{
	return os << "(x=" << p.x << ", y=" << p.y << ")";
}

#define point point<double>
#define segment segment<double>
#define circle circle<double>
#define MAXN 112345

#define M_PI 3.14159265358979323846

circle c[MAXN];

int main(void)
{
	point p0;
	double v, t;
	int n;
	cin >> p0.x >> p0.y >> v >> t >> n;
	for (int i = 0; i < n; i++)
	{
		scanf("%lf %lf %lf", &c[i].center.x, &c[i].center.y, &c[i].r);
		c[i].center = c[i].center - p0;
		if (c[i].center.dist() < c[i].r + EPS)
		{
			printf("1\n");
			return 0;
		}
	}

	cerr << fixed << setprecision(12);

	p0 = p0 - p0;
	circle safe = {p0, v * t};
	vector<pair<double, double>> arcs;
	for (int i = 0; i < n; i++)
	{
		if (c[i].center.dist() < c[i].r + safe.r - EPS)
		{
			pair<point,point> sf;
			sf = c[i].tangents(p0);
			// debug(sf);
			if (sf.first.dist() > safe.r + EPS)
			{
				if (c[i].intersect(safe, sf) <= 0)
				{
					debug(safe.center, safe.r);
					debug(sf);
					debug(c[i].center, c[i].r);
					assert(false);
				}
			}

			pair<double, double> tmp = {sf.first.angle(), sf.second.angle()};

			if (tmp.first > tmp.second)
				swap(tmp.first, tmp.second);

			if (tmp.second - tmp.first < M_PI)
				arcs.push_back(tmp);
			else
			{
				arcs.push_back({-M_PI, tmp.first});
				arcs.push_back({tmp.second, M_PI});
			}
			// debug(i, arcs, tmp);
		}
	}

	// debug(arcs);
	double ans = 0;
	sort(arcs.begin(), arcs.end());
	for (int i = 0; i < arcs.size(); i++)
	{
		double l = arcs[i].first;
		double r = arcs[i].second;
		while (i + 1 < arcs.size() && arcs[i + 1].first <= r)
			r = max(r, arcs[++i].second);
		
		ans += r - l;
	}


	printf("%.15lf\n", ans / (2*M_PI));
}