#include <bits/stdc++.h>
using namespace std;
 
#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define endl "\n"

const int N=1505;

int n, s, m, k;
int a[N], l[N], r[N];
int pref[N], maxr[N];
int cache[N][N];

int dp(int idx, int smaller)
{
	if(smaller>=k)
		return 0;
	if(idx==n+1)
		return 1e9;
	int &ans=cache[idx][smaller];
	if(ans!=-1)
		return ans;
	ans=dp(idx+1, smaller);
	int getr=maxr[idx];
	if(maxr[idx]>=idx)
	{
		int cur=pref[maxr[idx]] - pref[idx-1];
		ans=min(ans, 1 + dp(maxr[idx]+1, smaller+cur));
	}
	return ans;
}

int check(int x)
{
	memset(cache, -1, sizeof(cache));
	memset(pref, 0, sizeof(pref));
	for(int i=1;i<=n;i++)
		pref[i]=pref[i-1] + (a[i]<=x);
	int minreqd=dp(1, 0);
	return minreqd<=m;
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
	if(check(lo))
		return lo;
	else
		return -1;
}

int32_t main()
{
	IOS;
	cin>>n>>s>>m>>k;
	for(int i=1;i<=n;i++)
		cin>>a[i];
	for(int i=1;i<=s;i++)
	{
		cin>>l[i]>>r[i];
		for(int j=l[i];j<=r[i];j++)
			maxr[j]=max(maxr[j], r[i]);
	}
	int ans=binsearch(1, 1e9);
	cout<<ans;
	return 0;
}