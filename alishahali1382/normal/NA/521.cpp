#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
typedef pair<int, int> pii;
typedef pair<int, pii> piii;
typedef pair<ll, ll> pll;
#define debug(x) cerr<<#x<<'='<<x<<endl;
#define debugp(x) cerr<<#x<<"= {"<<x.first<<", "<<x.second<<"}"<<endl;
#define all(x) x.begin(), x.end()
#define pb push_back

const ld eps=1e-7;
const int inf=1000000010;
const int mod = 1000000007;
const int MAXN = 100010;

int n, m, b, x, y, t=1, ans, v, p, q;
int par[MAXN][20];
int lv[MAXN];
int mark[MAXN];
int w[MAXN];
vector<int> child[MAXN];
vector<int> level[MAXN];

void dfs(int node){
	mark[node]=t++;
	if (par[node][0]) lv[node]=lv[par[node][0]]+1;
	
	level[lv[node]].pb(mark[node]);
	for (int i:child[node]) dfs(i);
	w[node]=t;
}

int getpar(int node, int k){
	if (!k) return node;
	return getpar(par[node][__builtin_ctz(k)], k-(k&(-k)));
}

int main(){
	ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	cin>>n;
	for (int i=1; i<=n; i++){
		cin>>par[i][0];
		if (par[i][0]) child[par[i][0]].pb(i);
	}
	for (int j=1; j<=17; j++){
		for (int i=1; i<=n; i++){
			par[i][j]=par[par[i][j-1]][j-1];
		}
	}
	for (int i=1; i<=n; i++) if (!par[i][0]) dfs(i);
	for (int i=0; i<MAXN; i++) level[i].pb(inf);
	//for (int i=1; i<=n; i++) cerr<<mark[i]<<' ';cerr<<endl;
	//for (int i=1; i<=n; i++) cerr<<w[i]<<' ';cerr<<endl;
	cin>>q;
	while (q--){
		cin>>v>>p;
		int x=getpar(v, p);
		if (lv[v]<p || x==0){
			cout<<0<<' ';
			continue ;
		}
		//debug(mark[x]);
		auto y=lower_bound(all(level[lv[v]]), mark[x]);
		auto z=upper_bound(all(level[lv[v]]), w[x]);
		cout<<z-y-1<<' ';
	}
	cout<<endl;
	
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