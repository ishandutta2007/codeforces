#include <bits/stdc++.h>
using namespace std;
 
#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define endl "\n"
#define int long long

const int N=1e5+5;

int n;
int a[N];

int check(int k)
{
	int host=0;
	for(int i=1;i<=n;i++)
	{
		if(k<a[i])
			return 0;
		host+=max(0LL, k-a[i]);
	}
	return host>=k;
}

int binsearch(int lo, int hi)
{
	while(lo<hi)
	{
		int mid=(lo+hi)>>1;
		if(check(mid))
			hi=mid;
		else
			lo=mid+1;
	}
	return lo;
}

int32_t main()
{
	IOS;
	cin>>n;
	for(int i=1;i<=n;i++)
		cin>>a[i];
	int ans=binsearch(1, 1e12);
	cout<<ans;
	return 0;
}