#include <bits/stdc++.h>
using namespace std;
#define x first
#define y second
#define mp make_pair
#define pb push_back
typedef pair<int,int> pii;
typedef long long ll;
typedef unsigned long long ull;
typedef pair<ll,ll> pll;
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
}
int inv(int x){return qmi(x,MOD-2);}*/
const int MAXN=300005;

int n;
vector<int> G[MAXN],H[MAXN];
int dfn[MAXN],dfn_cnt,ans,sz[MAXN];
set<pii> s;
void dfs1(int u)
{
	dfn[u]=++dfn_cnt;
	sz[u]=1;
	for(auto v:H[u])
		dfs1(v),sz[u]+=sz[v];
}
void dfs2(int u)
{
	int x=(--s.lower_bound(mp(dfn[u],0)))->y;
	int w=0;
	if(dfn[u]<dfn[x]+sz[x])w=x,s.erase(mp(dfn[x],x));
	s.insert(mp(dfn[u],u));
	chkmax(ans,(int)s.size()-1);
	for(auto v:G[u])
		dfs2(v);
	s.erase(mp(dfn[u],u));
	if(w)s.insert(mp(dfn[w],w));
}
void solve()
{
	readint(n);
	for(int i=1;i<=n;++i)G[i].clear(),H[i].clear();
	for(int i=2,u;i<=n;++i)readint(u),G[u].pb(i);
	for(int i=2,v;i<=n;++i)readint(v),H[v].pb(i);
	ans=dfn_cnt=0;
	s.clear();s.insert(mp(0,0));
	dfs1(1);
	dfs2(1);
	printf("%d\n",ans);
}

int main()
{
	#ifdef LOCAL
	freopen("code.in","r",stdin);
//	freopen("code.out","w",stdout);
	#endif
	int T;
	readint(T);
	while(T--)solve();
	return 0;
}