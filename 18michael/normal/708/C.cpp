#include<cstdio>
int n,edge_t=0;
int la[400002]={},siz[400002],mxsiz[400002],dp1[400002],num[400002]={},ans[400002];
int dp[400002][2]={};
struct aaa
{
	int to,nx;
}edge[800002];
inline int max(int a,int b)
{
	return a>b? a:b;
}
inline void add_edge(int x,int y)
{
	edge[++edge_t]=(aaa){y,la[x]},la[x]=edge_t;
	edge[++edge_t]=(aaa){x,la[y]},la[y]=edge_t;
}
inline void dfs(int u,int f)
{
	siz[u]=1;
	for(int i=la[u],v;i;i=edge[i].nx)
		if((v=edge[i].to)!=f)
		{
			dfs(v,u),siz[u]+=siz[v];
			if(siz[v]>siz[mxsiz[u]])mxsiz[u]=v;
			if(siz[v]<=n/2)
			{
				if(siz[v]>dp[u][0])dp[u][1]=dp[u][0],dp[u][0]=siz[v],num[u]=v;
				else if(siz[v]>dp[u][1])dp[u][1]=siz[v];
			}
			else
			{
				if(dp[v][0]>dp[u][0])
				{
					dp[u][1]=dp[u][0],dp[u][0]=dp[v][0],num[u]=v;
					if(dp[v][1]>dp[u][1])dp[u][1]=dp[v][1];
				}
				else if(dp[v][0]>dp[u][1])dp[u][1]=dp[v][0];
			}
		}
}
inline void dfs1(int u,int f)
{
	ans[u]=1;
	if(siz[mxsiz[u]]>n/2 && siz[mxsiz[u]]-dp[mxsiz[u]][0]>n/2)ans[u]=0;
	if(n-siz[u]>n/2 && n-siz[u]-dp1[u]>n/2)ans[u]=0;
	for(int i=la[u],v;i;i=edge[i].nx)
		if((v=edge[i].to)!=f)
		{
			if(n-siz[u]<=n/2)dp1[v]=n-siz[u];
			else dp1[v]=dp1[u];
			if(num[u]==v)dp1[v]=max(dp1[v],dp[u][1]);
			else dp1[v]=max(dp1[v],dp[u][0]);
			dfs1(v,u);
		}
}
int main()
{
	scanf("%d",&n);
	for(int i=1,x,y;i<n;++i)scanf("%d%d",&x,&y),add_edge(x,y);
	dfs(1,0),dfs1(1,0);
	for(int i=1;i<=n;++i)printf("%d%c",ans[i],i==n? '\n':' ');
	return 0;
}