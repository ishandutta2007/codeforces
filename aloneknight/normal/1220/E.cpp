#include<bits/stdc++.h>
using namespace std;
#define ll long long
const int N=200005;
int n,m,S,f[N],sz[N],vis[N],dep[N],fa[N][20],tg[N],ff[N];ll w[N],g1[N],g2[N];
vector<int>g[N],e[N];
int fnd(int x){return f[x]==x?x:f[x]=fnd(f[x]);}
inline int lca(int u,int v)
{
	if(dep[u]<dep[v])swap(u,v);int sub=dep[u]-dep[v];
	for(int i=18;i>=0;i--)if(sub>>i&1)u=fa[u][i];if(u==v)return u;
	for(int i=18;i>=0;i--)if(fa[u][i]!=fa[v][i])u=fa[u][i],v=fa[v][i];return fa[u][0];
}
void dfs1(int x,int p)
{
	vis[x]=1;fa[x][0]=p;dep[x]=dep[p]+1;
	for(int i=0;i<g[x].size();i++){int y=g[x][i];if(!vis[y])dfs1(y,x);}
}
void dfs2(int x,int p)
{
	vis[x]=0;
	for(int i=0;i<g[x].size();i++)
	{
		int y=g[x][i];
		if(!vis[y]&&y!=p){int t=lca(x,y);tg[x]++;tg[y]++;tg[t]--;tg[t]--;}
	}
	for(int i=0;i<g[x].size();i++){int y=g[x][i];if(vis[y])dfs2(y,x);}
}
void dfs3(int x,int p)
{
	vis[x]=1;
	for(int i=0;i<g[x].size();i++){int y=g[x][i];if(!vis[y])dfs3(y,x),tg[x]+=tg[y];}
	if(tg[x])
	{
		int f1=fnd(x),f2=fnd(p);
		if(f1!=f2){f[f1]=f2;w[f2]+=w[f1];sz[f2]+=sz[f1];}
	}
}
void dp(int x)
{
	g1[x]=w[x];g2[x]=w[x];ff[x]=sz[x]>1;
	for(int i=0;i<e[x].size();i++){int y=e[x][i];dp(y);if(ff[y])g1[x]+=g1[y],ff[x]=1;}
	for(int i=0;i<e[x].size();i++){int y=e[x][i];g2[x]=max(g2[x],g2[y]+g1[x]-(ff[y]?g1[y]:0));}
}
int main()
{
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n;i++)scanf("%lld",&w[i]),sz[i]=1,f[i]=i;
	for(int i=1,u,v;i<=m;i++)scanf("%d%d",&u,&v),g[u].push_back(v),g[v].push_back(u);
	scanf("%d",&S);dfs1(S,0);
	for(int i=1;i<=18;i++)for(int j=1;j<=n;j++)fa[j][i]=fa[fa[j][i-1]][i-1];
	dfs2(S,0);dfs3(S,0);
	for(int i=1;i<=n;i++)if(i!=S&&f[i]==i){int t=fnd(fa[i][0]);e[t].push_back(i);}
	dp(S);printf("%lld\n",max(g1[S],g2[S]));
	return 0;
}