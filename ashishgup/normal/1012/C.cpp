#include <bits/stdc++.h>
using namespace std;
 
#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define endl "\n"

const int N=5005;

int n;
int a[N];
int cache[N][2502][2];

int dp(int idx, int k, int check)
{
	if(k==0)
		return 0;
	if(idx>=n+1)
		return 1e9;
	int &ans=cache[idx][k][check];
	if(ans!=-1)
		return ans;
	ans=dp(idx+1, k, 0);
	if(check)
	{
		int cost=max(0, min(a[idx-2]-1, a[idx-1]) - (a[idx] - 1));
		cost+=max(0, a[idx+1] - (a[idx] - 1));
		ans=min(ans, cost + dp(idx+2, k-1, 1));
	}
	else
	{
		int cost=max(0,  a[idx-1] - (a[idx] - 1));
		cost+=max(0, a[idx+1] - (a[idx] - 1));
		ans=min(ans, cost + dp(idx+2, k-1, 1));
	}
	return ans;
}

int32_t main()
{
	IOS;
	memset(cache, -1, sizeof(cache));
	cin>>n;
	for(int i=1;i<=n;i++)
		cin>>a[i];
	for(int i=1;i<=(n+1)/2;i++)
		cout<<dp(1, i, 0)<<" ";
	return 0;
}