#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define X first
#define Y second
#define pii pair<int,int>
#define mp make_pair
#define pb push_back
#define rep(i,a,b) for(int i=a;i<=b;++i)
#define per(i,a,b) for(int i=a;i>=b;--i)
const int N=1000005;
int n,sz[N];ll ans,f[N];vector<int>g[N];
struct pll{ll a,b;}stk[N];
inline ll gt(pll t,ll x){return t.a*x+t.b;}
inline ll chk(pll a,pll b,ll t){return gt(a,t)<gt(b,t);}
inline ll C(ll x){return 1ll*x*(x-1)/2;}
inline bool cmp(int x,int y){return sz[x]<sz[y];}
void dfs(int x,int p)
{
	sz[x]=1;
	for(int i=0;i<g[x].size();i++)
	{
		int y=g[x][i];if(y==p)continue;
		dfs(y,x);sz[x]+=sz[y];
	}
	f[x]=C(sz[x]);
	for(int i=0;i<g[x].size();i++)
	{
		int y=g[x][i];if(y==p)continue;
		f[x]=min(f[x],C(sz[x]-sz[y])+f[y]);
	}
	sort(g[x].begin(),g[x].end(),cmp);
	int L=1,R=1;stk[1]=(pll){0,0};
	for(int i=0;i<g[x].size();i++)
	{
		int y=g[x][i];if(y==p)continue;
		ll xx=n-sz[y],c1=-2*sz[y],c2=1ll*sz[y]*(sz[y]+1)+2*f[y];
		pll p=(pll){c1,c2};while(L<R&&chk(stk[R-1],stk[R],xx))R--;
		ans=max(ans,2ll*C(n)-(stk[R].a*xx+stk[R].b+xx*xx-xx+2ll*f[y])/2);stk[++R]=p;
		while(L<R&&chk(stk[R-1],stk[R],xx))R--;
	}
}
int main()
{
	scanf("%d",&n);
	for(int i=1;i<n;i++){int u,v;scanf("%d%d",&u,&v);g[u].pb(v);g[v].pb(u);}
	dfs(1,0);printf("%lld\n",ans);
	return 0;
}