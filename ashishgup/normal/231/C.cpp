#include <bits/stdc++.h>
using namespace std;

#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define endl "\n"
#define int long long

const int N=1e5+5;

int n, k, store;
int a[N], pref[N];

int check(int f)
{
	for(int i=f;i<=n;i++)
	{
		int reqd=(a[i]*f)-(pref[i]-pref[i-f]);
		if(reqd<=k)
		{
			store=a[i];
			return 1;
		}
	}
	return 0;
}

int binsearch(int lo, int hi)
{
	while(lo<hi)
	{
		int mid=(lo+hi+1)>>1;
		if(check(mid))
			lo=mid;
		else
			hi=mid-1;
	}
	check(lo);
	return lo;
}

int32_t main()
{
	IOS;
	cin>>n>>k;
	for(int i=1;i<=n;i++)
		cin>>a[i];
	sort(a+1, a+n+1);
	for(int i=1;i<=n;i++)
		pref[i]=pref[i-1]+a[i];
	int ans=binsearch(1, n);
	cout<<ans<<" "<<store;
	return 0;   
}