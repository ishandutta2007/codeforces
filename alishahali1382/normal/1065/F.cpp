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
const int MAXN = 1000010, LOG=20;

int n, m, k, u, v, x, y, t, a, b, ans;
int par[MAXN][LOG];
int leaf[MAXN];
int comp[MAXN];
int sz[MAXN];
int dp[MAXN];
bitset<MAXN> mark;
vector<int> Gin[MAXN], Gout[MAXN];
vector<int> G[MAXN];
vector<int> vec;

int getpar(int v){
	for (int i=0; i<LOG; i++) if ((1<<i)&k) v=par[v][i];
	return v; 
}

void dfsout(int node){
	mark[node]=1;
	for (int v:Gout[node]) if (!mark[v]) dfsout(v);
	vec.pb(node);
}
void dfsin(int node, int c){
	comp[node]=c;
	for (int v:Gin[node]) if (!comp[v]) dfsin(v, c);
}

int f(int node){
	if (dp[node]!=-1) return dp[node];
	dp[node]=0;
	for (int v:G[node]) dp[node]=max(dp[node], f(v));
	return dp[node]+=sz[node];
}

int main(){
	ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	memset(dp, -1, sizeof(dp));
	cin>>n>>k;
	fill(leaf+2, leaf+n+1, 1);
	for (int i=2; i<=n; i++){
		cin>>par[i][0];
		leaf[par[i][0]]=0;
		Gout[par[i][0]].pb(i);
		Gin[i].pb(par[i][0]);
	}
	par[1][0]=1;
	for (int j=1; j<LOG; j++){
		par[1][j]=1;
		for (int i=2; i<=n; i++) par[i][j]=par[par[i][j-1]][j-1];
	}
	for (int i=2; i<=n; i++) if (leaf[i]){
		int p=getpar(i);
		Gin[p].pb(i);
		Gout[i].pb(p);
	}
	dfsout(1);
	reverse(all(vec));
	for (int i:vec) if (!comp[i]) dfsin(i, i);
	for (int i=1; i<=n; i++) sz[comp[i]]+=leaf[i];
	
	for (int i=1; i<=n; i++){
		for (int v:Gout[i]) if (comp[i]!=comp[v]) G[comp[i]].pb(comp[v]);
	}
	cout<<f(1)<<'\n';
	
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