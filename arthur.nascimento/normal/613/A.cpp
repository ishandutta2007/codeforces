#include <iostream>
#include <iomanip>
#include <algorithm>
#include <cmath>
#include <assert.h>
#include <stdio.h>
#include <ctime>
#include <cstdlib>
#include <string>
#include <utility>
#include <string.h>
#include <vector>
#include <queue>
#include <stack>
#include <set>
#include <map>
#include <complex>

#define inf 1000000007
#define pii pair<int,int>
#define pip pair<int,pii>
#define pll pair<long long,long long>
#define pif pair<int,double>
#define eps 1e-7

#ifdef ONLINE_JUDGE
#define debug(args...)
#else
#define debug(args...) fprintf(stderr,args)
#endif

#define pb push_back
#define mod 1000000007
#define maxn 100100
#define sq(x) ((x)*(x))

using namespace std;

long double a[maxn];
long double b[maxn];

main(){

	int n;
	long double x,y;
	cin >> n >> x >> y;

	long double dmax, dmin;

	for(int i=0;i<n;i++){
		cin >> a[i] >> b[i];
		long double d = sqrt(sq(a[i]-x)+sq(b[i]-y));
		if(i == 0)
			dmax = dmin = d;
		if(d > dmax)
			dmax = d;
		if(d < dmin)
			dmin = d;
	}
	a[n] = a[0];
	b[n] = b[0];

	for(int i=0;i<n;i++){

		long double dx = a[i+1]-a[i];
		long double dy = b[i+1]-b[i];
		long double low = 0, up = 1, d1, d2;
		for(int j=0;j<100;j++){
			long double mid1 = (2*low+up)/3, mid2 = (low+2*up)/3;
			long double xa = a[i] + mid1*dx, ya = b[i] + mid1*dy, xb = a[i] + mid2*dx, yb = b[i] + mid2*dy;
			d1 = sqrt(sq(xa-x)+sq(ya-y)), d2 = sqrt(sq(xb-x)+sq(yb-y));
			if(d1 < d2)
				up = mid2;
			else
				low = mid1;
		}
		if(d1 < dmin)
			dmin = d1;
	
	}

	double ans = acos(-1) * (dmax*dmax - dmin*dmin);

	printf("%.10lf\n",ans);

}