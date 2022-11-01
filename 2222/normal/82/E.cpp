#include <algorithm>
#include <iostream>
#include <sstream>
#include <complex>
#include <numeric>
#include <cstring>
#include <vector>
#include <string>
#include <cstdio>
#include <queue>
#include <cmath>
#include <map>
#include <set>

using namespace std;

#define all(a)			(a).begin(), (a).end()
#define sz(a)			int((a).size())
#define FOR(i, a, b)	for (int i(a); i < b; ++i)
#define REP(i, n)		FOR(i, 0, n)
#define UN(v)			sort(all(v)), (v).erase(unique((v).begin(), (v).end()), (v).end())
#define CL(a, b)		memset(a, b, sizeof a)
#define pb				push_back
#define X				first
#define Y				second

typedef long long ll;
typedef vector <int> vi;
typedef pair <int, int> pii;
typedef pair<double, double> point;
typedef pair<point, point> line;

inline double det(double a, double b, double c, double d) { return a * d - b * c; }

const double eps = 1e-9;

int n, h, f;
int l[555], r[555];
double L[555], R[555];

bool in(int i, double x, double y) {
	if (fabs(y) > h + eps) return false;
	if (x + eps < l[i] + (L[i] - l[i]) * (h - y) / (2 * h)) return false;
	if (x - eps > r[i] + (R[i] - r[i]) * (h - y) / (2 * h)) return false;
	return true;
}

point cross(const line &p, const line &q) {
	double a1 = p.Y.Y - p.X.Y, b1 = p.X.X - p.Y.X, c1 = a1 * p.X.X + b1 * p.X.Y;
	double a2 = q.Y.Y - q.X.Y, b2 = q.X.X - q.Y.X, c2 = a2 * q.X.X + b2 * q.X.Y;
	double d = det(a1, b1, a2, b2);
	if (fabs(d) < eps) return point(0, f);
	return {
		det(c1, b1, c2, b2) / d,
		det(a1, c1, a2, c2) / d
	};
}

void CH(vector<point> &S) {
	FOR (i, 1, sz(S)) 
		if (S[i].X + eps < S[0].X || S[i].X < S[0].X + eps && S[i].Y < S[0].Y)
			swap(S[i], S[0]);
	for (int i = sz(S); i --> 0; ) {
		S[i].X -= S[0].X;
		S[i].Y -= S[0].Y;
	}
	sort(all(S), [](const point &p, const point &q) { 
		double d = det(p.X, p.Y, q.X, q.Y); 
		if (fabs(d) > eps) return d < 0;
		return fabs(p.X) + fabs(p.Y) < fabs(q.X) + fabs(q.Y);
	});
	auto rght = [](const point &p, const point &q, const point &r) {
		return det(p.X - r.X, p.Y - r.Y, q.X - r.X, q.Y - r.Y) < eps;
	};
	vector<point> ch;
	for (point &p : S) {
		for (; sz(ch) > 1 && rght(ch[sz(ch) - 1], ch[sz(ch) - 2],  p); ch.pop_back());
		ch.pb(p);
	}
	S.swap(ch);
}

int main(){
	#ifdef LocalHost
	freopen("x.in", "r", stdin);
	freopen("x.out", "w", stdout);
	#endif
	cin >> n >> h >> f;
	double res = 0;
	REP (i, n) {
		cin >> l[i] >> r[i];
		L[i] = l[i] * double(f + h) / (f - h);
		R[i] = r[i] * double(f + h) / (f - h);
		res += (r[i] + R[i] - l[i] - L[i]) * h;
	}
	res *= 2;
	REP (i, n) REP (j, n) {
		line a[2], b[2];
		
		a[0] = {point(l[i], h), point(L[i], -h)};
		a[1] = {point(r[i], h), point(R[i], -h)};
		b[0] = {point(L[j], h), point(l[j], -h)};
		b[1] = {point(R[j], h), point(r[j], -h)};
		
		vector<point> S;
		
		REP (k, 2) {
			if (in(i, b[k].X.X, b[k].X.Y)) S.pb(b[k].X);
			if (in(i, b[k].Y.X, b[k].Y.Y)) S.pb(b[k].Y);
			if (in(j, a[k].X.X, -a[k].X.Y)) S.pb(a[k].X);
			if (in(j, a[k].Y.X, -a[k].Y.Y)) S.pb(a[k].Y);
			REP (l, 2) {
				point t = cross(a[k], b[l]);
				if (in(i, t.X, t.Y) && in(j, t.X, -t.Y)) S.pb(t);
			}
		}
		if (sz(S) == 0) continue;
		CH(S);
		S.pb(S[0]);
		double area = 0;
		REP (i, sz(S) - 1)
			area += det(S[i].X, S[i].Y, S[i + 1].X, S[i + 1].Y);
		res -= fabs(area) * 0.5;
	}
	printf("%.12lf\n", res);
	return 0;
}