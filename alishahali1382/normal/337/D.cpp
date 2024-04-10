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
const int MAXN = 100010;

int n, m, d, u, v, x, y, t, a, b, ans;
int dp1[MAXN];
int dp2[MAXN];
int premx[MAXN];
int sufmx[MAXN];
vector<int> G[MAXN];

int dfsdown(int node, int p){
	for (int i:G[node]) if (i!=p) dp1[node]=max(dp1[node], dfsdown(i, node)+1);
	return dp1[node];
}
void dfsup(int node, int p){
	vector<int> vec;
	vec.pb(0);
	for (int v:G[node]){
		if (v==p) continue ;
		vec.pb(v);
		dp2[v]=max(dp2[v], dp2[node]+1);
	}
	premx[0]=sufmx[vec.size()]=-inf;
	for (int i=1; i<vec.size(); i++) premx[i]=max(premx[i-1], dp1[vec[i]]);
	for (int i=vec.size()-1; i; i--) sufmx[i]=max(sufmx[i+1], dp1[vec[i]]);
	for (int i=1; i<vec.size(); i++) dp2[vec[i]]=max(dp2[vec[i]], max(premx[i-1], sufmx[i+1])+2);
	
	for (int v:G[node]) if (v!=p) dfsup(v, node);
}

int main(){
	ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	memset(dp1, -63, sizeof(dp1));
	memset(dp2, -63, sizeof(dp2));
	cin>>n>>m>>d;
	for (int i=0; i<m; i++) cin>>x, dp1[x]=dp2[x]=0;
	for (int i=0; i<n-1; i++){
		cin>>u>>v;
		G[u].pb(v);
		G[v].pb(u);
	}
	dfsdown(1, 0);
	dfsup(1, 0);
	for (int i=1; i<=n; i++) ans+=(max(dp1[i], dp2[i])<=d);
	cout<<ans<<endl;
	
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