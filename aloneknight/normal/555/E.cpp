#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define ui long long
#define ull unsigned long long
#define db double
#define pii pair<int,int>
#define pli pair<ll,int>
#define X first
#define Y second
#define mp make_pair
#define pb push_back
#define vi vector<int>
#define vii vector<vi>
#define lb lower_bound
#define rep(i,a,b) for(int i=(a);i<=(b);++i)
#define per(i,b,a) for(int i=(b);i>=(a);--i)
#define rep0(i,a,b) for(int i=(a);i<(b);++i)
#define fore(i,a) for(int i=0;i<a.size();++i)
#define gc() getchar()
#define ls x<<1,l,m
#define rs x<<1|1,m+1,r
inline int rd()
{
	int x=0,w=1;char c=gc();while(!isdigit(c)&&c!='-')c=gc();
	if(c=='-')c=gc(),w=-1;while(isdigit(c))x=x*10+c-48,c=gc();return x*w;
}
const int N=200005;
#define F(x,y,z) for(re x=y;x<=z;x++)
#define FOR(x,y,z) for(re x=y;x>=z;x--)
int n,m,Q,cc,tt,tp,nn,ff,hd[N],dfn[N],low[N],stk[N],bel[N],top[N],dep[N],fa[N][18],up[N],dn[N];vi G[N];
struct E{int v,nxt;}e[N*2];
inline void adde(int u,int v){e[++cc]=(E){v,hd[u]};hd[u]=cc;}
inline void addg(int u,int v){if(u==v)return;G[u].pb(v);}
void tarjan(int x,int o)
{
	dfn[x]=low[x]=++tt;stk[++tp]=x;
	for(int i=hd[x];i;i=e[i].nxt)if(i!=(o^1))
	{
		int y=e[i].v;
		if(!dfn[y])tarjan(y,i),low[x]=min(low[x],low[y]);
		else if(!bel[y])low[x]=min(low[x],dfn[y]);
	}
	if(dfn[x]==low[x])
	{
		nn++;int y;
		do{y=stk[tp--];bel[y]=nn;}while(y!=x);
	}
}
inline int lca(int x,int y)
{
	if(dep[x]<dep[y])swap(x,y);int d=dep[x]-dep[y];
	per(i,17,0)if(d>>i&1)x=fa[x][i];if(x==y)return x;
	per(i,17,0)if(fa[x][i]!=fa[y][i])x=fa[x][i],y=fa[y][i];return fa[x][0];
}
void dfs1(int x,int p,int d,int t)
{
	fa[x][0]=p;dep[x]=d;top[x]=t;
	rep(i,1,17)fa[x][i]=fa[fa[x][i-1]][i-1];
	for(int y:G[x])if(y!=p)dfs1(y,x,d+1,t);
}
void dfs2(int x,int p)
{
	for(int y:G[x])if(y!=p){dfs2(y,x);up[x]+=up[y];dn[x]+=dn[y];}
	if(up[x]&&dn[x])ff=0;
}
int main()
{
	n=rd();m=rd();Q=rd();cc=1;ff=1;
	rep(i,1,m){int u=rd(),v=rd();adde(u,v);adde(v,u);}
	rep(i,1,n)if(!dfn[i])tarjan(i,0);
	rep(x,1,n)for(int i=hd[x];i;i=e[i].nxt)addg(bel[x],bel[e[i].v]);
	rep(i,1,nn){sort(G[i].begin(),G[i].end());G[i].erase(unique(G[i].begin(),G[i].end()),G[i].end());} 
	rep(i,1,nn)if(!top[i])dep[i]=1,dfs1(i,0,1,i);
	while(Q--)
	{
		int u=rd(),v=rd(),x=bel[u],y=bel[v];
		if(top[x]!=top[y]){puts("No");return 0;}
		int t=lca(x,y);up[x]++;up[t]--;dn[y]++;dn[t]--;
	}
	rep(i,1,nn)if(top[i]==i)dfs2(i,0);
	puts(ff?"Yes":"No");return 0;
}