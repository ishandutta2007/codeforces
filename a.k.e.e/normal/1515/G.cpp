#include <bits/stdc++.h>
using namespace std;
#define x first
#define y second
#define mp make_pair
#define pb push_back
typedef pair<int,int> pii;
typedef long long ll;
typedef unsigned long long ull;
template <typename T> void chkmin(T &x,T y){y<x?x=y:T();}
template <typename T> void chkmax(T &x,T y){x<y?x=y:T();}
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

int n;
vector<pii> G[MAXN];
int dfn[MAXN],low[MAXN],scc[MAXN],sta[MAXN],db[MAXN],dfn_cnt,scc_cnt,top;
vector<ll> al;
bool vis[MAXN];
ll dis[MAXN],rs[MAXN];
void tarjan(int u)
{
	dfn[u]=low[u]=++dfn_cnt;
	sta[++top]=u;
	for(auto p:G[u])
	{
		if(p.y<0)continue;
		int v=p.x;
		if(!dfn[v])tarjan(v),chkmin(low[u],low[v]);
		else if(!scc[v])chkmin(low[u],dfn[v]);
	}
	if(low[u]==dfn[u])
	{
		db[++scc_cnt]=u;
		while(1)
		{
			int w=sta[top--];
			scc[w]=scc_cnt;
			if(w==u)break;
		}
	}
}
void dfs(int u,int col)
{
	vis[u]=1;
	for(auto p:G[u])
	{
		int v=p.x,d=p.y;
		if(scc[v]!=col)continue;
		if(vis[v])al.pb(dis[u]-dis[v]+d);
		else dis[v]=dis[u]+d,dfs(v,col);
	}
}

int main()
{
	#ifdef LOCAL
	freopen("code.in","r",stdin);
//	freopen("code.out","w",stdout);
	#endif
	int E;
	readint(n),readint(E);
	while(E--)
	{
		int u,v,c;
		readint(u),readint(v),readint(c);
		G[u].pb(mp(v,c)),G[v].pb(mp(u,-c));
	}
	for(int i=1;i<=n;++i)
		if(!dfn[i])tarjan(i);
	for(int i=1;i<=scc_cnt;++i)
	{
		al.clear();
		int u=db[i];
		dfs(u,i);
		for(auto j:al)rs[i]=__gcd(rs[i],j);
	}
	int Q;
	readint(Q);
	while(Q--)
	{
		int u,s;
		ll t;
		readint(u),readint(s),readint(t);
		printf(s%__gcd(t,rs[scc[u]])==0?"YES\n":"NO\n");
	}
	return 0;
}