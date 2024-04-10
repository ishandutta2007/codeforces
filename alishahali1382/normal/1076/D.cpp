#include <bits/stdc++.h>
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
const int MAXN = 300010;

struct edge{
	ll x, w, ind;
};

ll n, m, k, ans, t, a, b, u, v, w;
ll dist[MAXN];
int par[MAXN];
int pare[MAXN];
bool mark[MAXN];
vector<edge> adj[MAXN];
priority_queue<pll> pq; 

map<ll, int> out;

int main(){
	ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	cin>>n>>m>>k;
	for (int i=1; i<=m; i++){
		cin>>u>>v>>w;
		edge tmp;
		tmp.ind=i;
		tmp.w=w;
		tmp.x=v;
		adj[u].pb(tmp);
		tmp.x=u;
		adj[v].pb(tmp);
	}
	memset(dist, 63, sizeof(dist));
	dist[1]=0;
	pq.push({0, 1});
	while (!pq.empty()){
		u=pq.top().second;
		pq.pop();
		if (mark[u]) continue ;
		mark[u]=true;
		for (auto it=adj[u].begin(); it!=adj[u].end(); it++){
			v=(*it).x;
			w=(*it).w;
			if (dist[v]>dist[u]+w){
				dist[v]=dist[u]+w;
				par[v]=u;
				pare[v]=(*it).ind;
				pq.push({-dist[v], v});
			}
		}
	}
	cout<<min(k, n-1)<<'\n';
	vector<int> child[MAXN];
	for (int i=1; i<=n; i++) child[par[i]].pb(i);
	queue<int> qu;
	for (int i:child[1]) qu.push(i);
	while (!qu.empty() && k--){
		int fr=(qu.front());
		cout<<pare[fr]<<' ';
		for (auto i:child[fr]) qu.push(i);
		qu.pop();
	}
	cout<<'\n';
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