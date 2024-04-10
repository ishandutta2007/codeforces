#include <bits/stdc++.h>
using namespace std;
 
#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define endl "\n"
#define int long long
#define double long double

const int N=2e5+5;

int n, w;
double a[N], b[N], c[N];

bool check(double &val)
{
	double girls=val/(n*3);
	double boys=2*val/(n*3);
	return a[1]>=girls && a[n+1]>=boys;
}

double binsearch(double lo, double hi)
{
	for(int i=1;i<=100;i++)
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
	cin>>n>>w;
	for(int i=1;i<=2*n;i++)
		cin>>a[i];
	sort(a+1, a+2*n+1);
	double ans=binsearch(0, w);
	cout<<fixed<<setprecision(12)<<ans;
	return 0;
}