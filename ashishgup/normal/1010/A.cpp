#include <bits/stdc++.h>
using namespace std;
 
#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define endl "\n"
#define int long long
#define double long double

const int N=1e5+5;

int n, m;
double a[N], b[N];

double check(double cur)
{
	double w=m+cur;
	for(int i=1;i<=n;i++)
	{
		w-=(w/a[i]);
		w-=(w/b[i]);
		if(w<m)
			return 0;
	}
	return 1;
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
	cin>>n>>m;
	for(int i=1;i<=n;i++)
		cin>>a[i];
	for(int i=1;i<=n;i++)
		cin>>b[i];
	a[n+1]=a[1];
	b[n+1]=b[1];
	double ans=binsearch(0, 1e10);
	if(ans>5e9)
	{
		cout<<"-1";
		return 0;
	}
	cout<<fixed<<setprecision(12)<<ans;
	return 0;
}