#define _CRT_SECURE_NO_WARNINGS
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
#include <list>
#include <cassert>
#include <complex>
#define rep(i,n) for(int (i)=0;(i)<(int)(n);++(i))
#define rer(i,l,u) for(int (i)=(int)(l);(i)<=(int)(u);++(i))
#define reu(i,l,u) for(int (i)=(int)(l);(i)<(int)(u);++(i))
#if defined(_MSC_VER) || __cplusplus > 199711L
#define aut(r,v) auto r = (v)
#else
#define aut(r,v) typeof(v) r = (v)
#endif
#define each(it,o) for(aut(it, (o).begin()); it != (o).end(); ++ it)
#define all(o) (o).begin(), (o).end()
#define pb(x) push_back(x)
#define mp(x,y) make_pair((x),(y))
#define mset(m,v) memset(m,v,sizeof(m))
#define INF 0x3f3f3f3f
#define INFL 0x3f3f3f3f3f3f3f3fLL
#define EPS 1e-9
using namespace std;
typedef vector<int> vi; typedef pair<int,int> pii; typedef vector<pair<int,int> > vpii;
typedef long long ll; typedef vector<long long> vl; typedef pair<long long,long long> pll; typedef vector<pair<long long,long long> > vpll;
typedef vector<string> vs; typedef long double ld;

typedef complex<double> P;
typedef vector<P> G;
double cross(const P& a, const P& b) {
	return imag(conj(a)*b);
}
double dot(const P& a, const P& b) {
	return real(conj(a)*b);
}

int ccw(P a, P b, P c) {
	b -= a; c -= a;
	if(cross(b, c) > 0)   return +1;       // counter clockwise
	if(cross(b, c) < 0)   return -1;       // clockwise
	if(dot(b, c) < 0)     return +2;       // c--a--b on line
	if(norm(b) < norm(c)) return -2;       // a--b--c on line
	return 0;
}

P crosspoint(P a, P b, P c, P d) {
	double A = cross(b - a, d - c), B = cross(b - a, b - c);
	if(abs(A) < EPS && abs(B) < EPS) return c;
	return c + B / A * (d - c);
}

G convex_cut(const G &poly, const P &a, const P &b) {
	G r;
	rep(i, poly.size()) {
		P p = poly[i], q = poly[(i+1) % poly.size()];
		int c = ccw(a, b, p), d = ccw(a, b, q);
		if(c != -1) r.push_back(p);
		if(c * d < 0) r.push_back(crosspoint(p, q, a, b));
	}
	return r;
}

double area(const G& poly) {
	double A = 0;
	rep(i, poly.size())
		A += cross(poly[i], poly[(i+1)%poly.size()]);
	return abs(A) / 2;
}


int ys[300][301];
double ans[300];
int main() {
	int n, k;
	scanf("%d%d", &n, &k);
	rep(i, n) rep(j, k+1) scanf("%d", &ys[i][j]);
	rep(j, k) {
		G poly;
		poly.push_back(P(0, 0));
		poly.push_back(P(1, 0));
		poly.push_back(P(1, 1000));
		poly.push_back(P(0, 1000));
		double a = area(poly);
		rep(i, n) {
			poly = convex_cut(poly, P(0, ys[i][j]), P(1, ys[i][j+1]));
			double b = area(poly);
			ans[i] += a - b;
			a = b;
		}
	}
	rep(i, n) printf("%.10f\n", ans[i]);
	return 0;
}