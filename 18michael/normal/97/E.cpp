#include<bits/stdc++.h>
#define Mx 17
using namespace std;
int n,m,q,n1,edge_t=0,dfn_t=0,st_t,col_t=0,e_t=0;bool ok;
int la[100002]={},rt[100002],dis[100002],dfn[100002],low[100002],st[100002],col[100002],lae[200002]={},dep[200002];
bool ins[100002]={};
int fa[200002][18];
bool val[200002][18]={};
struct aaa
{
	int to,nx;
}edge[200002],e[400002];
inline void add_edge(int x,int y)
{
	edge[++edge_t]=(aaa){y,la[x]},la[x]=edge_t;
	edge[++edge_t]=(aaa){x,la[y]},la[y]=edge_t;
}
inline void add_e(int x,int y)
{
	e[++e_t]=(aaa){y,lae[x]},lae[x]=e_t;
	e[++e_t]=(aaa){x,lae[y]},lae[y]=e_t;
}
inline void getroot(int x)
{
	if(rt[x]==x)return ;
	getroot(rt[x]),rt[x]=rt[rt[x]];
}
inline void dfs(int x,int d)
{
	dis[x]=d;
	for(int i=la[x],v;i;i=edge[i].nx)if(!(~dis[v=edge[i].to]))dfs(v,d^1);
}
inline bool dfs1(int x)
{
	col[x]=0;
	for(int i=la[x],v;i;i=edge[i].nx)if(col[v=edge[i].to]==col_t && dis[x]==dis[v])return 1;
	for(int i=la[x],v;i;i=edge[i].nx)if(col[v=edge[i].to]==col_t && dfs1(v))return 1;
	return 0;
}
inline void Tarjan(int x)
{
	dfn[x]=low[x]=(++dfn_t),ins[st[++st_t]=x]=1;
	for(int i=la[x],v;i;i=edge[i].nx)
	{
		v=edge[i].to;
		if(!dfn[v])
		{
			Tarjan(v),low[x]=min(low[x],low[v]);
			if(low[v]==dfn[x])
			{
				col[x]=(++col_t),add_e(++n1,x);
				do col[st[st_t]]=col_t,add_e(n1,st[st_t]),ins[st[st_t]]=0,--st_t;while(st[st_t+1]!=v);
				val[n1][0]=dfs1(x);
			}
		}
		else if(ins[v])low[x]=min(low[x],dfn[v]);
	}
}
inline void dfs2(int x,int f,int d)
{
	fa[x][0]=f,dep[x]=d;
	for(int i=1;i<=Mx;++i)fa[x][i]=fa[fa[x][i-1]][i-1],val[x][i]=(val[x][i-1]|val[fa[x][i-1]][i-1]);
	for(int i=lae[x],v;i;i=e[i].nx)if((v=e[i].to)!=f)dfs2(v,x,d+1);
}
inline int LCA(int x,int y)
{
	if(dep[x]<dep[y])swap(x,y);
	for(int i=Mx;~i;--i)if(dep[fa[x][i]]>=dep[y])x=fa[x][i];
	if(x==y)return x;
	for(int i=Mx;~i;--i)if(fa[x][i]!=fa[y][i])x=fa[x][i],y=fa[y][i];
	return fa[x][0];
}
int main()
{
	scanf("%d%d",&n,&m),n1=n;
	for(int i=1;i<=n;++i)rt[i]=i,dis[i]=-1;
	for(int i=1,x,y;i<=m;++i)
	{
		scanf("%d%d",&x,&y),add_edge(x,y),getroot(x),getroot(y);
		if(rt[x]!=rt[y])rt[rt[x]]=rt[y];
	}
	for(int i=1;i<=n;++i)
	{
		getroot(i);
		if(!(~dis[i]))dfs(i,st_t=0),Tarjan(i),dfs2(i,0,1);
	}
	scanf("%d",&q);
	for(int x,y,z;q--;)
	{
		scanf("%d%d",&x,&y);
		if(rt[x]!=rt[y])
		{
			puts("No");
			continue;
		}
		if(dis[x]^dis[y])
		{
			puts("Yes");
			continue;
		}
		z=LCA(x,y),ok=val[z][0];
		for(int i=Mx;~i;--i)if(dep[fa[x][i]]>=dep[z])ok|=val[x][i],x=fa[x][i];
		for(int i=Mx;~i;--i)if(dep[fa[y][i]]>=dep[z])ok|=val[y][i],y=fa[y][i];
		puts(ok? "Yes":"No");
	}
	return 0;
}