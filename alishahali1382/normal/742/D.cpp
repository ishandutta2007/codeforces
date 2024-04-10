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
const int MAXN = 1010;

struct DSU{
	int par[MAXN];
	vector<pii> vec[MAXN];
	DSU(){
		for (int i=1; i<MAXN; i++) par[i]=i;
	}
	int get(int x){
		if (par[x]==x) return x;
		return par[x]=get(par[x]);
	}
	void join(int x, int y){
		x=get(x);
		y=get(y);
		if (x==y) return ;
		if (vec[x].size()<vec[y].size()) swap(x, y);
		for (pii p:vec[y]) vec[x].pb(p);
		vec[y].clear();
		par[y]=x;
	}
} dsu;

int n, m, w, u, v, x, y, t, a, b, ans;
int dp[MAXN][MAXN];

void upd(int i, int a, int b){
	for (int j=1; j<=w; j++){
		dp[i][j]=max(dp[i][j], max(dp[i-1][j], dp[i][j-1]));
		if (j>=a) dp[i][j]=max(dp[i][j], dp[i-1][j-a]+b);
	}
}

int main(){
	ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	cin>>n>>m>>w;
	for (int i=1; i<=n; i++) cin>>x, dsu.vec[i].pb({x, 0});
	for (int i=1; i<=n; i++) cin>>dsu.vec[i][0].second;
	while (m--){
		cin>>u>>v;
		dsu.join(u, v);
	}
	for (int i=1; i<=n; i++){
		if (dsu.par[i]!=i) continue ;
		t++;
		a=b=0;
		for (pii p:dsu.vec[i]){
			a+=p.first;
			b+=p.second;
			upd(t, p.first, p.second);
		}
		upd(t, a, b);
	}
	cout<<dp[t][w]<<endl;
	
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