#include <bits/stdc++.h>
using namespace std;
 
#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define endl "\n"
#define int long long

const int N=1e5+5;

int n, m, ans=0;
int a[N], b[N];

int calc(int k)
{
	int ops=0;
	for(int i=1;i<=n;i++)
		ops+=max(0LL, k-a[i]);
	for(int i=1;i<=m;i++)
		ops+=max(0LL, b[i]-k);
	return ops;
}

int ternary_search(int lo, int hi)
{
	while(lo<hi-2)
	{
		int mid1=(2*lo+hi)/3;
		int mid2=(lo+2*hi)/3;
		if(calc(mid1)<calc(mid2))
			hi=mid2;
		else
			lo=mid1;
	}
	int ans=calc(lo);
	for(int i=lo+1;i<=lo+2;i++)
		ans=min(ans, calc(i));
	return ans;	
}
	
int32_t main()
{
	IOS;
	cin>>n>>m;
	for(int i=1;i<=n;i++)
		cin>>a[i];
	for(int i=1;i<=m;i++)
		cin>>b[i];
	sort(a+1, a+n+1);
	sort(b+1, b+m+1);
	int ans=ternary_search(1, 1e9);
	cout<<ans;
	return 0;
}