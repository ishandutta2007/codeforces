#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define N (70)
#define INF ((ll)1e9)

ll n,m,r,d[N][N][N],dp[N][N][N];

int main()
{
	ios_base::sync_with_stdio(0);
    cin>>n>>m>>r;
    for(int i=0;i<N;i++)for(int j=0;j<N;j++)for(int k=0;k<N;k++)dp[i][j][k]=INF;
    for(int i=0;i<m;i++)
    {
    	for(int j=0;j<n;j++)
    		for(int k=0;k<n;k++)
    			cin>>d[j][k][i];
    	for(int j=0;j<n;j++)
			for(int k=0;k<n;k++)
				for(int q=0;q<n;q++)
					d[k][q][i]=min(d[k][q][i],d[k][j][i]+d[j][q][i]);		
	}
	for(int i=0;i<n;i++)
		for(int j=0;j<n;j++)
			for(int q=0;q<m;q++)
				dp[i][j][0]=min(dp[i][j][0],d[i][j][q]);
	for(int k=1;k<N;k++)
		for(int i=0;i<n;i++)
			for(int j=0;j<n;j++)
				for(int q=0;q<n;q++)
					dp[i][j][k]=min(dp[i][j][k],dp[i][q][k-1]+dp[q][j][0]);
	while(r--)
	{
		ll v,u,k;
		cin>>v>>u>>k;
		if(k>=N)k=N-1;
		cout<<dp[v-1][u-1][k]<<"\n";
	}
    return 0;
}