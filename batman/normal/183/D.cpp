#include <bits/stdc++.h>
using namespace std;
#define N ((int)3300)

int n,m;
long double p[N][N],dp[N][N],ex[N],now[N],ans;
bool mark[N];

int main()
{
    scanf("%d%d",&n,&m);
    for(int i=1;i<=n;i++)
		for(int j=1;j<=m;j++)
		{
			int ex;
			dp[0][j]=1;
			scanf("%d",&ex);
			p[i][j]=(double)ex/1000;
			dp[i][j]=dp[i-1][j]*(1-p[i][j]);
		}
	for(int i=1;i<=m;i++)now[i]=(double)1-dp[n][i];
	for(int i=1;i<=n;i++)
	{
		int id=1;
		for(int j=1;j<=m;j++)if(now[j]>now[id])id=j;
		ans+=now[id];
		for(int j=1;j<=n;j++)ex[j]=ex[j-1]*(1-p[j][id])+dp[j-1][id]*p[j][id];
		for(int j=0;j<=n;j++)dp[j][id]=ex[j];
		now[id]-=dp[n][id];
	}
	cout<<fixed<<setprecision(15)<<ans<<endl;
	return 0;
}