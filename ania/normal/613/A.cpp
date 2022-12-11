#include<bits/stdc++.h>

using namespace std;

#define REP(i,a,b) for(int i = (a); i <= (b); ++i)
#define FORI(i,n) REP(i,1,n)
#define FOR(i,n) REP(i,0,int(n)-1)
#define mp make_pair
#define pb push_back
#define pii pair<int,int>
#define vi vector<int>
#define ll long long
#define SZ(x) ((int)((x).size()))
#define IN(x,y) ((y).find((x)) != (y).end())
#define DBG(v) cerr<<#v<<" = "<<(v)<<endl;
#define FOREACH(i,t) for (typeof(t.begin()) i = t.begin(); i != t.end(); ++i)
#define fi first
#define se second

double get(int x, int y, int dx, int dy) {
	double t = -1.0 * x * dx - 1.0 * y * dy;
	t /= 1.0 * dx*dx + 1.0*dy*dy;
	if (t<0) t=0;
	if (t>1) t=1;
	double x0 = x+t*dx, y0 = y+t*dy;
	return x0*x0 + y0*y0;
}

int x[100100], y[100100];

int main() {
	int n,px,py;
	double rmi = -1, rma = -1;
	scanf("%d%d%d", &n, &px, &py);
	FOR(i,n) {
		scanf("%d%d", &x[i], &y[i]);
		x[i] -= px;
		y[i] -= py;
	}
	x[n] = x[0];
	y[n] = y[0];
	FOR(i,n) {
		double r = get(x[i], y[i], x[i+1]-x[i], y[i+1]-y[i]);
		if (i==0 || r>rma) rma=r;
		if (i==0 || r<rmi) rmi=r;
		r = 1.0 * x[i] * x[i] + 1.0 * y[i] * y[i];
		if (r>rma) rma=r;
		if (r<rmi) rmi=r;
	}
	//printf("%lf %lf\n", rma, rmi);
	printf("%.10lf\n", M_PI*(rma-rmi));
	return 0;
}