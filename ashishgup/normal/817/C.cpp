#include <bits/stdc++.h>
using namespace std;

#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define endl "\n"
#define int long long

int n, s;

bool check(int k)
{
	int sumofdigits=0;
	int cur=k;
	while(cur>0)
	{
		int rem=cur%10;
		sumofdigits+=rem;
		cur=cur/10;
	}
	return ((k-sumofdigits)>=s);
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
	cin>>n>>s;
	int ans=n-binsearch(0,n+1)+1;
	cout<<ans;
	return 0;
}