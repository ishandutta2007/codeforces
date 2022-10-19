#include<bits/stdc++.h>
#define int long long
#define N 5005
#define mod 998244353
#define rep(i,a,n) for (int i=a;i<=n;i++)
#define per(i,a,n) for (int i=n;i>=a;i--)
#define inf 0x3f3f3f3f
#define pb push_back
#define mp make_pair
#define pii pair<int,int>
#define fi first
#define se second
#define lowbit(i) ((i)&(-i))
#define VI vector<int>
using namespace std;
int f[N][N],g[N],dep[N],maxdep[N];
int n,k;
VI e[N];
void dfs(int u,int fa){
	maxdep[u] = dep[u] = dep[fa]+1;
	f[u][0] = 1;
	for(auto v:e[u]) if(v != fa){
		dfs(v,u);
		int l1 = maxdep[u]-dep[u],l2 = maxdep[v]-dep[u];
		rep(i,0,max(l1,l2)+1) g[i] = 0;
		rep(i,0,l1) rep(j,0,l2){
			(g[i] += f[u][i]*f[v][j]) %= mod;
		}
		rep(i,0,l1) rep(j,0,l2){
			if(i+j+1>k) break;
			(g[max(i,j+1)] += f[u][i]*f[v][j]) %= mod;
		}
		maxdep[u] = max(maxdep[u],maxdep[v]);
		rep(i,0,maxdep[u]-dep[u]) f[u][i] = g[i];
	}
}
signed main(){
	//freopen(".in","r",stdin);
	//freopen(".out","w",stdout);
	scanf("%lld%lld",&n,&k);
	rep(i,2,n){
		int u,v; scanf("%lld%lld",&u,&v);
		e[u].pb(v); e[v].pb(u);
	}
	dfs(1,0); int res = 0;
	rep(i,0,k) (res += f[1][i]) %= mod;
	printf("%lld\n",res);
	return 0;
}