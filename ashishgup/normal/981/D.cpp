#include <bits/stdc++.h>
using namespace std;
 
#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define endl "\n"
#define int long long

const int N=55;

int n, k, mask;
int a[N];
int cache[N][N];

int dp(int idx, int groups)
{
	if(idx==n+1)
	{
		if(groups==k)
			return 1;
		return 0;
	}
	int &ans=cache[idx][groups];
	if(ans!=-1)
		return ans;
	ans=0;
	int cursum=0;
	for(int j=idx;j<=n;j++)
	{
		cursum+=a[j];
		if((cursum&mask) == mask)
		{
			ans|=dp(j+1, groups+1);
		}
	}
	return ans;
}

int check(int cur)
{
	memset(cache, -1, sizeof(cache));
	mask=cur;
	return dp(1, 0);
}

int32_t main()
{
	IOS;
	cin>>n>>k;
	for(int i=1;i<=n;i++)
		cin>>a[i];
	int ans=0;
	for(int i=60;i>=0;i--)
	{
		if(check(ans+(1LL<<i)))
		{
			ans+=(1LL<<i);
		}
	}
	cout<<ans;
	return 0;
}