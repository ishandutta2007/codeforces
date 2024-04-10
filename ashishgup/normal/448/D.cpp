#include <bits/stdc++.h>
using namespace std;

#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define endl "\n"
#define int long long

int n, m, k;

bool check(int a)
{
	int ct=0;
	for(int i=1;i<=n;i++)
	{
		ct+=min((a-1)/i, m);
	}
	return ct<k;
}

int binsearch(int lo, int hi)
{
	while(lo<hi)
	{
		int mid=(lo+hi+1)>>1;
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
	cin>>n>>m>>k;
	int ans=binsearch(1, n*m);
	cout<<ans;
	return 0;
}