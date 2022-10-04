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
const int MAXN=100005;

int n,f[MAXN],g[MAXN];
vector<int> G[MAXN];
void chkmax(int &x,int &y,int z)
{
	if(z>x)y=x,x=z;
	else if(z>y)y=z;
}
int rt,ans=0;
void dfs(int u,int pa)
{
	int secg=0,secf=0,add=0,sz=G[u].size()-(u!=rt);
	for(auto v:G[u])
	{
		if(v==pa)continue;
		dfs(v,u);
		chkmax(g[u],secg,max(f[v],g[v]));
		chkmax(f[u],secf,g[v]);
	}
	++f[u];
	if(sz>=2)
	{
		chkmax(ans,f[u]+secf);
		chkmax(ans,g[u]+secg+sz-2+(u!=rt));
	}
	g[u]+=sz-1;
	chkmax(ans,g[u]);
	chkmax(ans,f[u]);
//cerr<<u<<":"<<f[u]<<" "<<g[u]<<endl;
}

int main()
{
	#ifndef ONLINE_JUDGE
	freopen("code.in","r",stdin);
//	freopen("code.out","w",stdout);
	#endif
	int u,v;
	readint(n);
	for(int i=1;i<n;++i)readint(u),readint(v),G[u].pb(v),G[v].pb(u);
	rt=1;
	for(int i=2;i<=n;++i)if(G[i].size()>G[rt].size())rt=i;
	dfs(rt,-1);
	printf("%d\n",ans);
	return 0;
}