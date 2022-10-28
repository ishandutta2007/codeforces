#include <bits/stdc++.h>
using namespace std;
 
#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define endl "\n"

const int N=1e5+5;

int n, k;
char a[N];
int pref[N];

int check(int dist)
{
	for(int i=1;i<=n;i++)
	{
		if(a[i]=='1')
			continue;
		int left=pref[i-1] - pref[max(0, i-dist-1)];
		int right=pref[min(i+dist, n)] - pref[i];
		if(left+right>=k)
			return 1;
	}
	return 0;
}

int binsearch(int lo, int hi)
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

int32_t main()
{
	IOS;
	cin>>n>>k;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
		pref[i]=pref[i-1] + (a[i]=='0');
	}
	int ans=binsearch(0, n);
	cout<<ans;
}