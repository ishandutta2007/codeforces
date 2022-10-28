#include <bits/stdc++.h>
using namespace std;

#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define endl "\n"

const int N=1e5+5;

int n, k;
long double factor, total=0;
long double a[N];

int check(long double cur)
{
	long double have=0;
	long double extra=0;
	for(int i=1;i<=n;i++)
	{
		long double reqd=a[i]-cur;
		if(reqd<0)
		{
			extra+=(fabs(reqd)*factor);
		}
		else
		{
			have+=fabs(reqd);
		}
	}
	return (extra<=have);
}

long double binsearch(long double lo, long double hi)
{
	while((hi-lo)>1e-12)
	{
		long double mid=(lo+hi)/2;
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
    cin>>n>>k;
    for(int i=1;i<=n;i++)
    {
    	cin>>a[i];
    	total+=a[i];
    }
    factor=((long double)100/(100-k));
    long double ans=binsearch(0, 1e3);
    cout<<fixed<<setprecision(12)<<ans;
    return 0;
}