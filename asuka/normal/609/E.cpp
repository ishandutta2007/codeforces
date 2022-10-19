#include<bits/stdc++.h>
#define int long long
#define N 200015
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
#define all(x) x.begin(),x.end()
#define SZ(x) ((int)x.size())
using namespace std;
int n,m;
struct edge{
	int u,v,w;
	int id;
}g[N];
int ans[N];
int fa[N];
int find(int x){return x == fa[x] ? x : fa[x] = find(fa[x]);}
int uni(int u,int v){
	u = find(u); v = find(v);
	if(u == v) return 0;
	fa[u] = v;
	return 1;
}
bool cmp(edge a,edge b){
	return a.w < b.w;
}
vector<pii> e[N];
int up[N][21],Max[N][21],dep[N];
void add(int u,int v,int w){
	// printf("%d %d\n",u,v);
	e[u].pb(mp(v,w)); e[v].pb(mp(u,w));
}
void dfs(int u,int f){
	up[u][0] = f; dep[u] = dep[f]+1;
	for(auto V:e[u]){
		int v = V.fi,w = V.se;
		if(v == f) continue;
		Max[v][0] = w;
		dfs(v,u);
	}
}
int query(int u,int v){
	int res = 0;
	if(dep[u] < dep[v]) swap(u,v);
	int t = dep[u] - dep[v];
	rep(i,0,19) if((1<<i)&t) res = max(res,Max[u][i]),u = up[u][i];
	if(u == v) return res;
	per(i,0,19){
		if(up[u][i] != up[v][i]){
			res = max({res,Max[u][i],Max[v][i]});
			u = up[u][i]; v = up[v][i];
		}
	}
	res = max({res,Max[u][0],Max[v][0]});
	return res;
}
void init(){
	dfs(1,0);
	rep(j,1,19) rep(i,1,n) up[i][j] = up[up[i][j-1]][j-1],Max[i][j] = max(Max[i][j-1],Max[up[i][j-1]][j-1]);
}
int sum;
signed main(){
	//freopen(".in","r",stdin);
	//freopen(".out","w",stdout);
 	scanf("%lld%lld",&n,&m);
 	rep(i,1,m) scanf("%lld%lld%lld",&g[i].u,&g[i].v,&g[i].w),g[i].id = i;
 	sort(g+1,g+m+1,cmp);
 	rep(i,1,n) fa[i] = i;
 	rep(i,1,m){
 		if(uni(g[i].u,g[i].v)){
 			add(g[i].u,g[i].v,g[i].w);
 			sum += g[i].w;
 		}
 	}
 	init();
 	rep(i,1,m) ans[g[i].id] = sum - query(g[i].u,g[i].v) + g[i].w;
 	rep(i,1,m) printf("%lld\n",ans[i]);
	return 0;
}