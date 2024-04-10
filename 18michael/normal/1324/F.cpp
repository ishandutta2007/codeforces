#include<cstdio>
int n,edge_t=0;
int a[200002],la[200002]={},dp[200002],ans[200002];
struct aaa
{
	int to,nx;
}edge[400002];
inline int max(int a,int b)
{
	return a>b? a:b;
}
inline int min(int a,int b)
{
	return a<b? a:b;
}
inline void add_edge(int x,int y)
{
	edge[++edge_t]=(aaa){y,la[x]},la[x]=edge_t;
	edge[++edge_t]=(aaa){x,la[y]},la[y]=edge_t;
}
inline void dfs(int x,int f)
{
	dp[x]=(a[x]? 1:-1);
	for(int i=la[x],v;i;i=edge[i].nx)
		if((v=edge[i].to)!=f)
			dfs(v,x),dp[x]+=max(dp[v],0);
}
inline void dfs1(int x,int f)
{
	ans[x]=max(ans[f]+min(dp[x],0),dp[x]);
	for(int i=la[x],v;i;i=edge[i].nx)
		if((v=edge[i].to)!=f)
			dfs1(v,x);
}
int main()
{
	scanf("%d",&n);
	for(int i=1;i<=n;++i)scanf("%d",&a[i]);
	for(int i=1,x,y;i<n;++i)scanf("%d%d",&x,&y),add_edge(x,y);
	dfs(1,0),ans[1]=dp[1];
	for(int i=la[1];i;i=edge[i].nx)dfs1(edge[i].to,1);
	for(int i=1;i<=n;++i)printf("%d%c",ans[i],i==n? '\n':' ');
	return 0;
}