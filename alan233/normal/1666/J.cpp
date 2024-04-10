#include<bits/stdc++.h>
using namespace std;
const int N=205;
int n,c[N][N],g[N][N][N],fa[N];
long long p[N][N],d[N][N][N],dp[N][N][N];
long long dfs(int l,int r,int h)
{
	if(l>r)
		return 0;
	if(dp[l][r][h]!=-1)
		return dp[l][r][h];
	if(l==r)
	{
		g[l][r][h]=l;
		dp[l][r][h]=p[l][n]*h;
		return dp[l][r][h];
	}
	dp[l][r][h]=1e18;
	for(int i=l;i<=r;i++)
	{
		long long w=dfs(l,i-1,h+1)+dfs(i+1,r,h+1)-2*d[l][i][r]*h+p[i][n]*h;
		if(w<dp[l][r][h])
		{
			dp[l][r][h]=w;
			g[l][r][h]=i;
		}
	}
	return dp[l][r][h];
}
void path(int l,int r,int h,int f)
{
	if(l>r)
		return;
	int i=g[l][r][h];
	fa[i]=f;
	path(l,i-1,h+1,i);
	path(i+1,r,h+1,i);
}
int main()
{
	scanf("%d",&n);
	for(int i=1;i<=n;i++)
		for(int j=1;j<=n;j++)
			scanf("%d",&c[i][j]),p[i][j]=p[i][j-1]+c[i][j];
	for(int l=1;l<=n;l++)
	{
		for(int i=l;i<=n;i++)
		{
			long long t=0;
			for(int j=l;j<i;j++)
				t+=c[j][i];
			for(int r=i;r<=n;r++)
			{
				if(r>i)
				{
					t+=c[r][i];
					t+=p[r][i-1]-p[r][l-1];
				}
				d[l][i][r]=t;
			}
		}
	}
	memset(dp,-1,sizeof(dp));
	dfs(1,n,0);
	path(1,n,0,0);
	for(int i=1;i<=n;i++)
		printf("%d ",fa[i]);
	return 0;
}