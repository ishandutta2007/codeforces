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

typedef complex<double> point;

inline double det(double a, double b, double c, double d) { return a * d - b * c; }

int n;

struct line {
	double a, b, c;
	line() {}
	line(point p, point q) {
		a = q.imag() - p.imag();
		b = p.real() - q.real();
		c = p.real() * a + p.imag() * b;
	}
};

vector <line> L;
vector <double> H;

void cross(const line &p, const line &q) {
	double d = det(p.a, p.b, q.a, q.b);
	if (fabs(d) < 1e-9) return;
	H.pb(det(p.a, p.c, q.a, q.c) / d);
}

struct event {
	double x0, x1;
	int id;
};

bool operator < (const event &p, const event &q) {
	return p.x0 + p.x1 < q.x0 + q.x1;
}

const double eps = 1e-9;

double X(const point &p, const point &q, double y) {
	return p.real() + (q.real() - p.real()) * (y - p.imag()) / (q.imag() - p.imag());
}

struct triangle {
	complex<double> p[3];
	void read() {
		REP (i, 3) {
			double x, y;
			cin >> x >> y;
			p[i] = complex<double>(x, y) * polar(1.0, 0.123456789);
			H.pb(p[i].imag());
		}
		REP (i, 3) {
			int j = (i + 1) % 3;
			L.pb(line(p[i], p[j]));
		}
	}
	void f(double y0, double y1, vector<event> &e, int id) {
		REP (i, 3) {
			point P = p[i], Q = p[(i + 1) % 3];
			if (P.imag() > Q.imag()) swap(P, Q);
			if (P.imag() <= y0 + eps && Q.imag() >= y1 - eps) {
				event q;
				q.id = id;
				q.x0 = X(P, Q, y0);
				q.x1 = X(P, Q, y1);
				e.pb(q);
			}
		}
	}
} t[111];

double d2(double x, double y) { return sqrt(x * x + y * y); }

int main(){
	#ifdef LocalHost
	freopen("x.in", "r", stdin);
	freopen("x.out", "w", stdout);
	#endif
	cin >> n;
	REP (i, n) t[i].read();
	REP (j, sz(L)) REP (i, j) cross(L[i], L[j]);
	UN(H);
	double res = 0;
	FOR (i, 1, sz(H)) {
		double y0 = H[i - 1], y1 = H[i];
		if (y1 - y0 > 1e-9) {
			vector <event> e;
			REP (j, n) t[j].f(y0, y1, e, j);
			sort(all(e));
			int k = 0;
			vector <bool> u(n);
			for (vector <event> :: iterator j = e.begin(); j != e.end(); ++j) {
				if (u[j->id]) {
					if (--k == 0) 
						res += d2(j->x0 - j->x1, y1 - y0);
				} else {
					u[j->id] = true;
					if (k++ == 0)
						res += d2(j->x0 - j->x1, y1 - y0);
				}
			}
		}
	}
	printf("%.12lf\n", res);
	return 0;
}