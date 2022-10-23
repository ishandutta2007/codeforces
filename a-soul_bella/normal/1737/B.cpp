#include <bits/stdc++.h>
#define int long long
#define mod 998244353
using namespace std;
int a[1000005],ans[1005];
int cal(int x)
{
	int rtn=0;
	int l=0,r=2e9,ans=0;
	while(l<=r)
	{
		int mid=(l+r)/2;
		if(mid*mid<=x) ans=mid,l=mid+1;
		else r=mid-1;
	}
	rtn+=ans;l=0,r=2e9,ans=0;
	while(l<=r)
	{
		int mid=(l+r)/2;
		if(mid*(mid+1)<=x) ans=mid,l=mid+1;
		else r=mid-1;
	}
	rtn+=ans;l=0,r=2e9,ans=0;
	while(l<=r)
	{
		int mid=(l+r)/2;
		if(mid*(mid+2)<=x) ans=mid,l=mid+1;
		else r=mid-1;
	}
	rtn+=ans;
	for(int i=1;i<=20;i++)
	{
		if(i*i<=min(100ll,x)) --rtn;
		if(i*(i-1)<=min(100ll,x)) --rtn;
		if(i*(i-2)<=min(100ll,x)) --rtn;
	}
	for(int i=1;i<=min(100ll,x);i++)
	{
		int X=sqrt(i);
		if(i%X==0) ++rtn;
	}
	return rtn;
}
signed main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	int T;
	cin >> T;
	while(T--)
	{
		int l,r;
		cin >> l >> r;
		cout << cal(r)-cal(l-1) << "\n";
	}
	return 0;
}