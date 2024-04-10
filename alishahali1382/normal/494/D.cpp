#include <bits/stdc++.h>
#pragma GCC optimize ("Ofast,unroll-loops,fast-math")
using namespace std;
typedef long long ll;
const int mod = 1000000007;
const int MAXN = 100010, LOG=17;

ll n, m, k, u, v, x, y, t, a, b;
int h[MAXN];
int par[MAXN][LOG];
ll path[MAXN];
ll dp1[MAXN][3];
ll dp2[MAXN][3];
ll val[MAXN];
vector<pair<int, int>> G[MAXN];

ll calc1(ll s0, ll s1, ll w){
	return (s1+s0*w)%mod;
}

ll calc2(ll s0, ll s1, ll s2, ll w){
	return (s2+2*w*s1+(w*w%mod)*s0)%mod;
}

void dfs1(int node, int parent){
	dp1[node][0]=1;
	h[node]=h[par[node][0]=parent]+1;
	for (int i=1; i<LOG; i++) par[node][i]=par[par[node][i-1]][i-1];
	for (auto p:G[node]){
		ll v=p.first, w=p.second;
		if (v==parent) continue ;
		path[v]=path[node]+w;
		dfs1(v, node);
		dp1[node][0]+=dp1[v][0];
		dp1[node][1]+=calc1(dp1[v][0], dp1[v][1], w);
		dp1[node][2]+=calc2(dp1[v][0], dp1[v][1], dp1[v][2], w);
	}
	dp1[node][1]%=mod;
	dp1[node][2]%=mod;
}

void dfs2(int node, int parent){
	for (auto p:G[node]){
		ll v=p.first, w=p.second;
		if (v==parent) continue ;
		dp2[v][0]=n-dp1[v][0];
		dp2[v][1]=(calc1(dp2[node][0]+dp1[node][0], dp2[node][1]+dp1[node][1], w)-calc1(dp1[v][0], dp1[v][1], 2*w)+mod)%mod;
		dp2[v][2]=(calc2(dp2[node][0]+dp1[node][0], dp2[node][1]+dp1[node][1], dp2[node][2]+dp1[node][2], w)-calc2(dp1[v][0], dp1[v][1], dp1[v][2], 2*w)+mod)%mod;
		dfs2(v, node);
	}
}

int LCA(int x, int y){
	if (h[x]>h[y]) swap(x, y);
	for (int i=0; i<LOG; i++) if ((h[y]-h[x])&(1<<i)) y=par[y][i];
	if (x==y) return x;
	for (int i=LOG-1; i>=0; i--) if (par[x][i]!=par[y][i]){
		x=par[x][i];
		y=par[y][i];
	}
	return par[x][0];
}

ll f(int v, int u, ll w){
	return dp1[u][2]+dp2[u][2]-calc2(dp2[v][0], dp2[v][1], dp2[v][2], w);
}

ll g(int v, int u, ll w){
	return calc2(dp1[v][0], dp1[v][1], dp1[v][2], w);
}

int main(){
	ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	cin>>n;
	for (int i=1; i<n; i++){
		cin>>u>>v>>x;
		G[u].push_back({v, x});
		G[v].push_back({u, x});
	}
	dfs1(1, 1);
	dfs2(1, 1);
	
	cin>>m;
	while (m--){
		cin>>u>>v;
		int lca=LCA(u, v);
		ll w=(path[u]+path[v]-2*path[lca])%mod;
		ll ans=0;
		if (lca==v) ans=2*f(v, u, w);
		else ans=2*g(v, u, w);
		ans-=f(1, u, path[u]);
		ans%=mod;
		if (ans<0) ans+=mod;
		cout<<ans<<'\n';
	}
	
	return 0;
}