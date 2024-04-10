#include <bits/stdc++.h>
using namespace std;
 
#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define endl "\n"
#define int long long

const int N=1e4+5;

int n, c;
int a[N], b[N];

int calc(int x)
{
	int ans=0;
	for(int i=1;i<=n;i++)
	{
		long double cur=(long double)a[i]*x;
		cur/=b[i];
		cur=floorl(cur);
		if(cur>c)
			return c+1;
		ans+=round(floorl(cur));
		if(ans>c)
			return ans;
	}
	return ans;
}

int check(int mid)
{	
	return calc(mid)>=c;
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

int check2(int mid)
{	
	return calc(mid)>c;
}

int binsearch2(int lo, int hi)
{
	while(lo<hi)
	{
		int mid=(lo+hi+1)/2;
		if(check2(mid))
			hi=mid-1;
		else
			lo=mid;
	}
	return lo;
}

int32_t main()
{
	IOS;
	cin>>n>>c;
	c-=n;
	for(int i=1;i<=n;i++)
		cin>>a[i]>>b[i];
	int ans1=binsearch(1, 2e18);
	int ans2=binsearch2(1, 2e18);
	if(!check(ans1))
		ans1++;
	if(check2(ans2))
		ans2--;
	if(!check(ans1) && !check2(ans2))
	{
		cout<<"0";
		return 0;
	}
	if(ans2==2e18)
	{
		ans2=ans1-2;
	}
	cout<<ans2-ans1+1;
	return 0;
}