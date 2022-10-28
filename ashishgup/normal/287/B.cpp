#include <bits/stdc++.h>
using namespace std;
 
#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define endl "\n"
#define int long long

const int N=1e6+5;

int n, k;

int check(int x)
{
	int have=k*(k-1)/2;
	have-=x*(x-1)/2;
	return have>=n-1;
}

int binsearch(int lo, int hi)
{
	while(lo<hi)
	{
		int mid=(lo+hi+1)/2;
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
	int extra=n-1;
	int tot=k*(k-1)/2;
	if(extra>tot)
	{
		cout<<"-1";
		return 0;
	}
	int ans=binsearch(1, k+1);
	ans=(k-ans);
	cout<<ans;
	return 0;
}