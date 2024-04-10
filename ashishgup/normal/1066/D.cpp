#include <bits/stdc++.h>
using namespace std;
 
#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define endl "\n"
#define int long long

const int N=2e5+5;

int n, m, k;
int a[N];

int check(int idx)
{
	int boxes=1;
	int curleft=k;
	for(int i=idx;i<=n;i++)
	{
		if(curleft-a[i]<0)
		{	
			boxes++;
			curleft=k-a[i];
		}
		else
			curleft-=a[i];
		if(boxes>m)
			return 0;
	}
	return 1;
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
	return lo;
}

int32_t main()
{
	IOS;
	cin>>n>>m>>k;
	for(int i=1;i<=n;i++)
		cin>>a[i];
	int ans=binsearch(1, n);
	cout<<n-ans+1;
	return 0;
}