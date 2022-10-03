#include <bits/stdc++.h>
#if defined(__GNUC__)
#pragma GCC optimize ("Ofast")
#endif
using namespace std;
typedef long long ll;
typedef long double ld;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
#define debug(x) cerr<<#x<<'='<<x<<endl;
#define debugp(x) cerr<<#x<<"= {"<<x.first<<", "<<x.second<<"}"<<endl;
#define all(x) x.begin(), x.end()
#define pb push_back

const ld eps=1e-7;
const int inf=1000000010;
const int mod = 1000000007;
const int MAXN = 3010;

int n, m, u, v, x, y, t, a, b, s1, t1, l1, s2, t2, l2;
int dist[MAXN][MAXN];
vector<int> G[MAXN];
queue<int> q;

int main(){
	ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	cin>>n>>m;
	for (int i=0; i<m; i++){
		cin>>u>>v;
		G[u].pb(v);
		G[v].pb(u);
	}
	memset(dist, 63, sizeof(dist));
	for (int root=1; root<=n; root++){
		dist[root][root]=0;
		q.push(root);
		while (!q.empty()){
			int v=q.front();
			q.pop();
			for (int u:G[v]){
				if (dist[root][v]+1<dist[root][u]){
					dist[root][u]=dist[root][v]+1;
					q.push(u);
				}
			}
		}
	}
	cin>>s1>>t1>>l1>>s2>>t2>>l2;
	//debug(dist[s1][t1]);
	//debug(dist[s2][t2]);
	if (dist[s1][t1]>l1 || dist[s2][t2]>l2){
		cout<<-1<<endl;
		return 0;
	}
	ll ans=dist[s1][t1]+dist[s2][t2];
	for (int i=1; i<=n; i++){
		for (int j=1; j<=n; j++){
			if (dist[s1][i]+dist[i][j]+dist[j][t1]<=l1 && dist[s2][i]+dist[i][j]+dist[j][t2]<=l2)ans=min(ans, (ll) dist[s1][i]+dist[i][j]+dist[j][t1]+dist[s2][i]+dist[j][t2]);
		}
	}
	swap(s1, t1);
	for (int i=1; i<=n; i++){
		for (int j=1; j<=n; j++){
			if (dist[s1][i]+dist[i][j]+dist[j][t1]<=l1 && dist[s2][i]+dist[i][j]+dist[j][t2]<=l2)ans=min(ans, (ll) dist[s1][i]+dist[i][j]+dist[j][t1]+dist[s2][i]+dist[j][t2]);
		}
	}
	cout<<m-ans<<endl;
	
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