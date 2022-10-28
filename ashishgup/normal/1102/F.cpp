#include <bits/stdc++.h>
using namespace std;
 
#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define endl "\n"
#define int long long

const int N=17;
const int M=1e4+5;

int n, m;
int a[N][M], store[N][N], store2[N][N];
int cache[N][1<<(N-1)][N];

int dp(int start, int mask, int prev)
{
	if((mask+1)==(1<<n))
		return 1e9;
	int &ans=cache[start][mask][prev];
	if(ans!=-1)
		return ans;
	ans=0;
	int cnt=__builtin_popcount(mask);
	for(int i=0;i<n;i++)
	{
		if(mask>>i & 1)
			continue;
		int prv=prev+1;
		int nxt=i+1;
		int cur=min(store[prv][nxt], dp(start, mask|(1<<i), i));
		if(cnt==n-1)
			cur=min(cur, store2[start+1][nxt]);
		ans=max(ans, cur);
	}	
	return ans;
}


int32_t main()
{
	IOS;
	memset(cache, -1, sizeof(cache));
	cin>>n>>m;
	for(int i=1;i<=n;i++)
		for(int j=1;j<=m;j++)
			cin>>a[i][j];
	if(n==1)
	{
		int ans=1e9;
		for(int i=1;i<=m-1;i++)
			ans=min(ans, abs(a[1][i]-a[1][i+1]));
		cout<<ans;
		return 0;
	}
	for(int i=1;i<=n;i++)
	{
		for(int j=1;j<=n;j++)
		{
			store[i][j]=1e9;
			if(i==j)
				continue;
			for(int k=1;k<=m;k++)
				store[i][j]=min(store[i][j], abs(a[i][k]-a[j][k]));
		}
	}
	for(int i=1;i<=n;i++)
	{
		for(int j=1;j<=n;j++)
		{
			store2[i][j]=1e9;
			if(i==j)
				continue;
			for(int k=1;k<=m-1;k++)
				store2[i][j]=min(store2[i][j], abs(a[i][k]-a[j][k+1]));
		}
	}
	int ans=0;
	for(int i=0;i<n;i++)
		ans=max(ans, dp(i, (1<<i), i));
	cout<<ans;
	return 0;
}