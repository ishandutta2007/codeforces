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
const int MAXN=300005;

int n,a[MAXN],b[MAXN],as[MAXN];
vector<int> G[MAXN];
int pa[MAXN],vis[MAXN],p[MAXN],dep[MAXN],deg[MAXN];
void dfs1(int u)
{
	for(auto v:G[u])
	{
		pa[v]=u;
		dep[v]=dep[u]+1;
		dfs1(v);
	}
}
void dfs2(int u,int &dfn_cnt)
{
	if(!vis[u])vis[u]=++dfn_cnt;
	for(auto v:G[u])dfs2(v,dfn_cnt);
}
void check(const int *tp,ll d)
{
	ll td=d;
	memcpy(p,tp,sizeof(p));
	memcpy(a,as,sizeof(a));
	for(int i=1;i<=n;++i)
		sort(G[i].begin(),G[i].end(),[&](int x,int y){return p[x]<p[y];});
	int dfn_cnt=0;
	memset(vis,0,sizeof(vis));
	dfs2(1,dfn_cnt);
	for(int i=1;i<=n;++i)
		if(p[i]!=vis[i])exit(0*printf("NO\n"));
	priority_queue<pii,vector<pii>,greater<pii> > pq;
	for(int i=1;i<=n;++i)deg[i]=G[i].size();
	for(int i=1;i<=n;++i)if(!deg[i])pq.push(mp(p[i],i));
	memset(vis,0,sizeof(vis));
	dfn_cnt=0;
	for(int i=1;i<=n;++i)
	{
		++dfn_cnt;
		int u=pq.top().y;pq.pop();
		if(d>=dep[u])
		{
			d-=dep[u],vis[u]=i;
			--deg[pa[u]];
			if(!deg[pa[u]])pq.push(mp(p[pa[u]],pa[u]));
		}
		else
		{
			while(d<dep[u])u=pa[u];
			vis[u]=i;
			break;
		}
	}
	dfs2(1,dfn_cnt);
	for(int i=1;i<=n;++i)
		if(vis[i]!=a[i])exit(0*printf("NO\n"));
	printf("YES\n");
	printf("%lld\n",td);
	for(int i=1;i<=n;++i)printf("%d ",p[i]);
	putchar('\n');
	exit(0);
}

int main()
{
	#ifdef LOCAL
	freopen("code.in","r",stdin);
//	freopen("code.out","w",stdout);
	#endif
	ll d=0;
	readint(n);
	for(int i=1;i<=n;++i)readint(a[i]),as[i]=a[i];
	for(int i=1;i<=n;++i)b[a[i]]=i;
	for(int i=1,u,v;i<n;++i)readint(u),readint(v),G[u].pb(v);
	dfs1(1);
	int r=a[1];
	if(r==1)check(as,0);
	for(int i=b[r-1];i!=1;i=pa[i])a[i]=a[pa[i]],++d;
	a[1]=r-1;
	for(int i=1;i<=n;++i)b[a[i]]=i;
	int dfn=0;
	vis[1]=++dfn;
	for(int i=1;i<r-1;++i)
	{
		vector<int> al;
		for(int u=b[i];!vis[u];u=pa[u])al.pb(u);
		reverse(al.begin(),al.end());
		for(auto u:al)vis[u]=++dfn;
		d+=dep[b[i]];
	}
	for(int i=1;i<=n;++i)
		if(!vis[i])vis[i]=a[i];
	check(vis,d);
	return 0;
}