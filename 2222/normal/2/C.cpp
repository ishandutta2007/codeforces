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

#define all(a)		(a).begin(),(a).end()
#define sz(a)		int((a).size())
#define FOR(i,a,b)	for(int i=a;i<b;++i)
#define REP(i,n)	FOR(i,0,n)
#define UN(v)		sort(all(v)),(v).erase(unique((v).begin(),(v).end()),(v).end())
#define CL(a,b)		memset(a,b,sizeof a)
#define pb			push_back
#define X			first
#define Y			second

typedef long long ll;
typedef vector<int> vi;
typedef pair<int,int> pii;

typedef complex<double> point;

#define x	real()
#define y	imag()

point p[3],res;
double r[3],A[3],B[3],C[3],D[3],best=1e111;

double det(double a,double b,double c,double d){ return a*d-b*c; }

void check(point c){
	double mind = 1e111, maxd = -mind;
	REP(i,3) 
		mind = min(mind, abs(c - p[i]) / r[i]),
		maxd = max(maxd, abs(c - p[i]) / r[i]);
	if (maxd - mind < 1e-8 && maxd < best)
		best = maxd, res = c;
}

void circle(double A, double B, double C, double D, point& c, double& r2){
	c = point(-B, -C) / (2 * A);
	r2 = D/A + c.x*c.x + c.y*c.y;
}

void Solve(	double a1,double b1,double c1,double d1,
			double a2,double b2,double c2,double d2)
{
	if (fabs(a1) > fabs(a2))
		Solve(a2, b2, c2, d2, a1, b1, c1, d1);
	else if(fabs(a2) < 1e-8){
		double d=det(b1, c1, b2, c2);
		point c(det(d1, c1, d2, c2) / d,
				det(b1, d1, b2, d2) / d);
		check(c);
	} else if(fabs(a1) < 1e-8){
		double d = hypot(b1, c1);
		b1 /= d, c1 /= d, d1 /= d;
		point p2; double r2;
		circle(a1, b2, c2, d2, p2, r2);
		double h = b1 * p2.x + c1 * p2.y - d1;
		p2 -= point(b1, c1) * h;
		d = sqrt (max(0., r2 - h * h));
		check(c2 + point(c1, -b1) * d);
		check(c2 - point(c1, -b1) * d);
	} else {
		point a, b;
		double ra, rb, d;
		circle(a1, b1, c1, d1, a, ra);
		circle(a2, b2, c2, d2, b, rb);
		d = abs(a - b);
		double z = (d * d + ra - rb) / (2 * d);
		double h = sqrt(max(0., ra - z*z));
		check(a + (b-a) * point(z, +h) / d);
		check(a + (b-a) * point(z, -h) / d);
	}
}

int main(){
	#ifdef LocalHost
	freopen("x.in","r",stdin);
	freopen("y.out","w",stdout);
	#endif
	double a[3],b[3],c[3],d[3];
	int k = 0;
	REP(i,3){
		cin>>p[i].x>>p[i].y>>r[i];
		A[i]=1/(r[i]*r[i]);
		B[i]=-2*A[i]*p[i].x;
		C[i]=-2*A[i]*p[i].y;
		D[i]=A[i]*(r[i]*r[i] - p[i].x*p[i].x - p[i].y*p[i].y);
		REP(j,i)
			a[k] = A[i] - A[j],
			b[k] = B[i] - B[j],
			c[k] = C[i] - C[j],
			d[k++] = D[i] - D[j];
	}
	REP(j,k)REP(i,j) 
		Solve(	a[i], b[i], c[i], d[i],
				a[j], b[j], c[j], d[j]);
	if(best != 1e111)
		printf("%.5lf %.5lf\n", res.x, res.y);
	return 0;
}