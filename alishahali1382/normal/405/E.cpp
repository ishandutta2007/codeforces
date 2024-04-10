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

struct P3{
	int a, b, c;
} out[MAXN/2];

int n, m, k, u, v, x, y, t, a, b, ans;
bool mark[MAXN];
set<int> G[MAXN];

void dfs(int node, int p){
	mark[node]=true;
	vector<int> tmp, vec;
	for (int v:G[node]) vec.pb(v);
	for (int v:vec){
		if (v==p || !G[node].count(v)) continue ;
		if (mark[v]){
			tmp.pb(v);
			continue ;
		}
		dfs(v, node);
		if (G[v].size()) tmp.pb(v);
	}
	for (int i=1; i<tmp.size(); i+=2){
		int a=tmp[i-1], b=tmp[i];
		out[t++]={a, node, b};
		G[node].erase(a);
		G[node].erase(b);
		G[a].erase(node);
		G[b].erase(node);
	}
	if (G[node].size()>=2){
		int a=*G[node].begin();
		G[node].erase(a);
		int b=*G[node].begin();
		G[node].erase(b);
		out[t++]={a, node, b};
		//cerr<<a<<' '<<node<<' '<<b<<endl;
		G[a].erase(node);
		G[b].erase(node);
	}
}

int main(){
	ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	cin>>n>>m;
	for (int i=0; i<m; i++){
		cin>>u>>v;
		G[u].insert(v);
		G[v].insert(u);
	}
	for (int i=1; i<=n; i++){
		if (mark[i]) continue ;
		dfs(i, 0);
		if (G[i].size()) kill("No solution")
	}
	for (int i=0; i<t; i++) cout<<out[i].a<<' '<<out[i].b<<' '<<out[i].c<<'\n';
	
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