#include<bits/stdc++.h>
using namespace std;
int dp[55][55][55][55];

char s[55][55];

int main()
{
	int n;
	scanf("%d%d",&n);
	for(int i=1;i<=n;i++)
		scanf("%s",s[i]+1);
	for(int i=1;i<=n;i++)
	for(int j=1;j<=n;j++)
	if(s[i][j]=='#')
		dp[i][i][j][j]=1;
	else
		dp[i][i][j][j]=0;
	for(int rx=1;rx<=n;rx++)
	for(int ry=1;ry<=n;ry++)
	for(int lx=rx;lx>=1;lx--)
	for(int ly=ry;ly>=1;ly--)
	if(rx>lx||ry>ly)
	{
		dp[lx][rx][ly][ry]=max(rx-lx+1,ry-ly+1);
		for(int k=lx;k<rx;k++)
			dp[lx][rx][ly][ry]=min(dp[lx][rx][ly][ry],dp[lx][k][ly][ry]+dp[k+1][rx][ly][ry]);
		for(int k=ly;k<ry;k++)
			dp[lx][rx][ly][ry]=min(dp[lx][rx][ly][ry],dp[lx][rx][ly][k]+dp[lx][rx][k+1][ry]);
	}
	printf("%d\n",dp[1][n][1][n]);
	return 0;
}