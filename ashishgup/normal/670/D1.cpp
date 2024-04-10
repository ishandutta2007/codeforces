#include <bits/stdc++.h>
using namespace std;
 
#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define endl "\n"
#define int long long

const int N=2e5+5;

int n, k;
int a[N], b[N];

int check(int dish)
{
	int powder=0;
	for(int i=1;i<=n;i++)
	{
		int reqd=a[i]*dish;
		if(b[i]-reqd<0)
			powder+=(reqd-b[i]);
		if(powder>k)
			return 0;
	}
	return 1;
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
	return lo;
}

int32_t main()
{
	IOS;
	cin>>n>>k;
	for(int i=1;i<=n;i++)
		cin>>a[i];
	for(int i=1;i<=n;i++)
		cin>>b[i];
	int ans=binsearch(0, 2e9);
	cout<<ans;
	return 0;
}