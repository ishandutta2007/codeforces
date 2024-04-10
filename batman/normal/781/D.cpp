#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define N ((ll)505)
#define K ((ll)61)

ll n,m,ans[2][N];
bitset <N> dp[2][N][K];

int main()
{
	ios_base::sync_with_stdio(0);cin.tie(0);
	cin>>n>>m;
	for(int i=0;i<m;i++)
	{
		ll v,u,c;
		cin>>v>>u>>c;v--;u--;
		dp[c][v][0][u]=1;
	}
	for(int t=1;t<K;t++)
		for(int i=0;i<n;i++)
			for(int j=0;j<n;j++)
			{
				if(dp[0][i][t-1][j])dp[0][i][t]|=dp[1][j][t-1];
				if(dp[1][i][t-1][j])dp[1][i][t]|=dp[0][j][t-1];
			}
	for(int i=0;i<n;i++)
		if(dp[0][i][K-1].count())
			return cout<<-1,0;
	for(int q=0;q<N;q++)
	{
		for(int i=0;i<n;i++)
		{
			for(int t=K-1;t>=0;t--)
				if(dp[0][i][t].count())
				{
					for(int j=0;j<n;j++)
						if(dp[0][i][t][j])
							ans[0][i]=max(ans[0][i],(1LL<<t)+ans[1][j]);
					break;
				}
			for(int t=K-1;t>=0;t--)
				if(dp[1][i][t].count())
				{
					for(int j=0;j<n;j++)
						if(dp[1][i][t][j])
							ans[1][i]=max(ans[1][i],(1LL<<t)+ans[0][j]);
					break;
				}
		}
	}
	ll res=0;
	for(int i=0;i<n;i++)
		res=max(res,ans[0][i]);
	if(res>(ll)1e18)return cout<<-1,0;
	cout<<res;
	return 0;
}