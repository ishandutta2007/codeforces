#include <bits/stdc++.h>
using namespace std;

#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define endl "\n";
#define int long long

int n;

int check(int k)
{
	int cur=n;
	int had=0;
	while(cur!=0)
	{
		had+=min(cur, k);
		cur-=min(cur, k);
		cur-=cur/10;
	}
	return 2*had>=n;
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
	cin>>n;
	int ans=binsearch(1, n);
	cout<<ans;
}