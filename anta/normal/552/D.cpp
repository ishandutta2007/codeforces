#include <string>
#include <vector>
#include <algorithm>
#include <numeric>
#include <set>
#include <map>
#include <queue>
#include <iostream>
#include <sstream>
#include <cstdio>
#include <cmath>
#include <ctime>
#include <cstring>
#include <cctype>
#include <cassert>
#include <limits>
#include <functional>
#define rep(i,n) for(int (i)=0;(i)<(int)(n);++(i))
#define rer(i,l,u) for(int (i)=(int)(l);(i)<=(int)(u);++(i))
#define reu(i,l,u) for(int (i)=(int)(l);(i)<(int)(u);++(i))
#if defined(_MSC_VER) || __cplusplus > 199711L
#define aut(r,v) auto r = (v)
#else
#define aut(r,v) __typeof(v) r = (v)
#endif
#define each(it,o) for(aut(it, (o).begin()); it != (o).end(); ++ it)
#define all(o) (o).begin(), (o).end()
#define pb(x) push_back(x)
#define mp(x,y) make_pair((x),(y))
#define mset(m,v) memset(m,v,sizeof(m))
#define INF 0x3f3f3f3f
#define INFL 0x3f3f3f3f3f3f3f3fLL
using namespace std;
typedef vector<int> vi; typedef pair<int,int> pii; typedef vector<pair<int,int> > vpii; typedef long long ll;
template<typename T, typename U> inline void amin(T &x, U y) { if(y < x) x = y; }
template<typename T, typename U> inline void amax(T &x, U y) { if(x < y) x = y; }


struct P {
	typedef int T; typedef ll T2;	//T2{a*b | a:T, b:T}
	T x, y;
	P(T x_, T y_): x(x_), y(y_) {}
	P(): x(0), y(0) {}
};
inline bool operator==(const P& a, const P& b) { return a.x == b.x && a.y == b.y; }
inline bool operator<(const P& a, const P& b) { return a.x < b.x || (a.x == b.x && a.y < b.y); }
inline P operator+(const P& a, const P& b) { return P(a.x+b.x, a.y+b.y); }
inline P operator-(const P& a, const P& b) { return P(a.x-b.x, a.y-b.y); }
inline P operator-=(P& a, const P& b) { a.x -= b.x, a.y -= b.y ; return a; }
inline P::T2 cross(const P& a, const P& b) { return (P::T2)a.x*b.y - (P::T2)a.y*b.x; }
inline P::T2 dot(const P& a, const P& b) { return (P::T2)a.x*b.x + (P::T2)a.y*b.y; }
inline P::T2 norm(const P& a) { return (P::T2)a.x*a.x + (P::T2)a.y*a.y; }
ostream& operator<<(ostream& out, const P& x) { out << "(" << x.x << ", " << x.y << ")"; return out; }

int compareAngle(const P &a, const P &b) {
	int za = a.y > 0 || (a.y == 0 && a.x > 0) ? 0 : 1;
	int zb = b.y > 0 || (b.y == 0 && b.x > 0) ? 0 : 1;
	if(za != zb) return za - zb;
	P::T2 t1 = (P::T2)a.x * b.y;
	P::T2 t2 = (P::T2)a.y * b.x;
	return t1 > t2 ? 1 : t1 < t2 ? -1 : 0;
}

struct Angle {
	P point;
	int infty;
	int eps;
	Angle(): point(), infty(0), eps(0) { }
	Angle(P::T x, P::T y, int eps_ = 0): point(P(x, y)), infty(0), eps(eps_) { }
	Angle(P point_, int eps_ = 0): point(point_), infty(0), eps(eps_) { }
	Angle(P origin, P target, int eps_ = 0): point(target.x - origin.x, target.y - origin.y), infty(0), eps(eps_) { }
	explicit Angle(int infty_): point(), infty(infty_), eps(0) { }
	bool zero() const { return point.x == 0 && point.y == 0; }
	int compare_to(const Angle &that) const {
		if(infty != 0)
			return that.infty == 0 ? infty : (infty > 0) - (that.infty > 0);
		else if(that.infty != 0)
			return -that.infty;
		int t = compareAngle(point, that.point);
		if(t != 0)
			return t;
		return eps == that.eps ? 0 : eps > that.eps ? 1 : -1;
	}
	bool operator==(const Angle &that) const { return compare_to(that) == 0; }
	bool operator!=(const Angle &that) const { return compare_to(that) != 0; }
	bool operator< (const Angle &that) const { return compare_to(that) <  0; }
	bool operator<=(const Angle &that) const { return compare_to(that) <= 0; }
	bool operator> (const Angle &that) const { return compare_to(that) >  0; }
	bool operator>=(const Angle &that) const { return compare_to(that) >= 0; }
	friend ostream &operator<<(ostream &o, const Angle &a) {
		if(a.infty != 0)
			return o << (a.infty > 0 ? "+" : "-") << "oo";
		o << "(" << a.point.x << ", " << a.point.y << ")";
		if(a.eps != 0) o << a.eps;
		return o;
	}
	Angle operator-() const {
		if(infty != 0)
			return Angle(-infty);
		return Angle(-point.x, -point.y, -eps);
	}
};

int main() {
	int n;
	while(cin >> n) {
		vector<P> points(n);
		rep(i, n)
			cin >> points[i].x >> points[i].y;
		map<Angle,int> v, w;
		ll ans = (ll)n * (n-1) * (n-2) / 6;
		rep(i, n) {
			v.clear(), w.clear();
			rep(j, n) if(i != j) {
				Angle a(points[i], points[j]);
				if(a < -a)
					++ v[a];
				else
					++ w[-a];
			}
			ll cnt = 0;
			each(i, v)
				cnt += w[i->first] * i->second;
//			cerr << i << ": " << cnt << endl;
			ans -= cnt;
		}
		cout << ans << endl;
	}
	return 0;
}