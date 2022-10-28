#include <bits/stdc++.h>
using namespace std;
 
#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define endl "\n"
#define int long long

int n, l, v1, v2, k;

int check(double t)
{
	double newdist = l - v1 * t;
	if(newdist<=0)
		return 1;
	double bustime=newdist/(v2-v1);
	double cover=newdist/(v2+v1);
	double groups=(n+k-1)/k;
	double timetaken=groups * bustime + (groups-1) * cover;
	return (timetaken<=t);
}

double binsearch(double lo, double hi)
{
	while((double)clock()/CLOCKS_PER_SEC < 0.9)
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
	cin>>n>>l>>v1>>v2>>k;
	double ans=binsearch(0, 1e18);
	cout<<fixed<<setprecision(12)<<ans<<endl;
	return 0;
}