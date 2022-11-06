#include<bits/stdc++.h>
using namespace std;
#define pii pair<int,int>
#define X first
#define Y second
#define mp make_pair
#define pb push_back
const int N=100005;
int n,m,q,cc,tt,tp,dep[N],fa[N][17],f[N],w[N],val[N],odd[N],vis[N],col[N],dfn[N],low[N];
vector<pii>G[N];
struct E{int u,v,i;};
vector<E>e;E stk[N];
int fnd(int x){if(f[x]==x)return x;int ff=fnd(f[x]);w[x]^=w[f[x]];return f[x]=ff;}
bool uni(int u,int v)
{
	int x=fnd(u),y=fnd(v);
	if(x==y)return w[u]^w[v];
	else{w[y]=w[u]^w[v]^1;f[y]=x;return 1;}
}
void tarjan(int x,int p)
{
	dfn[x]=low[x]=++tt;col[x]=cc;
	for(int i=0;i<G[x].size();i++)
	{
		int y=G[x][i].Y,t=G[x][i].X;if(t==p)continue;
		if(!dfn[y])
		{
			stk[++tp]=(E){x,y,t};tarjan(y,t);
			low[x]=min(low[x],low[y]);
			if(low[y]>=dfn[x])
			{
				e.clear();
				while(true)
				{
					e.push_back(stk[tp--]);
					if(e.back().i==t)break;
				}
				for(auto &t:e){f[t.u]=t.u;f[t.v]=t.v;w[t.u]=w[t.v]=0;}
				bool ff=1;
				for(auto &t:e)if(!uni(t.u,t.v)){ff=0;break;}
				if(!ff)for(auto &t:e)odd[t.i]=1;
			}
		}
		else if(dfn[y]<dfn[x]){stk[++tp]=(E){x,y,t};low[x]=min(low[x],dfn[y]);}
	}
}
void dfs(int x,int p)
{
	vis[x]=1;dep[x]=dep[p]+1;fa[x][0]=p;
	for(int i=1;i<17;i++)fa[x][i]=fa[fa[x][i-1]][i-1];
	for(int i=0;i<G[x].size();i++)
	{
		int y=G[x][i].Y,t=G[x][i].X;if(vis[y])continue;
		val[y]=val[x]+odd[t];dfs(y,x);
	}
}
inline int lca(int u,int v)
{
	if(dep[u]<dep[v])swap(u,v);int d=dep[u]-dep[v];
	for(int i=16;~i;i--)if(d>>i&1)u=fa[u][i];if(u==v)return u;
	for(int i=16;~i;i--)if(fa[u][i]!=fa[v][i])u=fa[u][i],v=fa[v][i];
	return fa[u][0];
}
inline int gtd(int u,int v){int t=lca(u,v);return dep[u]+dep[v]-2*dep[t];}
inline int gtw(int u,int v){int t=lca(u,v);return val[u]+val[v]-2*val[t];}
int main()
{
	scanf("%d%d",&n,&m);
	for(int i=1,u,v;i<=m;i++){scanf("%d%d",&u,&v);G[u].pb(mp(i,v));G[v].pb(mp(i,u));}
	for(int i=1;i<=n;i++)if(!dfn[i]){cc++;tarjan(i,0);}
	for(int i=1;i<=n;i++)if(!vis[i])dfs(i,0);
	scanf("%d",&q);
	while(q--)
	{
		int u,v;scanf("%d%d",&u,&v);
		if(col[u]!=col[v]||(!gtw(u,v)&&!(gtd(u,v)&1)))puts("No");else puts("Yes");
	}
	return 0;
}