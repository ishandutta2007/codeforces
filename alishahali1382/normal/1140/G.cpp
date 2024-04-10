#include <bits/stdc++.h>
#pragma GCC optimize ("O2,unroll-loops")

using namespace std;
typedef long long ll;

const int MAXN = 300010, LOG=19;

struct Data{
	ll w[2][2];
} SP[MAXN][LOG];

Data operator +(Data x, Data y){
	Data out;
	for (int i=0; i<2; i++) for (int j=0; j<2; j++) out.w[i][j]=min(x.w[i][0]+y.w[0][j], x.w[i][1]+y.w[1][j]);
	return out;
}

ll n, m, k, u, v, x, y, t, a, b;
ll W[MAXN][2];
int h[MAXN];
int par[MAXN][LOG];
Data D[MAXN];
ll dist[MAXN];
bool mark[MAXN];
vector<pair<int, int>> G[MAXN];
priority_queue<pair<ll, ll>> pq;

void dfs(int node){
	for (int i=1; i<LOG; i++){
		par[node][i]=par[par[node][i-1]][i-1];
		SP[node][i]=SP[node][i-1]+SP[par[node][i-1]][i-1];
	}
	h[node]=h[par[node][0]]+1;
	for (auto p:G[node]) if (p.first!=par[node][0]){
		int v=p.first, i=p.second;
		par[v][0]=node;
		SP[v][0].w[0][0]=min(W[i][0], W[i][1]+dist[v]+dist[node]);
		SP[v][0].w[1][1]=min(W[i][1], W[i][0]+dist[v]+dist[node]);
		SP[v][0].w[0][1]=min(W[i][0]+dist[node], dist[v]+W[i][1]);
		SP[v][0].w[1][0]=min(W[i][1]+dist[node], dist[v]+W[i][0]);
		dfs(v);
	}
}

int LCA(int x, int y){
	if (h[x]>h[y]) swap(x, y);
	for (int i=0; i<LOG; i++) if ((h[y]-h[x])&(1<<i)) y=par[y][i];
	if (x==y) return x;
	for (int i=LOG-1; i>=0; i--) if (par[x][i]!=par[y][i]) x=par[x][i], y=par[y][i];
	return par[x][0];
}

int main(){
	ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	cin>>n;
	for (int i=1; i<=n; i++) cin>>x, pq.push({-(dist[i]=x), i});
	for (int i=1; i<n; i++){
		cin>>u>>v>>W[i][1]>>W[i][0];
		G[u].push_back({v, i});
		G[v].push_back({u, i});
	}
	
	while (pq.size()){
		int v=pq.top().second;
		pq.pop();
		if (mark[v]) continue ;
		mark[v]=1;
		for (auto p:G[v]) if (!mark[p.first]){
			ll w=W[p.second][0]+W[p.second][1];
			if (dist[v]+w<dist[p.first]) pq.push({-(dist[p.first]=dist[v]+w), p.first});
		}
	}
	for (int i=1; i<=n; i++) D[i].w[0][1]=D[i].w[1][0]=dist[i];
	
	dfs(1);
	cin>>m;
	while (m--){
		cin>>x>>y;
		u=(x+1)/2;
		v=(y+1)/2;
		int lca=LCA(u, v);
		Data ans1=D[u], ans2=D[v];
		for (int i=0; i<LOG; i++) if ((h[lca]-h[u])&(1<<i)) ans1=ans1+SP[u][i], u=par[u][i];
		for (int i=0; i<LOG; i++) if ((h[lca]-h[v])&(1<<i)) ans2=ans2+SP[v][i], v=par[v][i];
		swap(ans2.w[0][1], ans2.w[1][0]);
		Data ans=ans1+ans2;
		cout<<ans.w[x&1][y&1]<<'\n';
	}
	return 0;
}