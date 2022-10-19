#include<bits/stdc++.h>
using namespace std;
int n,m,edge_t=0,dfn_t=0;
int X[500002],Y[500002],Z[500002],rt[300002],la[300002],dfn[300002],siz[300002],son[300002],pre[300002],top[300002],dep[300002],fa[300002];
struct aaa
{
	int to,nx,val;
}edge[600002];
inline int lowbit(int x)
{
	return x&(-x);
}
struct BIT
{
	int sum[300002];
	inline void modify(int x,int d)
	{
		for(;x<=n;x+=lowbit(x))sum[x]+=d;
	}
	inline int query(int x)
	{
		int res=0;
		for(;x;x-=lowbit(x))res+=sum[x];
		return res;
	}
}S;
inline void add_edge(int x,int y,int z)
{
	edge[++edge_t]=(aaa){y,la[x],z},la[x]=edge_t;
	edge[++edge_t]=(aaa){x,la[y],z},la[y]=edge_t;
}
inline void getroot(int x)
{
	if(x==rt[x])return ;
	getroot(rt[x]),rt[x]=rt[rt[x]];
}
inline void dfs(int x,int f,int d)
{
	siz[x]=1,fa[x]=f,dep[x]=d;
	for(int i=la[x],v;i;i=edge[i].nx)
		if((v=edge[i].to)!=f)
		{
			pre[v]=(pre[x]^edge[i].val),dfs(v,x,d+1),siz[x]+=siz[v];
			if(siz[v]>siz[son[x]])son[x]=v;
		}
}
inline void dfs1(int x,int f,int t)
{
	dfn[x]=(++dfn_t),top[x]=t;
	if(son[x])dfs1(son[x],x,t);
	for(int i=la[x],v;i;i=edge[i].nx)if((v=edge[i].to)!=f && v!=son[x])dfs1(v,x,v);
}
inline int LCA(int x,int y)
{
	for(;top[x]^top[y];x=fa[top[x]])if(dep[top[x]]<dep[top[y]])swap(x,y);
	return dep[x]<dep[y]? x:y;
}
int main()
{
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n;++i)rt[i]=i;
	for(int i=1;i<=m;++i)
	{
		scanf("%d%d%d",&X[i],&Y[i],&Z[i]),getroot(X[i]),getroot(Y[i]);
		if(rt[X[i]]^rt[Y[i]])rt[rt[X[i]]]=rt[Y[i]],add_edge(X[i],Y[i],Z[i]),Z[i]=-1;
	}
	for(int i=1;i<=n;++i)if(!siz[i])dfs(i,0,1);
	for(int i=1;i<=n;++i)if(!dfn[i])dfs1(i,0,i);
	for(int i=1,x;i<=m;++i)
	{
		if(Z[i]<0)puts("YES");
		else if(!(pre[X[i]]^pre[Y[i]]^Z[i]))puts("NO");
		else
		{
			x=LCA(X[i],Y[i]);
			if(S.query(dfn[X[i]])==S.query(dfn[x]) && S.query(dfn[Y[i]])==S.query(dfn[x]))
			{
				puts("YES");
				for(;X[i]^x;X[i]=fa[X[i]])S.modify(dfn[X[i]],1),S.modify(dfn[X[i]]+siz[X[i]],-1);
				for(;Y[i]^x;Y[i]=fa[Y[i]])S.modify(dfn[Y[i]],1),S.modify(dfn[Y[i]]+siz[Y[i]],-1);
			}
			else puts("NO");
		}
	}
	return 0;
}