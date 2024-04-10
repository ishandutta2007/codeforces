#include<cstdio>
int n,m,edge_t=1,dfn_t=0,rt_t=0,st_t=0,mx=1,e_t=1;
int la[400002]={},lae[400002]={},dfn[400002]={},low[400002],siz[400002],st[400002],tree[800002],rt[400002],id[800002];
struct aaa
{
	int to,nx;
}edge[800002],e[800002];
inline int min(int a,int b)
{
	return a<b? a:b;
}
inline void swap(int &x,int &y)
{
	int z=x;x=y,y=z;
}
inline void add_edge(int x,int y)
{
	edge[++edge_t]=(aaa){y,la[x]},la[x]=edge_t;
	edge[++edge_t]=(aaa){x,la[y]},la[y]=edge_t;
}
inline void add_e(int x,int y,int z)
{
	e[++e_t]=(aaa){y,lae[x]},lae[x]=e_t,id[e_t]=z;
	e[++e_t]=(aaa){x,lae[y]},lae[y]=e_t,id[e_t]=(z^1);
}
inline void Tarjan(int x,int y,int fa)
{
	dfn[x]=low[x]=(++dfn_t),st[++st_t]=x;
	for(int i=la[x],v;i;i=edge[i].nx)
	{
		v=edge[i].to;
		if(!dfn[v])tree[i]=2,tree[i^1]=1,Tarjan(v,y,x),low[x]=min(low[x],low[v]);
		else if(v!=fa)low[x]=min(low[x],dfn[v]);
	}
	if(low[x]==dfn[x])
	{
		++rt_t;
		do rt[st[st_t]]=rt_t,++siz[rt_t],--st_t;while(st[st_t+1]!=x);
	}
}
inline void dfs(int x,int fa)
{
	for(int i=lae[x],v;i;i=e[i].nx)
		if((v=e[i].to)!=fa)
			dfs(v,x),tree[id[i]]=4,tree[id[i^1]]=3;
}
int main()
{
	scanf("%d%d",&n,&m);
	for(int i=1,x,y;i<=m;++i)scanf("%d%d",&x,&y),add_edge(x,y);
	for(int i=1;i<=n;++i)if(!dfn[i])Tarjan(i,i,0);
	for(int i=2;i<=rt_t;++i)if(siz[i]>siz[mx])mx=i;
	for(int i=2,x,y;i<=edge_t;i+=2)
		if(rt[edge[i].to]!=rt[edge[i^1].to])
			add_e(rt[edge[i].to],rt[edge[i^1].to],i);
	dfs(mx,0),printf("%d\n",siz[mx]);
	for(int i=2,x,y;i<=edge_t;i+=2)
	{
		x=edge[i].to,y=edge[i^1].to;
		if(tree[i]==4 || tree[i]==2 || (!tree[i] && dfn[edge[i].to]<dfn[edge[i^1].to]))swap(x,y);
		printf("%d %d\n",x,y);
	}
	return 0;
}