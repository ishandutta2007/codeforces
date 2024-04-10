#include <iostream>
#include <string.h>
using namespace std;
int cum[55][55],dp[55][55][55][55];
char g[55][55];
int solve(int x1,int y1,int x2,int y2)
{
	if (cum[x2+1][y2+1]-cum[x1][y2+1]-cum[x2+1][y1]+cum[x1][y1]==0)
	return 0;
	if (dp[x1][y1][x2][y2]!=-1)
	return dp[x1][y1][x2][y2];
	int ans=max(x2-x1+1,y2-y1+1);
	for (int i=x1+1;i<=x2;i++)
	ans=min(ans,solve(x1,y1,i-1,y2)+solve(i,y1,x2,y2));
	for (int i=y1+1;i<=y2;i++)
	ans=min(ans,solve(x1,y1,x2,i-1)+solve(x1,i,x2,y2));
	return dp[x1][y1][x2][y2]=ans;
}
int main()
{
	int n;
	scanf("%d",&n);
	getchar();
	for (int i=0;i<n;i++)
	{
		gets(g[i]);
		for (int j=0;j<n;j++)
		cum[i+1][j+1]=cum[i+1][j]+cum[i][j+1]-cum[i][j]+(g[i][j]=='#');
	}
	memset(dp,-1,sizeof(dp));
	printf("%d",solve(0,0,n-1,n-1));
}