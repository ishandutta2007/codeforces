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
#define SZ(x) ((int) x.size())
#define pb push_back
#define kill(x) return cout<<x<<'\n', 0;

const ld eps=1e-7;
const int inf=1000000010;
const ll INF=10000000000000010LL;
const int mod = 1000000007;
const int MAXN = 100010, LOG=20;

void merge(vector<int> v1, vector<int> &v2){
	vector<int> tmp;
	for (int i=0, j=0; i+j<min(10, SZ(v1)+SZ(v2)-2);){
		if (v1[i]<v2[j]) tmp.pb(v1[i++]);
		else tmp.pb(v2[j++]);
	}
	v2.clear();
	for (int i:tmp) v2.pb(i);
	v2.pb(inf);
}

int n, m, k, u, v, x, y, t, q, ans;
int h[MAXN];
int par[MAXN][LOG];
vector<int> G[MAXN];
vector<int> vec[MAXN][LOG];

void dfs(int node, int p){
	par[node][0]=p;
	h[node]=h[p]+1;
	for (int i=1; i<LOG; i++){
		par[node][i]=par[par[node][i-1]][i-1];
		for (int x:vec[par[node][i-1]][i-1]) vec[node][i].pb(x);
		merge(vec[node][i-1], vec[node][i]);
	}
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
	cin>>u>>v>>t;
	vector<int> out;
	out.pb(inf);
	int l=lca(u, v);
	//cerr<<"lca("<<u<<" ,"<<v<<") = "<<l<<endl;
	for (int i=0; i<LOG; i++) if ((1<<i)&(h[u]-h[l])){
		merge(vec[u][i], out);
		u=par[u][i];
	}
	for (int i=0; i<LOG; i++) if ((1<<i)&(h[v]-h[l])){
		merge(vec[v][i], out);
		v=par[v][i];
	}
	merge(vec[l][0], out);
	out.pop_back();
	cout<<min(SZ(out), t)<<' ';
	for (int i=0; i<min(SZ(out), t); i++) cout<<out[i]<<' ';
	cout<<'\n';
}

int main(){
	ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	cin>>n>>m>>q;
	for (int i=0; i<n-1; i++){
		cin>>u>>v;
		G[u].pb(v);
		G[v].pb(u);
	}
	for (int i=1; i<=m; i++){
		cin>>x;
		vec[x][0].pb(i);
	}
	for (int i=1; i<=n; i++){
		sort(all(vec[i][0]));
		vec[i][0].resize(min(10, SZ(vec[i][0])));
		vec[i][0].pb(inf);
	}
	for (int i=0; i<LOG; i++) vec[0][i].pb(inf);
	dfs(1, 0);
	
	while (q--) query();
	/*
	for (int i=1; i<=n; i++){
		cerr<<i<<" : ";
		for (int j:vec[i][0]) cerr<<j<<' ';
		cerr<<endl;
	}*/
	
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