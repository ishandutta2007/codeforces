#include <bits/stdc++.h>
#pragma GCC optimize ("O2")
#pragma GCC optimize ("unroll-loops")
//#pragma GCC optimize("no-stack-protector,fast-math")

using namespace std;
typedef long long ll;
typedef long double ld;
typedef pair<int, int> pii;
typedef pair<pii, int> piii;
typedef pair<ll, ll> pll;
#define debug(x) cerr<<#x<<'='<<(x)<<endl;
#define debugp(x) cerr<<#x<<"= {"<<(x.first)<<", "<<(x.second)<<"}"<<endl;
#define debug2(x, y) cerr<<"{"<<#x<<", "<<#y<<"} = {"<<(x)<<", "<<(y)<<"}"<<endl;
#define debugv(v) cerr<<#v<<" : ";for (auto x:v) cerr<<x<<' ';cerr<<endl;
#define all(x) x.begin(), x.end()
#define pb push_back
#define kill(x) return cout<<x<<'\n', 0;

const ld eps=1e-7;
const int inf=1000000010;
const ll INF=10000000000000010LL;
const int mod = 1000000007;
const int MAXN = 100010, LOG=20;

struct DSU{
	int par[MAXN];
	DSU(){
		for (int i=1; i<MAXN; i++) par[i]=i;
	}
	int get(int x){
		if (par[x]==x) return x;
		return par[x]=get(par[x]);
	}
	bool join(int x, int y){
		x=get(x);
		y=get(y);
		if (x==y) return 0;
		par[x]=y;
		return 1;
	}
} dsu;

ll n, m, k, q, u, v, x, y, t, a, b, ans;
int P[MAXN];
ll dist[MAXN];
bool mark[MAXN];
int good[MAXN];
int par[MAXN][LOG], h[MAXN];
ll Mx[MAXN][LOG];
vector<pll> G[MAXN];
vector<pair<ll, pii>> edge;
priority_queue<pll, vector<pll>, greater<pll>> pq;

void dfs(int node){
	h[node]=h[par[node][0]]+1;
	for (int i=1; i<LOG; i++){
		par[node][i]=par[par[node][i-1]][i-1];
		Mx[node][i]=max(Mx[node][i-1], Mx[par[node][i-1]][i-1]);
	}
	for (pll p:G[node]) if (p.first!=par[node][0]){
		int v=p.first;
		par[v][0]=node;
		Mx[v][0]=p.second;
		dfs(v);
	}
}

int Lca(int x, int y){
	if (h[x]>h[y]) swap(x, y);
	for (int i=0; i<LOG; i++) if ((h[y]-h[x])&(1<<i)) y=par[y][i];
	if (x==y) return x;
	for (int i=LOG-1; i>=0; i--) if (par[x][i]!=par[y][i]){
		x=par[x][i];
		y=par[y][i];
	}
	return par[x][0];
}

int main(){
	ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	cin>>n>>m>>k>>q;
	while (m--){
		cin>>u>>v>>x;
		G[u].pb({v, x});
		G[v].pb({u, x});
	}
	memset(dist, 63, sizeof(dist));
	for (int i=1; i<=k; i++){
		//cin>>good[i];
		good[i]=i;
		pq.push({dist[good[i]]=0, good[i]});
		P[good[i]]=good[i];
	}
	
	while (pq.size()){
		int v=pq.top().second;
		pq.pop();
		if (mark[v]) continue ;
		mark[v]=1;
		for (pll p:G[v]) if (dist[v]+p.second<dist[p.first]){
			pq.push({dist[p.first]=dist[v]+p.second, p.first});
			P[p.first]=P[v];
		}
	}
	
	for (int i=1; i<=n; i++){
		for (pll p:G[i]) if (i<p.first) edge.pb({p.second+dist[i]+dist[p.first], {P[i], P[p.first]}});
		G[i].clear();
	}
	sort(all(edge));
	for (auto p:edge) if (dsu.join(p.second.first, p.second.second)){
		int u=p.second.first, v=p.second.second;
		G[u].pb({v, p.first});
		G[v].pb({u, p.first});
	}
	dfs(1);
	
	while (q--){
		cin>>u>>v;
		ans=max(dist[u], dist[v]);
		u=P[u];
		v=P[v];
		int lca=Lca(u, v);
		for (int i=0; i<LOG; i++) if ((h[lca]-h[u])&(1<<i)){
			ans=max(ans, Mx[u][i]);
			u=par[u][i];
		}
		for (int i=0; i<LOG; i++) if ((h[lca]-h[v])&(1<<i)){
			ans=max(ans, Mx[v][i]);
			v=par[v][i];
		}
		cout<<ans<<'\n';
	}
	
	
	return 0;
}