#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef pair<int,ll> pii;
#define x first
#define y second
#define mp make_pair
#define pb push_back
template <typename TYPE> inline void chkmax(TYPE &x,TYPE y){x<y?x=y:TYPE();}
template <typename TYPE> inline void chkmin(TYPE &x,TYPE y){y<x?x=y:TYPE();}
template <typename TYPE> void readint(TYPE &x)
{
    x=0;int f=1;char c;
    for(c=getchar();!isdigit(c);c=getchar())if(c=='-')f=-1;
    for(;isdigit(c);c=getchar())x=x*10+c-'0';
    x*=f;
}
const int MAXN=3005;

int n,m,a[MAXN],size[MAXN];
vector<int> G[MAXN];
pii f[MAXN][MAXN],g[MAXN];
inline pii operator +(pii a,pii b){return mp(a.x+b.x,a.y+b.y);}
void dfs(int u,int pa)
{
	f[u][0]=mp(0,a[u]);
	for(int i=1;i<=n;++i)f[u][i]=mp(-1<<30,0);
	size[u]=1;
	for(auto v:G[u])
	{
		if(v==pa)continue;
		dfs(v,u);
		for(int i=0;i<=size[u]+size[v];++i)g[i]=mp(-1<<30,0);
		for(int i=0;i<=size[u];++i)
			for(int j=0;j<=size[v];++j)
			{
				chkmax(g[i+j],f[u][i]+f[v][j]);
				chkmax(g[i+j+1],mp(f[u][i].x+f[v][j].x+(f[v][j].y>0),f[u][i].y));
			}
		for(int i=0;i<=size[u]+size[v];++i)f[u][i]=g[i];
		size[u]+=size[v];
	}
//cerr<<u<<":";for(int i=0;i<=size[u];++i)cerr<<"("<<f[u][i].x<<","<<f[u][i].y<<")";cerr<<endl;
}
void solve()
{
	int x,u,v;
	readint(n),readint(m);
	for(int i=1;i<=n;++i)readint(a[i]);
	for(int i=1;i<=n;++i)
	{
		readint(x);
		a[i]=x-a[i];
	}
	for(int i=1;i<n;++i)
	{
		readint(u),readint(v);
		G[u].pb(v),G[v].pb(u);
	}
	dfs(1,-1);
	printf("%d\n",f[1][m-1].x+(f[1][m-1].y>0));
	for(int i=1;i<=n;++i)G[i].clear();
}

int main()
{
	#ifndef ONLINE_JUDGE
	freopen("code.in","r",stdin);
//	freopen("code.out","w",stdout);
	#endif
	int T;
	readint(T);
	while(T--)solve();
	return 0;
}