#include<bits/stdc++.h>
using namespace std;
bool dp[105][21005],z[105][21005];
int d[105],p[205];
int main()
{
	int t;
	cin>>t;
	while(t--)
	{
		int n,k,l;
		scanf("%d%d%d",&n,&k,&l);
		for(int i=1;i<=n;i++)scanf("%d",&d[i]);
		for(int i=0;i<=k;i++)p[i]=i;
		for(int i=k+1;i<2*k;i++)p[i]=2*k-i;
		for(int i=0;i<2*k;i++)dp[0][i]=1;
		for(int i=1;i<=n;i++)for(int j=20200;j>=0;j--)dp[i][j]=0;
		for(int i=1;i<=n;i++)
		{
			for(int j=i;j<=2*(i+1)*k-1;j++)
			{
				z[i][j]=(d[i]+p[j%(2*k)])<=l;
			}
			for(int j=i;j<=2*(i+1)*k-1;j++)
			{
				dp[i][j]=max(dp[i][j],dp[i-1][j-1]&&z[i][j]);
				int zz=z[i][j];
				for(int f=1;f<2*k;f++)
				{
					if(j+f>2*(i+1)*k-1)break;
					zz&=z[i][j+f];
					dp[i][j+f]=max(dp[i][j+f],dp[i][j]&&zz);
				}
			}
		}
		int ans=0;
		for(int j=n;j<=2*(n+1)*k-1;j++)ans|=dp[n][j];
		if(ans)puts("Yes");
		else puts("No");
	}
	return 0;
}