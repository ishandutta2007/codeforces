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
const int MAXN = 400010, LOG=20;

int n, m, k, u, v, x, y, t, a, b, ans;
int h[MAXN];
int sz[MAXN];
int comp[MAXN];
bool mark[MAXN];
pii E[MAXN];
vector<pii> G[MAXN];
vector<int> Gin[MAXN], Gout[MAXN];
vector<int> topol;

void add_edge(int u, int v){
	Gout[u].pb(v);
	Gin[v].pb(u);
	//cerr<<u<<' '<<v<<'\n';
}

void dfs1(int node, int par){
	h[node]=h[par]+1;
	for (pii p:G[node]) if (p.first!=par){
		int v=p.first;
		if (!h[v]){
			add_edge(node, v);
			dfs1(v, node);
		}
		else if (h[v]<h[node]) add_edge(node, v);
	}
}

void dfs2(int node){
	mark[node]=1;
	for (int v:Gout[node]) if (!mark[v]) dfs2(v);
	topol.pb(node);
}

void dfs3(int node, int id){
	sz[id]++;
	comp[node]=id;
	for (int v:Gin[node]) if (!comp[v]) dfs3(v, id);
}

void dfs4(int node, int par){
	h[node]=h[par]+1;
	for (pii p:G[node]) if (p.first!=par){
		int v=p.first, i=p.second;
		if (!h[v]){
			E[i]={node, v};
			dfs4(v, node);
		}
		else if (h[v]<h[node]) E[i]={node, v};
	}
}

int main(){
	ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	cin>>n>>m;
	for (int i=1; i<=m; i++){
		cin>>u>>v;
		E[i]={u, v};
		G[u].pb({v, i});
		G[v].pb({u, i});
	}
	
	dfs1(1, 1);
	for (int i=1; i<=n; i++) if (!mark[i]) dfs2(i);
	
	reverse(all(topol));
	for (int v:topol) if (!comp[v]) dfs3(v, v);
	
	for (int i=1; i<=n; i++) ans=max(ans, sz[i]);
	for (int i=1; i<=n; i++) if (sz[i]==ans){
		memset(h, 0, sizeof(h));
		dfs4(i, i);
		break ;
	}
	cout<<ans<<'\n';
	for (int i=1; i<=m; i++) cout<<E[i].second<<' '<<E[i].first<<'\n';
	
	return 0;
}