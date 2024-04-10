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

struct edge{
	int u, v, x;
} E[MAXN];

int n, m, k, u, v, x, y, t, a, b;
ll tav[MAXN*10], ans;
int h[MAXN];
int ans1[MAXN]; // up
int ans2[MAXN]; // down
int par[MAXN][LOG];
vector<int> G[MAXN];

void sumup(int node, int p){
	for (int v:G[node]) if (v!=p){
		sumup(v, node);
		ans1[node]+=ans1[v];
		ans2[node]+=ans2[v];
	}
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
	for (int i=1; i<MAXN*10; i++) tav[i]=(tav[i-1]*2+1)%mod;
	cin>>n;
	for (int i=0; i<n-1; i++){
		cin>>u>>v>>x;
		G[u].pb(v);
		G[v].pb(u);
		E[i]={u ,v, x};
	}
	dfs(1, 0);
	cin>>m;
	u=1;
	while (m--){
		cin>>v;
		int l=lca(u, v);
		ans1[u]++;
		ans2[v]++;
		ans1[l]--;
		ans2[l]--;
		u=v;
	}
	sumup(1, 0);
	for (int i=0; i<n-1; i++) if (E[i].x){
		int u=E[i].u, v=E[i].v;
		if (h[u]<h[v]) ans=(ans+tav[ans1[v]])%mod;
		else ans=(ans+tav[ans2[u]])%mod;
	}
	cout<<ans<<'\n';
	
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