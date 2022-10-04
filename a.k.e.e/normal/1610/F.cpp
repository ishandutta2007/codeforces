#include <bits/stdc++.h>
using namespace std;
#define mp make_pair
#define pb push_back
#define x first
#define y second
typedef pair<int,int> pii;
typedef long long ll;
typedef unsigned long long ull;
template <typename T> bool chkmax(T &x,T y){return x<y?x=y,1:0;}
template <typename T> bool chkmin(T &x,T y){return y<x?x=y,1:0;}
template <typename T> void readint(T &x)
{
	x=0;int f=1;char c;
	for(c=getchar();!isdigit(c);c=getchar())if(c=='-')f=-1;
	for(;isdigit(c);c=getchar())x=x*10+(c-'0');
	x*=f;
}
const int MAXN=600005;

int n,m,o;
pii e[MAXN];
int c[MAXN],w[MAXN],f[MAXN],fa[MAXN],deg[MAXN];
vector<int> g[2][MAXN];
vector<pii> h[MAXN];
int getfa(int u){return u==fa[u]?u:fa[u]=getfa(fa[u]);}
int find(vector<int> &g)
{
	if(g.empty())return 0;
	int i=getfa(g.back());
	if(e[i].x==e[i].y)
	{
		g.pop_back();
		return find(g);
	}
	return i;
}
bool vis[MAXN];
void dfs(int u)
{
	vis[u]=1;
	for(auto p:h[u])
	{
		int v=p.x,c=p.y;
		if(vis[v])continue;
		f[v]=f[u]^c;
		dfs(v);
	}
}

int main()
{
	#ifdef LOCAL
	freopen("code.in","r",stdin);
//	freopen("code.out","w",stdout);
	#endif
	readint(n),readint(m);
	for(int i=1;i<=m;++i)
	{
		readint(e[i].x),readint(e[i].y),readint(c[i]);
		g[c[i]-1][e[i].x].pb(i);
		g[c[i]-1][e[i].y].pb(i);
		fa[i]=i;
		deg[e[i].x]+=c[i],deg[e[i].y]+=c[i];
	}
	int fin=0;
	for(int i=1;i<=n;++i)fin+=(deg[i]&1);
	o=m;
	for(int u=1;u<=n;++u)
	{
		for(int t=0;t<2;++t)
			while(1)
			{
				int i=find(g[t][u]);if(!i)break;g[t][u].pop_back();
				int j=find(g[t][u]);if(!j){g[t][u].pb(i);break;}g[t][u].pop_back();
				int vi=e[i].x^e[i].y^u,vj=e[j].x^e[j].y^u;
				++o;fa[o]=o;c[o]=t+1;
				e[o]=mp(vi,vj);
				w[i]=fa[i]=o;f[i]=(u==e[i].x);
				w[j]=fa[j]=o;f[j]=(u==e[j].y);
			}
	}
	for(int u=1;u<=n;++u)
	{
		int i=find(g[1][u]),j=find(g[0][u]);
		if(!i || !j)continue;
		int c=(e[i].y==u)^(e[j].x==u);
		h[i].pb(mp(j,c));
		h[j].pb(mp(i,c));
	}
	for(int i=1;i<=o;++i)if(e[i].x!=e[i].y && !w[i] && !vis[i])dfs(i);
	for(int i=o;i;--i)f[i]^=f[w[i]];
	printf("%d\n",fin);
	for(int i=1;i<=m;++i)putchar('1'+f[i]);
	return 0;
}