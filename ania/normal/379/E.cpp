#include<algorithm>
#include<bitset>
#include<cctype>
#include<cmath>
#include<cstring>
#include<cstdio>
#include<cstdlib>
#include<ctime>
#include<deque>
#include<functional>
#include<iomanip>
#include<iostream>
#include<list>
#include<map>
#include<numeric>
#include<queue>
#include<set>
#include<sstream>
#include<stack>
#include<string>
#include<utility>
#include<vector>

using namespace std;

#define REP(i,a,b) for(int i = (a); i <= (b); ++i)
#define FORI(i,n) REP(i,1,n)
#define FOR(i,n) REP(i,0,int(n)-1)
#define mp make_pair
#define pb push_back
#define pii pair<int,int>
#define vi vector<int>
#define ll long long
#define FOREACH(i,t) for (typeof(t.begin()) i = t.begin(); i != t.end(); ++i)
#define fi first
#define se second

int n,k;
int y[333][333];
double res[333];
pair<double,double> pt[333], npt[333];
int pos, npos;

void clear() {
	pos = 0;
}

pair<double,double> cut(pair<double, double> p1, pair<double,double> p2, double a, double b) {
	//printf("cut %lf %f, %lf %lf, %lf, %lf\n", p1.fi,p1.se,p2.fi,p2.se,a,b);
	double k = (p1.fi-p2.fi) / (p1.se-p2.se);
	double m = p1.fi - k*p1.se;
	//printf("k=%lf,m=%lf\n",k,m);
	double rx = (a-m) / (k-b+a);
	double ry = k*rx+m;
	return mp(ry,rx);
}

void add(int a, int b) {
	//printf("add %d %d\n", a, b);
	if (pos == 0 || (a >= pt[0].fi && b >= pt[pos-1].fi)) {
		pos = 2;
		pt[0] = mp(a,0);
		pt[1] = mp(b,1);
		return;
	}
	bool lw = a < pt[0].fi;
	if (lw) {
		npt[0] = pt[0];
	} else {
		npt[0] = mp(a,0);
	}
	npos = 1;
	for (int i = 1; i < pos; i++) {
		double h = pt[i].se * (b-a) + a;
		bool now = h < pt[i].fi;
		if (lw) {
			if (!now) {
				npt[npos] = cut(pt[i-1], pt[i], a, b);
				npos++;
				lw = false;
			} else {
				npt[npos] = pt[i];
				npos++;
			}
		} else {
			if (now) {
				npt[npos] = cut(pt[i-1], pt[i], a, b);
				npos++;
				lw = true;
				npt[npos] = pt[i];
				npos++;
			}
		}
	}
	if (!lw) {
		npt[npos] = mp(b,1);
		npos++;
	}
	FOR(i,npos) pt[i] = npt[i];
	pos = npos;
}

double get() {
	//printf("%d points:\n", pos);
	//FOR(i,pos) {
	//	printf("%lf %lf\n", pt[i].fi, pt[i].se);
	//}
	double cur = 0;
	FOR(i,pos-1) {
		cur += (pt[i].fi+pt[i+1].fi) * (pt[i+1].se-pt[i].se);
	}
	return cur / 2.0;
}

int main() {
	scanf("%d%d", &n, &k);
	FOR(i,n) FOR(j,k+1) scanf("%d", &y[i][j]);
	FOR(j,k) {
		clear();
		FOR(i,n) {
			add(y[i][j], y[i][j+1]);
			res[i] += get();
		}
	}
	for (int i = n-2; i >= 0; i--) res[i+1] -= res[i];
	FOR(i,n) printf("%.5lf\n", res[i]);
	return 0;
}