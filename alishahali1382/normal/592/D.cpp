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

const ld eps=1e-7;
const int inf=1000000010;
const int mod = 1000000007;
const int MAXN = 123466;

int n, m, u, v, x, y, t, root, a, ans;
bool A[MAXN];
bool check[MAXN];
int dist[MAXN];
int par[MAXN];
vector<int> G[MAXN];

bool dfs0(int node, int p){
	bool res=A[node];
	for (int v:G[node]){
		if (v==p) continue ;
		res|=dfs0(v, node);
	}
	return check[node]=res;
}
void dfs(int node, int p, int dd){
	int d=0, res=node;
	dist[node]=dd++;
	for (int i:G[node]){
		if (i==p || !check[i]) continue ;
		dfs(i, node, dd);
	}
}

int main(){
	ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	cin>>n>>m;
	for (int i=0; i<n-1; i++){
		cin>>u>>v;
		G[u].pb(v);
		G[v].pb(u);
	}
	for (int i=1; i<=n; i++) sort(all(G[i]));
	for (int i=0; i<m; i++){
		cin>>x;
		A[x]=1;
		root=x;
	}
	dfs0(x, 0);
	/*
	int node=dfs(root, 0, 0).second;
	debug(node);
	int ans2=node;
	pii pp=dfs(node, 0, 0);
	int mx=pp.first, mn=pp.second;
	debug(mn);
	ans2=min(ans2, mn);
	*/
	dfs(root, 0, 0);
	int mx=0;
	for (int i=1; i<=n; i++){
		if (check[i] && (!mx || dist[mx]<dist[i])) mx=i;
	}
	int ans2=mx;
	debug(ans2);
	dfs(mx, 0, 0);
	mx=0;
	for (int i=1; i<=n; i++){
		if (check[i] && (!mx || dist[mx]<dist[i])) mx=i;
	}
	ans2=min(mx, ans2);
	debug(ans2);
	
	for (int i=0; i<MAXN; i++) ans+=2*check[i];
	ans=ans-2-dist[mx];
	
	
	cout<<ans2<<endl;
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