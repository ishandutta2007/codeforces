#include <bits/stdc++.h>
using namespace std;
 
#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define endl "\n"
#define int long long
#define double long double

const int N=1e5+5;

double x1, y1, x2, y2;
double vmax, t;
double vx, vy, wx, wy;

double dist(double &x1, double &y1, double &x2, double &y2)
{
	double xdiff=(x2-x1)*(x2-x1);
	double ydiff=(y2-y1)*(y2-y1);
	return sqrtl(xdiff+ydiff);
}	

bool check(double tim)
{
	if(tim<=t)
	{
		double curx=x1 + tim*vx;
		double cury=y1 + tim*vy;
		double cur=dist(curx, cury, x2, y2);
		double reqd=cur/vmax;
		return (reqd<tim);
	}
	else
	{
		double curx=x1 + t*vx;
		double cury=y1 + t*vy;
		double cur=dist(curx, cury, x2, y2);
		double reqd=cur/vmax;
		if(reqd<=t)
			return 1;
		curx+=(tim-t)*wx;
		cury+=(tim-t)*wy;
		cur=dist(curx, cury, x2, y2);
		reqd=cur/vmax;
		return (reqd<(tim));
	}
}

double binsearch(double lo, double hi)
{
	for(int i=1;i<=200;i++)
	{
		double mid=(lo+hi)/2;
		if(check(mid))
			hi=mid;
		else
			lo=mid;
	}
	return lo;
}

int32_t main()
{
	IOS;
	cin>>x1>>y1>>x2>>y2;
	cin>>vmax>>t;
	cin>>vx>>vy>>wx>>wy;
	double ans=binsearch(0, 1e9);
	cout<<fixed<<setprecision(12)<<ans;
	return 0;
}