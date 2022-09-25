#include<cstdio>
using namespace std;
#define N 233
int n,d,m,dp[N][N],c[N][N];
int main()
{
	scanf("%d%d%d",&n,&d,&m);
	if(d==1&&n>2){printf("0\n");return 0;}
	if(n==2){printf("%d\n",4%m);return 0;}
	for(int i=0;i<=n;i++)c[i][0]=c[i][i]=1;
	for(int i=2;i<=n;i++)
	for(int j=1;j<i;j++)
	c[i][j]=(1ll*c[i-1][j]+c[i-1][j-1])%m;
	dp[0][0]=dp[1][1]=1;
	for(int i=2;i<=n;i++)
	for(int j=1;j<i;j++)
	for(int l=0;l<d&&j-l+1>0;l++)
	dp[i][j-l+1]=(dp[i][j-l+1]+1ll*dp[i-1][j]*c[j][l])%m;
	int as=0;
	for(int i=1;i<=n;i++)
	for(int j=0;j<=d;j++)
	for(int l=0;l<=d;l++)
	if(j+l<=d)
	as=(as+1ll*dp[i-1][j]*dp[n-i][l])%m;
	for(int i=1;i<n;i++)
	for(int j=0;j<d;j++)
	for(int l=0;l<d;l++)
	as=(as-1ll*dp[i-1][j]*dp[n-i-1][l]%m+m)%m;
	printf("%d\n",2ll*n*(n-1)*as%m);
}