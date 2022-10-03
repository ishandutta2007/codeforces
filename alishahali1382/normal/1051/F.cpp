#include <bits/stdc++.h>
#if defined(__GNUC__)
#pragma GCC optimize ("Ofast")
#endif
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

priority_queue<pll, vector<pll>, greater<pll>> pq;
vector<pii> G[MAXN];
void djkasra(ll dist[], int root){
	pq.push({dist[root]=0, root});
	while (!pq.empty()){
		int v=pq.top().second;
		pq.pop();
		for (pll p:G[v]) if (dist[v]+p.second<dist[p.first]) pq.push({dist[p.first]=dist[v]+p.second, p.first});
	}
}

int n, m, q, u, v, x, y, t, a, b, ans;
ll h[MAXN];
int h2[MAXN];
int par[MAXN][LOG];
ll dist[21][MAXN];
bitset<MAXN> mark;
vector<int> vec;

void dfs(int node, int parent){
	mark.set(node);
	par[node][0]=parent;
	h2[node]=h2[parent]+1;
	for (int i=1; i<LOG; i++) par[node][i]=par[par[node][i-1]][i-1];
	bool flag=0;
	for (pii p:G[node]) if (p.first!=parent){
		if (!mark[p.first]){
			h[p.first]=h[node]+p.second;
			dfs(p.first, node);
			continue ;
		}
		if (h2[p.first]<h2[node]) flag=1;
	}
	if (flag) vec.pb(node);
}

int lca(int x, int y){
	if (h2[x]>h2[y]) swap(x, y);
	for (int i=0; i<LOG; i++) if ((1<<i)&(h2[y]-h2[x])) y=par[y][i];
	for (int i=LOG-1; i>=0; i--) if (par[x][i]!=par[y][i]){
		x=par[x][i];
		y=par[y][i];
	}
	if (x!=y) x=par[x][0];
	return x;
}

void query(){
	cin>>u>>v;
	ll ans=h[u]+h[v]-2*h[lca(u, v)];
	for (int i=0; i<vec.size(); i++) ans=min(ans, dist[i][u]+dist[i][v]);
	cout<<ans<<'\n';
}

int main(){
	ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	memset(dist, 63, sizeof(dist));
	cin>>n>>m;
	while (m--){
		cin>>u>>v>>x;
		G[u].pb({v, x});
		G[v].pb({u, x});
	}
	fill(par[1], par[1]+LOG, 1);
	dfs(1, 1);
	for (int i=0; i<vec.size(); i++) djkasra(dist[i], vec[i]);
	cin>>q;
	while (q--) query();
	
	return 0;
}
/*
      ___           ___                            ___           ___           ___           ___           ___           ___
     /\  \         /\__\      ___                 /\  \         /\__\         /\  \         /\__\         /\  \         /\__\      ___
    /::\  \       /:/  /     /\  \               /::\  \       /:/  /        /::\  \       /:/  /        /::\  \       /:/  /     /\  \
   /:/\:\  \     /:/  /      \:\  \             /:/\ \  \     /:/__/        /:/\:\  \     /:/__/        /:/\:\  \     /:/  /      \:\  \
  /::\~\:\  \   /:/  /       /::\__\           _\:\~\ \  \   /::\  \ ___   /::\~\:\  \   /::\  \ ___   /::\~\:\  \   /:/  /       /::\__\
 /:/\:\ \:\__\ /:/__/     __/:/\/__/          /\ \:\ \ \__\ /:/\:\  /\__\ /:/\:\ \:\__\ /:/\:\  /\__\ /:/\:\ \:\__\ /:/__/     __/:/\/__/
 \/__\:\/:/  / \:\  \    /\/:/  /             \:\ \:\ \/__/ \/__\:\/:/  / \/__\:\/:/  / \/__\:\/:/  / \/__\:\/:/  / \:\  \    /\/:/  /
      \::/  /   \:\  \   \::/__/               \:\ \:\__\        \::/  /       \::/  /       \::/  /       \::/  /   \:\  \   \::/__/
      /:/  /     \:\  \   \:\__\                \:\/:/  /        /:/  /        /:/  /        /:/  /        /:/  /     \:\  \   \:\__\
     /:/  /       \:\__\   \/__/                 \::/  /        /:/  /        /:/  /        /:/  /        /:/  /       \:\__\   \/__/
     \/__/         \/__/                          \/__/         \/__/         \/__/         \/__/         \/__/         \/__/
*/