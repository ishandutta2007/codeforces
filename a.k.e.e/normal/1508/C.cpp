#include <bits/stdc++.h>
using namespace std;
#define mp make_pair
#define pb push_back
#define x first
#define y second
typedef pair<int,int> pii;
typedef long long ll;
typedef unsigned long long ull;
template <typename T> void chkmax(T &x,T y){x<y?x=y:T();}
template <typename T> void chkmin(T &x,T y){y<x?x=y:T();}
template <typename T> void readint(T &x)
{
	x=0;int f=1;char c;
	for(c=getchar();!isdigit(c);c=getchar())if(c=='-')f=-1;
	for(;isdigit(c);c=getchar())x=x*10+(c-'0');
	x*=f;
}
/*const int MOD=;
inline int dmy(int x){return x>=MOD?x-MOD:x;}
inline void inc(int &x,int y){x=dmy(x+y);}
int qmi(int x,int y)
{
	int ans=1;
	for(;y;y>>=1,x=1ll*x*x%MOD)
		if(y&1)ans=1ll*ans*x%MOD;
	return ans;
}*/
const int MAXN=200005;

int n,m,c,cur;
ll sum=0;
pair<int,pii> e[MAXN];
int deg[MAXN];
vector<int> G[MAXN];
vector<pii> H[MAXN];
int vis[MAXN];
int fa[MAXN];
int anc[MAXN][20],dep[MAXN],pre[MAXN];
int getfa(int u){return u==fa[u]?u:fa[u]=getfa(fa[u]);}
void calc(int u,int v,int w)
{
	int fu=getfa(u),fv=getfa(v);
	if(fu==fv)return;
	fa[fu]=fv;
	++cur;
	sum+=w;
	H[u].pb(mp(v,w)),H[v].pb(mp(u,w));
}
void dfs(int u)
{
	for(int i=1;i<20;++i)anc[u][i]=anc[anc[u][i-1]][i-1];
	for(auto p:H[u])
	{
		int v=p.x,w=p.y;
		if(v!=anc[u][0])
		{
			anc[v][0]=u;
			dep[v]=dep[u]+1;
			pre[v]=pre[u]+(!w);
			dfs(v);
		}
	}
}
int lca(int u,int v)
{
	if(dep[u]>dep[v])swap(u,v);
	for(int i=19;i>=0;--i)if(dep[v]-dep[u]>=(1<<i))v=anc[v][i];
	if(u==v)return u;
	for(int i=19;i>=0;--i)if(anc[u][i]!=anc[v][i])u=anc[u][i],v=anc[v][i];
	return anc[u][0];
}

int main()
{
	#ifdef LOCAL
	freopen("code.in","r",stdin);
//	freopen("code.out","w",stdout);
	#endif
	readint(n),readint(m);
	for(int i=1;i<=m;++i)
		readint(e[i].y.x),readint(e[i].y.y),readint(e[i].x),
		c^=e[i].x,++deg[e[i].y.x],++deg[e[i].y.y],
		G[e[i].y.x].pb(e[i].y.y),G[e[i].y.y].pb(e[i].y.x);
	sort(e+1,e+m+1);
	int u=1;
	for(int i=2;i<=n;++i)if(deg[i]<deg[u])u=i;
	for(int i=1;i<=n;++i)fa[i]=i;
	vis[u]=1;
	for(auto v:G[u])vis[v]=u;
	for(int v=1;v<=n;++v)if(vis[v]!=u)calc(u,v,0);
	for(auto i:G[u])
	{
		for(auto j:G[i])vis[j]=i;
		for(int j=1;j<=n;++j)if(vis[j]!=i)calc(i,j,0);
	}
	int tmp=cur;
	for(int i=1;i<=m;++i)calc(e[i].y.x,e[i].y.y,e[i].x);
	if(tmp!=1ll*n*(n-1)/2-m)return 0*printf("%lld\n",sum);
	dfs(1);
	for(int i=1;i<=m;++i)
	{
		int u=e[i].y.x,v=e[i].y.y;
		int d=lca(u,v);
		if(pre[u]+pre[v]-2*pre[d])chkmin(c,e[i].x);
	}
	printf("%lld\n",sum+c);
	return 0;
}