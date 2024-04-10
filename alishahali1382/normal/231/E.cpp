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
	int val[MAXN];
	DSU(){ for (int i=1; i<MAXN; i++) par[i]=i, val[i]=0;}
	int get(int x){
		if (par[x]==x) return x;
		return par[x]=get(par[x]);
	}
	void join(int x, int y){
		par[get(x)]=get(y);
		val[get(y)]=1;
		//debug2(x, y);
	}
	int f(int x){ return val[get(x)];}
} dsu;

int n, m, k, u, v, x, y, t, a, b, ans;
int h[MAXN];
int val[MAXN];
int par[MAXN][LOG];
int tav[MAXN];
vector<int> G[MAXN], original[MAXN];

int bridge(int node, int p){
	int res=h[node]=h[p]+1;
	for (int v:original[node]) if (v!=p){
		if (h[v]) res=min(res, h[v]);
		else res=min(res, bridge(v, node));
	}
	if (res<h[node]) dsu.join(p, node);
	return res;
}

int dfs(int node, int p){
	//debug2(node, p)
	h[node]=h[par[node][0]=p]+1;
	val[node]=val[p]+dsu.f(node);
	for (int i=1; i<LOG; i++) par[node][i]=par[par[node][i-1]][i-1];
	for (int v:G[node]) if (v!=p) dfs(v, node);
}

int lca(int x, int y){
	if (h[x]>h[y]) swap(x, y);
	for (int i=0; i<LOG; i++) if ((1<<i)&(h[y]-h[x])) y=par[y][i];
	for (int i=LOG-1; i>=0; i--) if (par[x][i]!=par[y][i]){
		x=par[x][i];
		y=par[y][i];
	}
	if (x!=y) x=par[x][0];
	return x;
}

int query(){
	cin>>x>>y;
	x=dsu.get(x);
	y=dsu.get(y);
	int l=lca(x, y);
	if (!l) kill(0);
	cout<<tav[val[x]+val[y]-2*val[l]+dsu.f(l)]<<'\n';
}

int main(){
	ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	tav[0]=1;
	for (int i=1; i<MAXN; i++) tav[i]=tav[i-1]*2%mod;
	cin>>n>>m;
	while (m--){
		cin>>u>>v;
		original[u].pb(v);
		original[v].pb(u);
	}
	for (int i=1; i<=n; i++) if (!h[i]) bridge(i, 0);
	for (int i=1; i<=n; i++) for (int j:original[i]) if (dsu.get(i)!=dsu.get(j)) G[dsu.get(i)].pb(dsu.get(j));
	memset(h, 0, sizeof(h));
	for (int i=1; i<=n; i++) if (!h[i] && dsu.par[i]==i) dfs(i, 0);
	//debug("preprocess")
	cin>>k;
	while (k--) query();
	
	return 0;
}
/*
          .---.                                                                     .---.              ...-'  |`. ..-'''-.       / .--. \        .-''-.
          |   |.--.                       .                     .                   |   |.--.          |      |  |\.-'''\ \     ' '    ' '     .' .-.  )
          |   ||__|                     .'|                   .'|                   |   ||__|          ....   |  |       | |    \ \    / /    / .'  / /
          |   |.--.                    <  |                  <  |                   |   |.--.            -|   |  |    __/ /      `.`'--.'    (_/   / /
    __    |   ||  |                     | |             __    | |             __    |   ||  |             |   |  |   |_  '.      / `'-. `.        / /
 .:--.'.  |   ||  |                 _   | | .'''-.   .:--.'.  | | .'''-.   .:--.'.  |   ||  |          ...'   `--'      `.  \   ' /    `. \      / /
/ |   \ | |   ||  |               .' |  | |/.'''. \ / |   \ | | |/.'''. \ / |   \ | |   ||  |          |         |`.      \ '. / /       \ '    . '
`" __ | | |   ||  |              .   | /|  /    | | `" __ | | |  /    | | `" __ | | |   ||  |          ` --------\ |       , || |         | |  / /    _.-')
 .'.''| | |   ||__|            .'.'| |//| |     | |  .'.''| | | |     | |  .'.''| | |   ||__|           `---------'        | || |         | |.' '  _.'.-''
/ /   | |_'---'              .'.'.-'  / | |     | | / /   | |_| |     | | / /   | |_'---'                                 / ,' \ \       / //  /.-'_.'
\ \._,\ '/                   .'   \_.'  | '.    | '.\ \._,\ '/| '.    | '.\ \._,\ '/                              -....--'  /   `.'-...-'.'/    _.'
 `--'  `"                               '---'   '---'`--'  `" '---'   '---'`--'  `"                               `.. __..-'       `-...-'( _.-'
*/