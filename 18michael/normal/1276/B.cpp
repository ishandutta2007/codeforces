#include<cstdio>
int n,m,a,b,edge_t,Test_num,cnta,cntb;
int vis[200002],la[200002];
struct aaa
{
	int to,nx;
}edge[1000002];
inline void add_edge(int x,int y)
{
	edge[++edge_t]=(aaa){y,la[x]},la[x]=edge_t;
	edge[++edge_t]=(aaa){x,la[y]},la[y]=edge_t;
}
inline void dfs(int x,int y)
{
	vis[x]|=y;
	for(int i=la[x],v;i;i=edge[i].nx)
		if(!(vis[v=edge[i].to]&y) && v!=a && v!=b)
			dfs(v,y);
}
int main()
{
	scanf("%d",&Test_num);
	while(Test_num--)
	{
		scanf("%d%d%d%d",&n,&m,&a,&b),edge_t=cnta=cntb=0;
		for(int i=1;i<=n;++i)la[i]=vis[i]=0;
		for(int i=1,u,v;i<=m;++i)scanf("%d%d",&u,&v),add_edge(u,v);
		dfs(a,1),dfs(b,2);
		for(int i=1;i<=n;++i)cnta+=(vis[i]==1),cntb+=(vis[i]==2);
		printf("%lld\n",1LL*(cnta-1)*(cntb-1));
	}
	return 0;
}