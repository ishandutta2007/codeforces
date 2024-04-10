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

const int inf = 0x3f3f3f3f;
const long long infll = 0x3f3f3f3f3f3f3f3fll;

// Source: https://github.com/kth-competitive-programming/kactl/blob/master/content/geometry/Point.h
// Usage: avoid int unless necessary.

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
	double dist() const { return sqrt((double)dist2()); }
	double angle() const { return atan2(y, x); } // angle to x-axis in interval [-pi, pi]
	P unit() const { return *this / dist(); }	// makes dist()=1 (unit vector).
	P perp() const { return P(-y, x); }			 // rotates +90 degrees around origin.
	P normal() const { return perp().unit(); }   // perpendicular unit vector.
	P rotate(double a) const					 // returns point rotated 'a' radians ccw around the origin.
	{
		return P(x * cos(a) - y * sin(a), x * sin(a) + y * cos(a));
	}
};

// Solves the linear system {a * x + b * y = e
//                          {c * x + d * y = f
// Returns the point with x, y.
// Only works if solution is unique.
// If using integer function type, this will give wrong answer if answer is not integer.
template <class T>
point<T> linear_solve2(T a, T b, T c, T d, T e, T f)
{
	point<T> retv;
	T det = a * d - b * c;

	// In case solution needs to be integer, use something like the line below.
	// assert((e * d - f * b) % det == 0 && (a * f - c * e) % det == 0);

	return point<T>((e * d - f * b) / det, (a * f - c * e) / det);
}

template <class T>
struct segment
{
	typedef point<T> P;
	P pi, pf; // Initial and final points.

	explicit segment(P a, P b) : pi(a), pf(b) {}

	double dist(P p)
	{
		if (pi == pf)
			return (p - pi).dist();
		auto d = (pf - pi).dist2();
		auto t = min(d, max(.0, (p - pi).dot(pf - pi)));
		return ((p - pi) * d - (pf - pi) * t).dist() / d;
	}

	bool on_segment(P p)
	{
		return p.cross(pi, pf) == 0 && (pi - p).dot(pf - p) <= 0;
	}

	// If a unique intersection point between the line segments going from s1 to e1 and from s2 to e2 exists then it is returned.
	// If no intersection point exists an empty vector is returned. If infinitely many exist a vector with 2 elements is returned, containing the endpoints of the common line segment.
	// The wrong position will be returned if P is Point<ll> and the intersection point does not have integer coordinates.
	// However, no problem in using it to check if intersects or not in this case.
	// Products of three coordinates are used in intermediate steps so watch out for overflow if using int or long long.
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

#define point point<ll>
#define segment segment<ll>
#define MAXN 212

const ll mod = 1e9 + 7;

point p[MAXN];
int n;

bool been[MAXN][MAXN];
ll tab[MAXN][MAXN];

ll polyside = 0;

ll pd(int l, int r)
{
	if (been[l][r])
		return tab[l][r];

	been[l][r] = true;

	bool ok = true;
	for (int k = 0; k < n; k++)
	{
		if (l != k && l != (k + 1) % n && r != k && r != (k + 1) % n)
		{
			segment s1 = segment(p[l], p[r]);
			segment s2 = segment(p[k], p[(k + 1) % n]);

			if (s2.intersect(s1).size())
			{
				ok = false;
				// debug(l, r, k);
			}
		}
		if (l != k && r != k)
		{
			segment s1 = segment(p[l], p[r]);
			segment s2 = segment(p[k], p[k]);

			if (s2.intersect(s1).size())
			{
				ok = false;
				// debug(l, r, k);
			}
		}
	}

	// if (ok && !(polyside * p[l].cross(p[(l + 1) % n], p[r]) >= 0 && polyside * p[(l-1+n) % n].cross(p[l], p[r]) >= 0))
	// {
	// 	ok = false;
	// 	debug(l, r);
	// }

	if (!ok)
	{
		return tab[l][r] = 0;
	}

	if (r - l <= 1)
		return tab[l][r] = 1;

	ll retv = 0;
	for (int i = l + 1; i < r; i++)
		if ((polyside * p[r].cross(p[l], p[(l + 1) % n]) <= 0 || polyside * p[l].cross(p[(l + 1) % n], p[i]) >= 0) &&
			(polyside * p[(r-1+n) % n].cross(p[r], p[l]) <= 0 || polyside * p[(r-1+n) % n].cross(p[r], p[i]) >= 0))
		{
			// if (!(polyside * p[r].cross(p[l], p[i]) >= 0))
			// 	debug(l, r, i);

			if (polyside * p[r].cross(p[l], p[i]) >= 0)
			retv = (retv + pd(l, i) * pd(i, r)) % mod;

		}

	return tab[l][r] = retv;
}

int main(void)
{
	cin >> n;
	for (int i = 0; i < n; i++)
		cin >> p[i].x >> p[i].y;

	point p0(0,0);
	ll sum = 0;
	for (int i = 0; i < n; i++)
		sum += p0.cross(p[i], p[(i + 1) % n]);

	polyside = (sum > 0) ? 1 : -1;

	cout << pd(0, n-1) << endl;
}