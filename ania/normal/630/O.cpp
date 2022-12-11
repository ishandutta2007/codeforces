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

pair<double,double> t[7];
int main() {
	int px,py,vx,vy,a,b,c,d;
	cin >> px >> py >> vx >> vy >> a >> b >> c >> d;
	t[0].se = b;
	t[1].fi = -0.5*a;
	t[2].fi = -0.5*c;
	t[3].fi = -0.5*c;
	t[3].se = -d;
	t[4].fi = 0.5*c;
	t[4].se = -d;
	t[5].fi = 0.5*c;
	t[6].fi = 0.5*a;
	double D = sqrt(vx*vx+vy*vy);
	double VX=vx/D, VY=vy/D;
	FOR(i,7) {
		double tx = VY*t[i].fi+VX*t[i].se, ty = VY*t[i].se-VX*t[i].fi;
		t[i].fi=tx;
		t[i].se=ty;
	}
	FOR(i,7) {
		t[i].fi += px;
		t[i].se += py;
		printf("%.10lf %.10lf\n", t[i].fi, t[i].se);
	}
	return 0;
}