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

double a[7];
int main() {
	double r=0;
	cin >> a[3] >> a[4] >> a[5];
	REP(n,3,5) {
		double be = 2*M_PI/n, al = (M_PI-be)/2;
		double sa = sin(al), sb = sin(be);
		//printf("%.2lf %.2lf %.2lf %.2lf\n", al, be, sa, sb);
		double b = sa/sb*a[n];
		double h = sqrt(a[n]*a[n]-b*b);
		double V = b*b*n*sb*h/6.;
		//printf("%.2lf %.2lf %.2lf\n", b, h, V);
		r += V;
	}
	printf("%.10lf\n", r);
	return 0;
}