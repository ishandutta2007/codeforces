#include <bits/stdc++.h>
using namespace std;
 
#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define endl "\n"
#define int long long

const int N=2e5+5;

int n, m, sum=0;
int a[N], sz[N];

int check(int x)
{
	for(int i=0;i<x;i++)
		sz[i]=0;
	int idx=0, sum=0, rem=0;
	for(int i=1;i<=n;i++)
	{
		sum+=a[i];
		int cursz=sz[idx];
		rem-=cursz*(cursz-1)/2;
		sz[idx]++;
		cursz=sz[idx];
		rem+=cursz*(cursz-1)/2;
		idx++;
		idx%=x;
		if(sum-rem>=m)
			return 1;
	}
	return 0;
}

int binsearch(int lo, int hi)
{
	while(lo<hi)
	{
		int mid=(lo+hi)/2;
		if(check(mid))
			hi=mid;
		else
			lo=mid+1;
	}
	if(!check(lo))
		lo=-1;
	return lo;
}

int32_t main()
{
	IOS;
	cin>>n>>m;
	for(int i=1;i<=n;i++)
		cin>>a[i];
	sort(a+1, a+n+1);
	reverse(a+1, a+n+1);
	int ans=binsearch(1, n);
	cout<<ans;
	return 0;
}