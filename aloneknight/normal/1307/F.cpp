#include<bits/stdc++.h>
using namespace std;
const int N=400005,inf=1e9+7;
int n,k,r,q,dep[N],fa[20][N],f[N],d[N]; 
vector<int>g[N];
int fnd(int x){return f[x]==x?x:f[x]=fnd(f[x]);}
void dfs(int x,int p)
{
	fa[0][x]=p;for(int i=1;i<19;i++)fa[i][x]=fa[i-1][fa[i-1][x]];
	for(int y:g[x])if(y!=p)dep[y]=dep[x]+1,dfs(y,x);
}
inline int anc(int x,int d){for(int i=18;~i;i--)if(d>>i&1)x=fa[i][x];return x;}
inline int lca(int u,int v)
{
	if(dep[u]<dep[v])swap(u,v);u=anc(u,dep[u]-dep[v]);if(u==v)return u;
	for(int i=18;~i;i--)if(fa[i][u]!=fa[i][v])u=fa[i][u],v=fa[i][v];return fa[0][u];
}
inline int go(int u,int v,int t,int k){return (k<=dep[u]-dep[t])?anc(u,k):anc(v,dep[v]-dep[t]-(k-(dep[u]-dep[t])));}
inline bool sol()
{
	int u,v,t;scanf("%d%d",&u,&v);t=lca(u,v);
	return (dep[u]+dep[v]-2*dep[t]<=2*k)?1:(fnd(go(u,v,t,k))==fnd(go(v,u,t,k)));
}
int main()
{
	scanf("%d%d%d",&n,&k,&r);int nn=n;
	for(int i=1,u,v;i<n;i++)
	{
		scanf("%d%d",&u,&v);nn++;
		g[u].push_back(nn);g[v].push_back(nn);
		g[nn].push_back(u);g[nn].push_back(v);
	}
	for(int i=1;i<=nn;i++)f[i]=i,d[i]=inf;
	queue<int>Q;
	for(int i=1,x;i<=r;i++)scanf("%d",&x),d[x]=0,Q.push(x);
	while(!Q.empty())
	{
		int x=Q.front();Q.pop();
		if(d[x]>=k)break;
		for(int y:g[x])
		{
			f[fnd(y)]=fnd(x);
			if(d[y]==inf){d[y]=d[x]+1;Q.push(y);}
		}
	}
	dfs(1,0);scanf("%d",&q);
	while(q--)puts(sol()?"YES":"NO");
	return 0;
}