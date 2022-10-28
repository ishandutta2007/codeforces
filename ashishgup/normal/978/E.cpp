#include <bits/stdc++.h>
using namespace std;
 
#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define endl "\n"
#define int long long

const int N=1e6+5;

int n, w;
int a[N];

int check(int k)
{
	for(int i=1;i<=n;i++)
	{
		k+=a[i];
		if(k<0)
			return 0;
	}
	return 1;
}

int check2(int k)
{
	for(int i=1;i<=n;i++)
	{
		k+=a[i];
		if(k>w)
			return 0;
	}
	return 1;
}

int binsearch1(int lo, int hi)
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

int binsearch2(int lo, int hi)
{
	while(lo<hi)
	{
		int mid=(lo+hi+1)>>1;
		if(check2(mid))
			lo=mid;
		else
			hi=mid-1;
	}
	return lo;
}

int32_t main()
{
	IOS;
	cin>>n>>w;
	for(int i=1;i<=n;i++)
		cin>>a[i];
	int min1=binsearch1(0, w);
	int max1=binsearch2(0, w);
	if(!check(min1) || !check2(min1) || !check(max1) || !check2(max1))
	{
		cout<<"0";
		return 0;
	}
	cout<<max1-min1+1;
	return 0;
}