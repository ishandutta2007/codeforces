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

int x,y,vmax,t0,vx,vy,wx,wy;

bool ok(double ti) {
	if (ti <= t0) {
		double px = x - ti*vx, py = y - ti*vy;
		double di = hypot(px, py);
		double tr = di / vmax;
		return tr <= ti;
	} else {
		ti -= t0;
		double px = x - t0*vx - ti*wx, py = y - t0*vy - ti*wy;
		double di = hypot(px, py);
		double tr = di / vmax;
		return tr <= ti+t0;
	}
}

int main() {
	int aax, aay;
	scanf("%d%d%d%d", &aax, &aay, &x, &y);
	x -= aax; y -= aay;
	scanf("%d%d", &vmax, &t0);
	scanf("%d%d%d%d", &vx, &vy, &wx, &wy);
	
	double tmin = 0, tmax = 1e9;
	FOR(_,1000) {
		double tmid = (tmin+tmax)/2;
		//printf("t = %lf %lf %lf\n", tmin, tmid, tmax);
		if (ok(tmid)) tmax=tmid;
		else tmin=tmid;
	}
	printf("%.10lf\n", tmin);
	return 0;
}