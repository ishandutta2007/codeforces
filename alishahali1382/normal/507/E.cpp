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
const int MAXN = 100010;

int n, m, u, v, x, y, t, a, b, ans;
int dist[MAXN];
int dp[MAXN];
int upd[MAXN];
vector<int> G[MAXN], level[MAXN];
set<pii> vec;
map<pii, int> mp;
queue<int> q;

int main(){
	ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	cin>>n>>m;
	for (int i=0; i<m; i++){
		cin>>u>>v>>x;
		G[u].pb(v);
		G[v].pb(u);
		mp[{u, v}]=mp[{v, u}]=x;
	}
	memset(dist, 63, sizeof(dist));
	dist[1]=0;
	q.push(1);
	while (!q.empty()){
		int v=q.front();
		q.pop();
		level[dist[v]].pb(v);
		for (int u:G[v]){
			if (dist[v]+1<dist[u]){
				dist[u]=dist[v]+1;
				q.push(u);
			}
		}
	}
	for (int l=1; l<=n; l++){
		for (int v:level[l]){
			for (int u:G[v]){
				if (dist[u]>=dist[v]) continue ;
				if (dp[u]+mp[{u, v}]>=dp[v]){
					dp[v]=dp[u]+mp[{u, v}];
					upd[v]=u;
				}
			}
		}
	}
	//for (int i=1; i<=n; i++) cerr<<dp[i]<<' ';cerr<<endl;
	//debug(dp[n]);
	//debug(upd[n]);
	int lst=n;
	while (lst!=1){
		vec.insert({upd[lst], lst});
		vec.insert({lst, upd[lst]});
		lst=upd[lst];
	}
	vector<piii> out;
	for (int i=1; i<=n; i++){
		for (int j:G[i]){
			if (j<i) continue ;
			if (mp[{i, j}] && vec.find({i, j})==vec.end()) out.pb({{i, j}, 0});
			if (!mp[{i, j}] && vec.find({i, j})!=vec.end()) out.pb({{i, j}, 1});
		}
	}
	cout<<out.size()<<endl;
	for (piii pp:out){
		pii p=pp.first;
		cout<<p.first<<' '<<p.second<<' '<<pp.second<<'\n';
	}

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