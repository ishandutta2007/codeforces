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

int main() {
	int a,b,c;
	cin >> a >> b >> c;
	double d = b*b-4*a*c;
	d = sqrt(d);
	double x = 0.5*(d-b)/a, y = 0.5*(-d-b)/a;
	printf("%.10lf\n%.10lf\n", max(x,y), min(x,y));
	return 0;
}