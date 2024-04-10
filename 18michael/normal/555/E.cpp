#include<bits/stdc++.h>
#define Mx 17
using namespace std;
int n,m,q,dfn_t=0,num_t=0,st_t=0,edge_t=1,e_t=0;bool ok=0;
int rt[200002],dfn[200002],low[200002],num[200002],st[200002],la[200002]={},lae[200002]={},dep[200002];
bool ins[200002]={},vis[200002]={};
int fa[200002][18],cnt[200002][2]={};
struct aaa
{
	int to,nx;
}edge[400002],e[400002];
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
inline void Tarjan(int x,int e)
{
	dfn[x]=low[x]=(++dfn_t),st[++st_t]=x,ins[x]=1;
	for(int i=la[x],v;i;i=edge[i].nx)
		if((i>>1)!=e)
		{
			v=edge[i].to;
			if(!dfn[v])Tarjan(v,(i>>1)),low[x]=min(low[x],low[v]);
			else if(ins[v])low[x]=min(low[x],dfn[v]);
		}
	if(low[x]==dfn[x])
	{
		++num_t;
		while(st[st_t+1]!=x)num[st[st_t]]=num_t,ins[st[st_t]]=0,--st_t;
	}
}
inline void dfs(int x,int f,int d)
{
	vis[x]=1,fa[x][0]=f,dep[x]=d;
	for(int i=1;i<=Mx;++i)fa[x][i]=fa[fa[x][i-1]][i-1];
	for(int i=lae[x],v;i;i=e[i].nx)if((v=e[i].to)!=f)dfs(v,x,d+1);
}
inline int LCA(int x,int y)
{
	if(dep[x]<dep[y])swap(x,y);
	for(int i=Mx;~i;--i)if(dep[fa[x][i]]>=dep[y])x=fa[x][i];
	if(x==y)return x;
	for(int i=Mx;~i;--i)if(fa[x][i]!=fa[y][i])x=fa[x][i],y=fa[y][i];
	return fa[x][0];
}
inline void dfs1(int x,int f)
{
	vis[x]=1;
	for(int i=lae[x],v;i;i=e[i].nx)if((v=e[i].to)!=f)dfs1(v,x),cnt[x][0]+=cnt[v][0],cnt[x][1]+=cnt[v][1];
	ok|=(cnt[x][0] && cnt[x][1]);
}
int main()
{
	scanf("%d%d%d",&n,&m,&q);
	for(int i=1;i<=n;++i)rt[i]=i;
	for(int i=1,x,y;i<=m;++i)
	{
		scanf("%d%d",&x,&y),add_edge(x,y),getroot(x),getroot(y);
		if(rt[x]!=rt[y])rt[rt[x]]=rt[y];
	}
	Tarjan(1,0);
	for(int i=1;i<=n;++i)
	{
		getroot(i);
		for(int j=la[i],v;j;j=edge[j].nx)if((v=edge[j].to)>i && num[i]!=num[v])add_e(num[i],num[v]);
	}
	for(int i=1;i<=n;++i)if(!vis[i])dfs(i,0,1);
	for(int i=1,x,y,z;i<=q;++i)
	{
		scanf("%d%d",&x,&y);
		if(rt[x]!=rt[y])return 0&puts("No");
		if((x=num[x])==(y=num[y]))continue;
		z=LCA(x,y),++cnt[x][0],--cnt[z][0],++cnt[y][1],--cnt[z][1];
	}
	for(int i=1;i<=n;++i)vis[i]=0;
	for(int i=1;i<=n;++i)if(!vis[i])dfs1(i,0);
	return 0&puts(ok? "No":"Yes");
}