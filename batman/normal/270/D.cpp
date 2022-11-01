#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define N (5010)
#define INF ((ll)1e9)
#define MOD ((ll)1e9+7)

int n,m,a[N],cnt[N][N],dp[N][N];
double ex;

int main()
{
	cin>>n>>m;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i]>>ex;
		for(int j=a[i];j>=0;j--)cnt[i][j]++;
	}
	for(int i=2;i<=n;i++)for(int j=0;j<=m;j++)cnt[i][j]+=cnt[i-1][j];
	for(int i=1;i<=n;i++)
		for(int j=1;j<=m;j++)
		{
			if(j<a[i])
				dp[i][j]=dp[i-1][j];
			else
				dp[i][j]=min(dp[i-1][j]+1,min(dp[i-1][a[i]]-cnt[i-1][j+1]+cnt[i-1][a[i]+1],dp[i-1][a[i]-1]-cnt[i-1][j+1]+cnt[i-1][a[i]]));	
		}
	cout<<dp[n][m];
	
	
    return 0;
}