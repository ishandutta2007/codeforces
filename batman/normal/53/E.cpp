#include <bits/stdc++.h>
using namespace std;
#define ll int
#define ld double
#define N ((ll)12)
#define INF ((ll)1e18)

ll n,m,k,dp[1<<N][1<<N];
bool a[N][N];


int main()
{
	ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	cin>>n>>m>>k;
	for(int i=0;i<m;i++)
	{
		ll v,u;
		cin>>v>>u;v--;u--;
		dp[(1<<v)+(1<<u)][(1<<v)+(1<<u)]=a[v][u]=a[u][v]=1;
	}
	for(int i=0;i<(1<<n);i++)
		for(int j=0;j<(1<<n);j++)
			if(dp[i][j])
			{
				if(__builtin_popcount(i)>2)dp[i][j]/=__builtin_popcount(j);
				for(int p=0;p<n;p++)
					if(!((1<<p)&i))
						for(int q=0;q<n;q++)
							if(((1<<q)&i) && a[p][q])
							{
								if(((1<<q)&j))dp[(i+(1<<p))][(j-(1<<q)+(1<<p))]+=dp[i][j];
								else dp[(i+(1<<p))][(j+(1<<p))]+=dp[i][j];
							}
			}
	ll ans=0;
	for(int i=0;i<(1<<n);i++)
		if(__builtin_popcount(i)==k)
			ans+=dp[((1<<n)-1)][i];
	cout<<ans;
	return 0;
}