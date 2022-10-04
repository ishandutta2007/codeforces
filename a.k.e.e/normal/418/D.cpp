#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef pair<int,int> pii;
#define x first
#define y second
#define mp make_pair
#define pb push_back
template <typename TYPE> inline void chkmax(TYPE &x,TYPE y){x<y?x=y:0;}
template <typename TYPE> inline void chkmin(TYPE &x,TYPE y){y<x?x=y:0;}
template <typename TYPE> void readint(TYPE &x)
{
    x=0;int f=1;char c;
    for(c=getchar();!isdigit(c);c=getchar())if(c=='-')f=-1;
    for(;isdigit(c);c=getchar())x=x*10+c-'0';
    x*=f;
}
const int MAXN=100005,MAXK=19;

int n;
vector<int> G[MAXN];
int f[MAXN],sec[MAXN],thi[MAXN],g[MAXN],h[MAXN];
int anc[MAXN][MAXK],dep[MAXN],mns[MAXN][MAXK],pls[MAXN][MAXK];
void dfs1(int u,int pa)
{
	for(int i=1;i<MAXK;++i)anc[u][i]=anc[anc[u][i-1]][i-1];
	for(auto v:G[u])
	{
		if(v==pa)continue;
		anc[v][0]=u;
		dep[v]=dep[u]+1;
		dfs1(v,u);
		if(f[v]+1>f[u])thi[u]=sec[u],sec[u]=f[u],f[u]=f[v]+1;
		else if(f[v]+1>sec[u])thi[u]=sec[u],sec[u]=f[v]+1;
		else if(f[v]+1>thi[u])thi[u]=f[v]+1;
	}
}
void dfs2(int u,int pa)
{
	for(int i=1;i<MAXK;++i)
		mns[u][i]=max(mns[u][i-1],mns[anc[u][i-1]][i-1]),
		pls[u][i]=max(pls[u][i-1],pls[anc[u][i-1]][i-1]);
	for(auto v:G[u])
	{
		if(v==pa)continue;
		if(f[v]+1==f[u])g[v]=sec[u]+1;
		else g[v]=f[u]+1;
		h[v]=max(h[u]+1,g[v]);
		mns[v][0]=g[v]-dep[v];
		pls[v][0]=g[v]+dep[v];
		dfs2(v,u);
	}
}
int lca(int u,int v)
{
	if(dep[u]>dep[v])swap(u,v);
	int t=dep[v]-dep[u];
	for(int i=0;i<MAXK;++i)
		if(t&(1<<i))v=anc[v][i];
	if(u==v)return u;
	for(int i=MAXK-1;i>=0;--i)
		if(anc[u][i]!=anc[v][i])
			u=anc[u][i],v=anc[v][i];
	return anc[u][0];
}
int jump(int u,int x)
{
	for(int i=0;i<MAXK;++i)
		if(x&(1<<i))u=anc[u][i];
	return u;
}
int jump_mns(int u,int x)
{
	int ans=-(1<<30);
	for(int i=0;i<MAXK;++i)
		if(x&(1<<i))chkmax(ans,mns[u][i]),u=anc[u][i];
	return ans;
}
int jump_pls(int u,int x)
{
	int ans=-(1<<30);
	for(int i=0;i<MAXK;++i)
		if(x&(1<<i))chkmax(ans,pls[u][i]),u=anc[u][i];
	return ans;
}

int main()
{
	#ifndef ONLINE_JUDGE
	freopen("code.in","r",stdin);
//	freopen("code.out","w",stdout);
	#endif
	int Q,u,v,ans;
	readint(n);
	for(int i=1;i<n;++i)
	{
		readint(u),readint(v);
		G[u].pb(v),G[v].pb(u);
	}
	dfs1(1,-1);
	dfs2(1,-1);
//for(int i=1;i<=n;++i)cerr<<f[i]<<" "<<g[i]<<" "<<h[i]<<endl;
	readint(Q);
	while(Q--)
	{
		readint(u),readint(v);
		if(dep[u]>dep[v])swap(u,v);
		int d=lca(u,v),dis=dep[u]+dep[v]-dep[d]*2;
		if(u==d)
		{
			ans=max(f[v],h[u]);
			int x=jump(v,dep[v]-dep[u]-1);
			if(f[x]+1==f[u])chkmax(ans,sec[u]);
			else chkmax(ans,f[u]);
			chkmax(ans,jump_mns(v,(dis-1)/2)+dep[v]);
			int t=jump(v,(dis-1)/2);
			chkmax(ans,jump_pls(t,dep[t]-dep[u]-1)-dep[u]-2);
		}
		else
		{
			ans=max(f[v],f[u]);
			int x=jump(u,dep[u]-dep[d]-1),y=jump(v,dep[v]-dep[d]-1);
			if(f[x]<f[y])swap(x,y);
			if(f[d]==f[x]+1 && sec[d]==f[y]+1)chkmax(ans,thi[d]+dep[u]-dep[d]);
			else if(f[d]==f[x]+1)chkmax(ans,sec[d]+dep[u]-dep[d]);
			else chkmax(ans,f[d]+dep[u]-dep[d]);
			chkmax(ans,h[d]+dep[u]-dep[d]);
			chkmax(ans,jump_mns(v,(dis-1)/2)+dep[v]);
			int t=jump(v,(dis-1)/2);
			chkmax(ans,jump_pls(t,dep[t]-dep[d]-1)-2-dep[d]+dep[u]-dep[d]);
			chkmax(ans,jump_mns(u,dep[u]-dep[d]-1)+dep[u]);
		}
		printf("%d\n",ans);
	}
	return 0;
}