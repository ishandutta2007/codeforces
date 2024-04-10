#include<bits/stdc++.h>
using namespace std;
const int M=1000000007;
int n,a,i,j,k,l,m,p;
long long dp[2][2][2][2],mi[500005];
int main()
{
#ifndef ONLINE_JUDGE
	freopen("input.txt","r",stdin);
	freopen("output.txt","w",stdout);
#endif
	scanf("%d %d",&n,&m);
	mi[0]=1;
	for(i=1;i<=n;++i)
		mi[i]=mi[i-1]*2%M;
	dp[0][0][0][0]=1;
	for(i=1;i<=n;++i)
	{
		scanf("%d",&a);
		int t=i&1;
		memset(dp[t],0,sizeof(dp[t]));
		if(a==0||a==-1)
		{
			for(j=0;j<=1;++j)
				for(k=0;k<=1;++k)
					for(p=0;p<=1;++p)
					{
						if(k)
						{
							dp[t][j][k][p]=(dp[t][j][k][p]+dp[t^1][j][k][p]*(i-1>0?mi[i-2]:0))%M;
							dp[t][j|1][k][p^1]=(dp[t][j|1][k][p^1]+dp[t^1][j][k][p]*(i-1>0?mi[i-2]:0))%M;
						}
						else
							dp[t][j|1][k][p^1]=(dp[t][j|1][k][p^1]+dp[t^1][j][k][p]*mi[i-1])%M;
					}
		}
		if(a==1||a==-1)
		{
			for(j=0;j<=1;++j)
				for(k=0;k<=1;++k)
					for(p=0;p<=1;++p)
					{
						if(k)
						{
							dp[t][k][j][p]=(dp[t][k][j][p]+dp[t^1][k][j][p]*(i-1>0?mi[i-2]:0))%M;
							dp[t][k][j|1][p^1]=(dp[t][k][j|1][p^1]+dp[t^1][k][j][p]*(i-1>0?mi[i-2]:0))%M;
						}
						else
							dp[t][k][j|1][p^1]=(dp[t][k][j|1][p^1]+dp[t^1][k][j][p]*mi[i-1])%M;
					}
		}
	}
	cout<<((dp[n&1][0][0][m]+dp[n&1][0][1][m]+dp[n&1][1][1][m]+dp[n&1][1][0][m])%M+M)%M;
}