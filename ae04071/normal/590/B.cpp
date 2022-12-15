#include <bits/stdc++.h>
#define fi first
#define se second
#define sz(x) ((int)x.size())
using namespace std;
using pii=pair<int,int>;
using lli = long long;

pii s,t,a[2];
int v,T;

inline double pw(double v) {return v*v;}
int main() {
	scanf("%d%d%d%d%d%d",&s.fi,&s.se,&t.fi,&t.se,&v,&T);
	for(int i=0;i<2;i++) scanf("%d%d",&a[i].fi,&a[i].se);
	t.fi -= s.fi; t.se -= s.se;

	double lo=0,up=2e9;
	for(int iter=0;iter<200;iter++) {
		double md=(lo+up)/2;
		double x = min(1.0*T, md)*a[0].fi + max(md-1.0*T, 0.0)*a[1].fi;
		double y = min(1.0*T, md)*a[0].se + max(md-1.0*T, 0.0)*a[1].se;
		if(pw(v*md) >= (t.fi-x)*(t.fi-x) + (t.se-y)*(t.se-y)) up=md;
		else lo=md;
	}
	printf("%.10lf\n",up);
	
	return 0;
}