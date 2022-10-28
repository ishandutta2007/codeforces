#include <bits/stdc++.h>
using namespace std;

#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define endl "\n"

const int N=1e3+5;
const int offset=1e4+5;
const int MOD=1e9+7;

int n, finans=0;
int a[N];
int cache[N][offset*2], vis[N][offset*2];

int dp(int i, int sum)
{
	if(i==n+1)
	{
		if(sum==0)
			return 1;
		else
			return 0;
	}
	if(vis[i][sum+offset])
		return cache[i][sum+offset];
	vis[i][sum+offset]=1;
	int ans=dp(i+1, sum-a[i]) + dp(i+1, sum+a[i]);
	ans%=MOD;
	cache[i][sum+offset]=ans;
	return ans;
}

int32_t main()
{
	IOS;
	cin>>n;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
	}
	for(int i=n;i>=1;i--)
	{
		finans+=dp(i, 0);
		finans%=MOD;
		cache[i][offset]++; //Incrementing cache[i][offset] to account for the arrays ending at position i with balance 0
		cache[i][offset]%=MOD;
	}
	cout<<finans;
}