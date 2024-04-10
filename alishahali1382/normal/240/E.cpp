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

bool mark[MAXN];
vector<int> useless[MAXN];
void ispossible(int node){
	mark[node]=1;
	for (int x:useless[node]) if (!mark[x]) ispossible(x);
}

vector<int> vec;
vector<int> Gin[MAXN], Gout[MAXN];
int comp[MAXN];
void dfs1(int node){
	mark[node]=1;
	for (int x:Gout[node]) if (!mark[x]) dfs1(x);
	vec.pb(node);
}
void dfs2(int node, int id){
	comp[node]=id;
	for (int x:Gin[node]) if (!comp[x]) dfs2(x, id);
}

int n, m, k, u, v, x, y, cnt, a, b, c;
piii E[MAXN];
bool bad[MAXN];
vector<int> G[MAXN];
vector<int> out, comps;
map<pii, int> mp;

void dfs3(int node){
	mark[node]=1;
	for (int v:Gout[node]) if (!mark[v]) dfs3(v);
	for (int v:G[node]) if (!mark[v] && bad[v]){
		bad[v]=0;
		out.pb(mp[{node, v}]);
		dfs3(v);
	}
}

int main(){
	ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
	cin>>n>>m;
	for (int i=0; i<m; i++){
		cin>>a>>b>>c;
		useless[a].pb(b);
		if (c) E[cnt++]={{a, b}, i+1};
		else{
			Gout[a].pb(b);
			Gin[b].pb(a);
		}
	}
	ispossible(1);
	for (int i=1; i<=n; i++) if (!mark[i]) kill(-1);
	memset(mark, 0, sizeof(mark));
	//-------------------------------------------------
	for (int i=2; i<=n; i++) Gin[1].pb(i), Gout[i].pb(1);
	for (int i=1; i<=n; i++) if (!mark[i]) dfs1(i);
	reverse(all(vec));
	for (int i:vec) if (!comp[i]) dfs2(i, i), comps.pb(i);
	for (int i=1; i<=n; i++){
		if (comp[i]==i) continue ;
		for (int j:Gout[i]) Gout[comp[i]].pb(comp[j]);
		for (int j:Gin[i]) Gin[comp[i]].pb(comp[j]);
		Gout[i].clear();
		Gin[i].clear();
	}
	//-------------------------------------------------
	for (int j=0; j<cnt; j++){
		int u=comp[E[j].first.first], v=comp[E[j].first.second], i=E[j].second;
		G[u].pb(v);
		mp[{u, v}]=i;
	}
	for (int i:comps) if (i!=comp[1] && Gin[i].empty()) bad[i]=1; 
	memset(mark, 0, sizeof(mark));
	dfs3(1);
	
	sort(all(out));
	cout<<out.size()<<'\n';
	for (int i:out) cout<<i<<' ';
	
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