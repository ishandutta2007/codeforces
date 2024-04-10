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
const int MAXN = 100010, LOG=20;

int n, m, k, u, v, x, y, t, a, b, ans;
int h[MAXN];
int sz[MAXN];
int par[MAXN][LOG];
vector<int> G[MAXN];

int dfs(int node, int p){
	sz[node]=1;
	h[node]=h[p]+1;
	par[node][0]=p;
	for (int i=1; i<LOG; i++) par[node][i]=par[par[node][i-1]][i-1];
	for (int v:G[node]) if (v!=p) sz[node]+=dfs(v, node);
	return sz[node];
}

int getpar(int v, int p){
	for (int i=0; i<LOG; i++) if ((1<<i)&p) v=par[v][i];
	return v;
}

int lca(int x, int y){
	if (h[x]>h[y]) swap(x, y);
	y=getpar(y, h[y]-h[x]);
	for (int i=LOG-1; i>=0; i--) if (par[x][i]!=par[y][i]){
		x=par[x][i];
		y=par[y][i];
	}
	if (x!=y) x=par[x][0];
	return x;
}

int dist(int x, int y, int l){
	return h[x]+h[y]-2*h[l];
}

int query(){
	cin>>x>>y;
	if (x==y) kill(n)
	int l=lca(x, y), d=dist(x, y, l);
	if (d&1) kill(0);
	d/=2;
	if (h[x]==h[y]){
		int xx=getpar(x, d-1), yy=getpar(y, d-1), z=getpar(x, d);
		kill(n-sz[xx]-sz[yy])
	}
	
	if (h[x]<h[y]) swap(x, y);
	int z=getpar(x, d-1), zz=par[z][0];
	int ans=sz[zz]-sz[z];
	kill(ans)
	
}

int main(){
	ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	cin>>n;
	for (int i=1; i<=n-1; i++){
		cin>>u>>v;
		G[u].pb(v);
		G[v].pb(u);
	}
	dfs(1, 0);
	cin>>m;
	while (m--) query();
	
	return 0;
}
/*
15
1 2
1 3
1 4
2 5
2 6
2 7
5 8
6 9
9 14
14 15
7 10
4 13
3 11
3 12
6
10 15
13 12
2 15
8 4
15 12
6 13
*/

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