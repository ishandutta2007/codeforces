#include <bits/stdc++.h>
#define mod 1000000007
#define int long long
using namespace std;
int a[1000005];
inline int cal(int x,int y)
{
	return max((x+1)/2,max((y+1)/2,(x+y+2)/3));
}
signed main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	int n;
	cin >> n;
	int mn=1e9,x=1e9;
	for(int i=1;i<=n;i++)
	{
		cin >> a[i];
		if(a[i]<mn) x=mn,mn=a[i];
		else if(a[i]<x) x=a[i];
	}
	int ans=(mn+1)/2+(x+1)/2;
	for(int i=1;i<n;i++) ans=min(ans,cal(a[i],a[i+1]));
	for(int i=1;i<n-1;i++)
	{
		ans=min(ans,min(a[i],a[i+2])+((max(a[i],a[i+2])-min(a[i],a[i+2])+1)/2));
	}
	cout << ans;
	return 0;
}