#include<bits/stdc++.h>
using namespace std;
#define X first
#define Y second
#define pb push_back
#define mp make_pair
const int N=1005;
int n,rt,m,lim,d,tot,sz[N],w[N],val[N];
pair<int,int>p[N];vector<int>G[N];
void dfs1(int x,int p)
{
	sz[x]=1;for(int v:G[x])if(v!=p)dfs1(v,x),sz[x]+=sz[v],w[x]=max(w[x],sz[v]);
	w[x]=max(w[x],n-sz[x]);if(w[x]<w[rt])rt=x;
}
void dfs2(int x,int p){sz[x]=1;for(int v:G[x])if(v!=p)dfs2(v,x),sz[x]+=sz[v];}
void dfs3(int x,int p)
{
	tot+=d;val[x]=tot;printf("%d %d %d\n",x,p,val[x]-val[p]);
	for(int v:G[x])if(v!=p)dfs3(v,x);
}
int main()
{
	scanf("%d",&n);
	for(int i=1,u,v;i<n;i++)scanf("%d%d",&u,&v),G[u].pb(v),G[v].pb(u);
	w[0]=n;dfs1(1,0);dfs2(rt,0);
	for(int v:G[rt])p[++m]=mp(sz[v],v);
	sort(p+1,p+m+1);
	for(int i=1,sum=0;i<=m;i++)
	{
		sum+=p[i].first;
		if(sum>=(n-1)/3){lim=i;break;}
	}
	d=1;for(int i=1;i<=lim;i++)dfs3(p[i].Y,rt);
	d=tot+1;tot=0;
	for(int i=lim+1;i<=m;i++)dfs3(p[i].Y,rt);
	return 0;
}