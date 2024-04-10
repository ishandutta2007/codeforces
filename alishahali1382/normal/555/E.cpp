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
#define debug(x) cerr<<#x<<'='<<x<<endl;
#define debugp(x) cerr<<#x<<"= {"<<x.first<<", "<<x.second<<"}"<<endl;
#define all(x) x.begin(), x.end()
#define pb push_back
#define kill(x) return cout<<x<<'\n', 0;

const ld eps=1e-7;
const int inf=1000000010;
const ll INF=10000000000000010LL;
const int mod = 1000000007;
const int MAXN = 200010, LOG=20;

struct DSU{
	int par[MAXN];
	DSU(){ for (int i=1; i<MAXN; i++) par[i]=i;}
	int get(int x){
		if (par[x]==x) return x;
		return par[x]=get(par[x]);
	}
	void join(int x, int y){ par[get(x)]=get(y);}
} dsu;

int h[MAXN], t;
vector<pii> origin[MAXN];
pii E[MAXN];
bool cut[MAXN];
bool mark[MAXN];

int bridge(int node, int p, int id){
	//cerr<<"bridge "<<node<<' '<<p<<endl;
	mark[node]=1;
	int res=h[node]=h[p]+1;
	for (pii pp:origin[node]){
		int v=pp.first, i=pp.second;
		if (i==id) continue ;
		if (mark[v]) res=min(res, h[v]);
		else res=min(res, bridge(v, node, i));
	}
	if (res<h[node]) dsu.join(node, p);
	else cut[id]=1;
	
	return res;
}

int n, m, q, u, v, x, y, a, b;
int ans1[MAXN]; // up
int ans2[MAXN]; // down
int par[MAXN][LOG];
vector<int> G[MAXN];

int sumup(int node, int p, int ps[]){
	for (int v:G[node]) if (v!=p) ps[node]+=sumup(v, node, ps);
	return ps[node];
}

void dfs(int node, int p){
	h[node]=h[p]+1;
	par[node][0]=p;
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

int main(){
	ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	cin>>n>>m>>q;
	for (int i=1; i<=m; i++){
		cin>>u>>v;
		origin[u].pb({v, i});
		origin[v].pb({u, i});
		E[i]={u, v};
	}
	for (int i=1; i<=n; i++) if (!mark[i]) bridge(i, 0, 0);
	for (int i=1; i<=m; i++) if (cut[i]){
		int u=dsu.get(E[i].first), v=dsu.get(E[i].second);
		//cerr<<"edge "<<u<<' '<<v<<endl;
		G[u].pb(v);
		G[v].pb(u);
	}
	for (int i=1; i<=n; i++) if (!par[i][0]) dfs(i, 0);
	
	while (q--){
		cin>>u>>v;
		u=dsu.get(u);
		v=dsu.get(v);
		if (u==v) continue ;
		int l=lca(u, v);
		if (!l) kill("No")
		ans1[u]++;
		ans2[v]++;
		ans1[l]--;
		ans2[l]--;
	}
	for (int i=1; i<=n; i++) if (!par[i][0]){
		sumup(i, 0, ans1);
		sumup(i, 0, ans2);
	}
	for (int i=1; i<=n; i++) if (ans1[i] && ans2[i]) kill("No")
	kill("Yes")
	
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