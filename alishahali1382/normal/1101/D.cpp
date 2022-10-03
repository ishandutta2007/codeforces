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
const int MAXN = 200010;

int n, m, k, u, v, x, y, t, a, b, ans;
int A[MAXN];
bool mark[MAXN];
vector<int> G[MAXN], adj[MAXN];
unordered_map<int, vector<int>> mp;

pii dfs(int node, int par){
	mark[node]=1;
	int res=0, out=node;
	for (int v:G[node]){
		if (v==par) continue ;
		pii p=dfs(v, node);
		if (p.first>res){
			res=p.first;
			out=p.second;
		}
	}
	return {res+1, out};
}

int main(){
	ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	cin>>n;
	for (int i=1; i<=n; i++){
		cin>>A[i];
		int tmp=A[i];
		for (ll j=2; j*j<=tmp; j++){
			if (tmp%j) continue ;
			mp[j].pb(i);
			while (tmp%j==0) tmp/=j;
		}
		if (tmp>1) mp[tmp].pb(i);
	}
	for (int i=0; i<n-1; i++){
		cin>>u>>v;
		adj[u].pb(v);
		adj[v].pb(u);
	}
	for (auto p:mp){
		int x=p.first;
		for (int i:p.second){
			for (int j:adj[i]) if (A[j]%x==0) G[i].pb(j);
		}
		for (int i:p.second){
			if (mark[i]) continue ;
			int node=dfs(i, 0).second;
			ans=max(ans, dfs(node, 0).first);
		}
		
		for (int i:p.second) G[i].clear(), mark[i]=0;
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