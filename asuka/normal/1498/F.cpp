#include<bits/stdc++.h>
#define ll long long
#define N 100015
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
int n,k;
int f[N][42],g[42],ans[N],a[N];
VI e[N];
void dfs(int u,int fa){
	f[u][0] = a[u];
	for(auto v:e[u]) if(v != fa){
		dfs(v,u);
		rep(i,0,2*k-1) f[u][(i+1)%(2*k)] ^= f[v][i];
	}
}
void dfs2(int u,int fa){
	rep(i,k,2*k-1) ans[u] ^= f[u][i];
	for(auto v:e[u]) if(v != fa){
		memset(g,0,sizeof g);
		rep(i,0,2*k-1) g[(i+1)%(2*k)] = f[u][(i+1)%(2*k)]^f[v][i];
		rep(i,0,2*k-1) f[v][(i+1)%(2*k)] ^= g[i];
		dfs2(v,u);
	}
}
int main(){
	//freopen(".in","r",stdin);
	//freopen(".out","w",stdout);
	scanf("%d%d",&n,&k);
	rep(i,2,n){
		int u,v; scanf("%d%d",&u,&v);
		e[u].pb(v); e[v].pb(u);
	}
	rep(i,1,n) scanf("%d",&a[i]);
	dfs(1,0); dfs2(1,0);
	rep(i,1,n) printf("%d ",min(ans[i],1));
	return 0;
}