#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
int dp[35][35][55],n,m,p,T;
int main()
{
	scanf("%d",&T);
	memset(dp,0x3f,sizeof(dp));
	n=m=30;
	p=50;
	for(int i=1;i<=n;i++)
		for(int j=1;j<=m;j++)
		{
			dp[i][j][0]=0;
			if(i*j<=50)
				dp[i][j][i*j]=0;
		}
	for(int i=1;i<=n;i++)
		for(int j=1;j<=m;j++)
			for(int k=1;k<=p;k++)
			{
				for(int l=1;l*2<=i;l++)
					for(int m=0;m<=k;m++)
						dp[i][j][k]=min(dp[i][j][k],dp[l][j][m]+dp[i-l][j][k-m]+j*j);
				for(int l=1;l*2<=j;l++)
					for(int m=0;m<=k;m++)
						dp[i][j][k]=min(dp[i][j][k],dp[i][l][m]+dp[i][j-l][k-m]+i*i);
			}
	while(T--)
	{
		scanf("%d%d%d",&n,&m,&p);
		printf("%d\n",dp[n][m][p]);
	}
}//2333333UKE