#include <bits/stdc++.h>

using namespace std;

#define F first
#define S second
#define pb push_back

typedef long long ll;

const ll INF=1e9+10,M=3e5+100,MOD=1e9+7,ML=25;

typedef pair<ll,ll> pii;
typedef pair<pii,ll> piii;

ll a[M],dp[M],dpu[M],is[M],h[M],lca[ML][M],lc[ML][M];
vector<pii> adj[M];

void dfs(int v,int p){
	dp[v]=a[v];
	h[v]=h[p]+1;
	for(pii u:adj[v]){
		if(u.F==p)
			continue;
		dfs(u.F,v);
		if(dp[u.F]-u.S*2>=0)
			dp[v]+=dp[u.F]-u.S*2;
	}
}

void dfsu(int v,int p,ll w){
	if(p!=v){
		ll x=dpu[p]+dp[p];
		if(w*2<dp[v]){
			x-=dp[v]-w*2;
			is[v]=1;
		}
		if(w*2<x)
			dpu[v]=x-w*2;
	}
	lca[0][v]=p;
	lc[0][v]=dp[v]-w;
	if(is[v])
		lc[0][v]-=dp[v]-w*2;
	for(int i=1;i<=20;i++){
		lca[i][v]=lca[i-1][lca[i-1][v]];
		lc[i][v]=lc[i-1][v]+lc[i-1][lca[i-1][v]];
	}
	for(pii u:adj[v]){
		if(u.F!=p)
			dfsu(u.F,v,u.S);
	}
}

pii gp(int v,int x){
	ll z=0;
	for(int i=0;i<=20;i++){
		if(x&(1<<i)){
			z+=lc[i][v];
			v=lca[i][v];
		}
	}
	return {v,z};
}

ll g(int v,int u){
	if(h[u]<h[v])
		swap(v,u);
	pii p=gp(u,h[u]-h[v]);
	ll ans=p.S;
	u=p.F;
	if(u==v)
		return ans+dp[v]+dpu[v];
	for(int i=20;i>=0;i--){
		if(lca[i][v]!=lca[i][u]){
			ans+=lc[i][v]+lc[i][u];
			v=lca[i][v],u=lca[i][u];
		}
	}
	ans+=dp[lca[0][v]]+dpu[lca[0][v]]+lc[0][v]+lc[0][u];
	return ans;
}

int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	int n,m;
	cin>>n>>m;
	for(int i=1;i<=n;i++)
		cin>>a[i];
	for(int i=1;i<n;i++){
		ll x,y,z;
		cin>>x>>y>>z;
		adj[x].pb({y,z});
		adj[y].pb({x,z});
	}
	dfs(1,1);
	dfsu(1,1,0);
	while(m--){
		ll x,y;
		cin>>x>>y;
		cout<<g(x,y)<<"\n";
	}
}