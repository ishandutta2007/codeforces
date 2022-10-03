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
#define debugv(v) cerr<<#v<<" : ";for (auto SHIT:v) cerr<<SHIT<<' ';cerr<<endl;
#define all(x) x.begin(), x.end()
#define pb push_back
#define kill(x) return cout<<x<<'\n', 0;

const ld eps=1e-7;
const int inf=1000000010;
const ll INF=10000000000000010LL;
const int mod = 1000000007;
const int MAXN = 100010, LOG=20;

struct DSU{
	int par[901];
	vector<int> vec[901];
	DSU(){ for (int i=1; i<=900; i++) par[i]=i, vec[i].pb(i);}
	int get(int x){
		if (par[x]==x) return x;
		return par[x]=get(par[x]);
	}
	void join(int x, int y){
		x=get(x);
		y=get(y);
		if (x==y) return ;
		if (vec[x].size()<vec[y].size()) swap(x, y);
		/*
		debug(x)
		debugv(vec[x])
		debugv(vec[y])
		cerr<<endl;
		*/
		for (int v:vec[y]) vec[x].pb(v);
		par[y]=x;
		vec[y].clear();
		/*
		cerr<<endl;
		debugv(vec[x])
		debugv(vec[y])
		cerr<<endl;
		*/
	}
} dsu;

int n, m, k, u, v, x, y, t, a, b, ans;
int h[901];
bool connected[901][901];
pii E[MAXN];
vector<int> G1[MAXN];
vector<int> G2[MAXN];
vector<pii> cutedge;
vector<int> leaf;
 
int bridge(int node, int par){
	int res=h[node]=h[node]=h[par]+1;
	for (int v:G1[node]) if (v!=par){
		if (h[v]) res=min(res, h[v]);
		else res=min(res, bridge(v, node));
	}
	if (node!=1 && res>=h[node]) cutedge.pb({par, node});
	else dsu.join(par, node);
	
	return res;
}

void dfs(int node, int par){
	if (G2[node].size()==1){
		leaf.pb(node);
		return ;
	}
	for (int v:G2[node]) if (v!=par) dfs(v, node);
}

void connect(int u, int v){
	//debug2(u, v)
	for (int x:dsu.vec[u]) for (int y:dsu.vec[v]) if (!connected[x][y]){
		cout<<x<<' '<<y<<'\n';
		connected[x][y]=1;
		return ;
	}
}

int main(){
	ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	cin>>n>>m;
	if (n==2) kill(-1)
	for (int i=1; i<=m; i++){
		cin>>u>>v;
		G1[u].pb(v);
		G1[v].pb(u);
		E[i]={u, v};
		connected[u][v]=1;
	}
	bridge(1, 1);
	for (pii p:cutedge){
		int u=dsu.get(p.first), v=dsu.get(p.second);
		G2[v].pb(u);
		G2[u].pb(v);
		//cerr<<u<<' '<<v<<endl;
		//debug2(u, v)
	}
	int root=0;
	for (int i=1; i<=n; i++) if (G2[i].size()){
		if (G2[i].size()==1) leaf.pb(i);
		else root=i; 
	}
	//debug(root)
	if (!leaf.size()) kill(0)
	
	cout<<(leaf.size()+1)/2<<'\n';
	
	if (!root){
		connect(leaf[0], leaf[1]);
		return 0;
	}
	leaf.clear();
	dfs(root, root);
	if (leaf.size()&1){
		int v=leaf.back();
		leaf.pop_back();
		connect(v, leaf.back());
	}
	for (int i=0; 2*i<leaf.size(); i++) connect(leaf[i], leaf[i+leaf.size()/2]);
	
	
	for (int i=1; i<=n; i++){
		debugv((dsu.vec[i]));
	}
	
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