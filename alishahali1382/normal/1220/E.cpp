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
const int MAXN = 200010, LOG=20;

ll n, m, k, u, v, x, y, t, a, b, root;
ll W[MAXN];
bool mark[MAXN];
int comp[MAXN];
ll dp[MAXN];
int h[MAXN];
bool good[MAXN];
vector<int> G[MAXN], G1[MAXN], G2[MAXN];
vector<int> topol;

void add_edge(int u, int v){
	G1[u].pb(v);
	G2[v].pb(u);
}

void SCC1(int node){
	mark[node]=1;
	for (int v:G1[node]) if (!mark[v]) SCC1(v);
	topol.pb(node);
}

void SCC2(int node, int cid){
	comp[node]=cid;
	for (int v:G2[node]) if (!comp[v]) SCC2(v, cid);
}

void SCC(){
	topol.clear();
	memset(mark, 0, sizeof(mark));
	memset(comp, 0, sizeof(comp));
	for (int i=1; i<=n; i++) if (!mark[i]) SCC1(i);
	reverse(all(topol));
	for (int v:topol) if (!comp[v]) SCC2(v, v);
	
	for (int i=1; i<=n; i++) if (comp[i]!=i){
		good[comp[i]]=1;
		W[comp[i]]+=W[i];
		W[i]=0;
		for (int v:G1[i]) if (comp[v]!=comp[i]) G1[comp[i]].pb(comp[v]);
		for (int v:G2[i]) if (comp[v]!=comp[i]) G2[comp[i]].pb(comp[v]);
		G1[i].clear();
		G2[i].clear();
	}
	for (int i=1; i<=n; i++){
		for (int &v:G1[i]) v=comp[v];
		for (int &v:G2[i]) v=comp[v];
	}
	root=comp[root];
}

void dfs1(int node, int par){
	h[node]=h[par]+1;
	for (int v:G[node]) if (v!=par){
		if (!h[v]){
			dfs1(v, node);
			add_edge(node, v);
		}
		else if (h[v]<h[node]) add_edge(node, v);
	}
}

void dfs2(int node, int par){
	mark[node]=1;
	for (int v:G1[node]){
		if (!mark[v]) dfs2(v, node);
		good[node]|=good[v];
	}
	if (good[node]) add_edge(node, par);
}

void dfs3(int node){
	mark[node]=1;
	ll res=0;
	for (int v:G1[node]){
		if (!mark[v]) dfs3(v);
		res=max(res, dp[v]);
	}
	dp[node]=W[node]+res;
}

int main(){
	ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	cin>>n>>m;
	for (int i=1; i<=n; i++) cin>>W[i];
	while (m--){
		cin>>u>>v;
		G[u].pb(v);
		G[v].pb(u);
	}
	cin>>root;
	dfs1(root, root);
	SCC();
	memset(mark, 0, sizeof(mark));
	dfs2(root, root);
	SCC();
	memset(mark, 0, sizeof(mark));
	dfs3(root);
	
	cout<<dp[root]<<'\n';
	
	return 0;
}