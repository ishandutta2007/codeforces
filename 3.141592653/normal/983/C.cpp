#include<cstdio>
#include<cstring> 
int dp[2222][11][11][11][11],n,x[2222],y[2222];
inline int min(int x,int y)
{return(x<y)?x:y;}
inline int abs(int x)
{return(x>0)?x:-x;}
int dfs(int m=1,int h=1,int a=0,int b=0,int c=0)
{
	if(~dp[m][h][a][b][c])return dp[m][h][a][b][c];
	int ret=1e9;
	if(a)ret=min(ret,dfs(m,a,b,c,0)+abs(h-a));
	if(b)ret=min(ret,dfs(m,b,a,c,0)+abs(h-b));
	if(c)ret=min(ret,dfs(m,c,a,b,0)+abs(h-c));
	if(m>n)
	{
		if((!a)&&(!b)&&(!c))return 0;
		return dp[m][h][a][b][c]=ret;
	}if(a&&b&&c)
	{
		ret=min(ret,dfs(m+1,y[m],a,b,c)+abs(h-x[m])+abs(x[m]-y[m]));
		ret=min(ret,dfs(m+1,a,y[m],b,c)+abs(h-x[m])+abs(x[m]-a));
		ret=min(ret,dfs(m+1,b,y[m],a,c)+abs(h-x[m])+abs(x[m]-b));
		ret=min(ret,dfs(m+1,c,y[m],a,b)+abs(h-x[m])+abs(x[m]-c));
	}else
	{
		if(!a)ret=min(ret,dfs(m+1,x[m],y[m],b,c)+abs(h-x[m]));
		else if(!b)ret=min(ret,dfs(m+1,x[m],y[m],a,c)+abs(h-x[m]));
		else ret=min(ret,dfs(m+1,x[m],a,b,y[m])+abs(h-x[m]));
	}return dp[m][h][a][b][c]=ret;
}
int main()
{
	memset(dp,-1,sizeof(dp));
	register int i;
	scanf("%d",&n);
	for(i=1;i<=n;i++)scanf("%d%d",x+i,y+i);
	int ans=dfs();
	printf("%d\n",ans+n*2);
}