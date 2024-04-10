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
#include <complex>
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

typedef complex<double> Point;

Point three_point_circle(const Point& a, const Point& b, const Point& c) {
	Point x = 1. / conj(b - a), y = 1. / conj(c - a);
	return (y - x) / (conj(x) * y - x * conj(y)) + a;
}

int main() {
	Point points[3];
	rep(k, 3) {
		double x, y;
		cin >> x >> y;
		points[k] = Point(x, y);
	}
	Point center = three_point_circle(points[0], points[1], points[2]);
	Point t = points[0] - center;
	double r = abs(t);
	double angles[3];
	rep(k, 3)
		angles[k] = arg(points[k] - center);
	rer(n, 3, 100) {
		bool ok = true;
		double d = acos(-1.) * 2 / n;
		rep(k, 3)
			ok &= abs(sin((angles[(k + 1) % 3] - angles[k]) / 2 * n)) < 1e-3;
		if(ok) {
			double s = hypot(r - r * cos(d), r * sin(d));
			double h = sqrt(r * r - s * s / 4);
			double area = s * h / 2 * n;
			printf("%.10f\n", area);
			return 0;
		}
	}
	abort();
	return 0;
}