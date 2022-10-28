#include <bits/stdc++.h>
using namespace std;
 
#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define endl "\n"
#define int long long
#define double long double

const int N=1e5+5;

int n, p;
int a[N], b[N];

bool check(double t)
{
	double reqd=0;
	for(int i=1;i<=n;i++)
	{
		reqd+=max((double)0, a[i]*t - b[i]);
	}
	return reqd<=t*p;
}

double binsearch(double lo, double hi)
{
	while((double)clock()/CLOCKS_PER_SEC < 0.5)
	{
		double mid=(lo+hi)/2;
		if(check(mid))
			lo=mid;
		else
			hi=mid;
	}
	return lo;
}

int32_t main()
{
	IOS;    
	cin>>n>>p;
	int tot=0;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i]>>b[i];
		tot+=a[i];
	}
	if(p>=tot)
	{
		cout<<"-1";
		return 0;
	}
	double ans=binsearch(0, 1e18);
	cout<<fixed<<setprecision(12)<<ans;
	return 0;
}