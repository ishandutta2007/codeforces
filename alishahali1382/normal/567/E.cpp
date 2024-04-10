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
#define kill(x) return cout<<x<<'\n', 0;

const ld eps=1e-7;
const int inf=1000000010;
const ll INF=10000000000000010LL;
const int mod = 1000000007;
const int MAXN = 100010;

struct edge{
	ll u, v, w;
} E[MAXN];

priority_queue<pll, vector<pll>, greater<pll>> pq;
void djkasra(ll dist[], vector<pll> adj[]){
	while (!pq.empty()){
		int v=pq.top().second;
		pq.pop();
		for (pll p:adj[v]){
			ll u=p.first, w=p.second;
			if (dist[v]+w<dist[u]) pq.push({dist[u]=dist[v]+w, u});
		}
	}
}

int n, m, k, u, v, w, x, s, t, a, b, ans;
ll dist1[MAXN];
ll dist2[MAXN];
bool bad[MAXN];
bool cut[MAXN];
bool mark[MAXN];
int lv[MAXN];
int vis[MAXN];
vector<pll> adjin[MAXN], adjout[MAXN]; 
vector<pii> G[MAXN];

int dfs(int node, int par, int id){
	mark[node]=1;
	int res=lv[node]=lv[par]+1;
	for (pii p:G[node]){
		int v=p.first, idd=p.second;
		if (idd==id) continue ;
		if (mark[v]) res=min(res, lv[v]);
		else res=min(res, dfs(v, node, idd));
		
	}
	if (res>=lv[node]) cut[id]=1;
	return res;
}

int main(){
	ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	memset(dist1, 63, sizeof(dist1));
	memset(dist2, 63, sizeof(dist2));
	cin>>n>>m>>s>>t;
	for (int i=1; i<=m; i++){
		cin>>u>>v>>w;
		E[i]={u, v, w};
		adjout[u].pb({v, w});
		adjin[v].pb({u, w});
	}
	pq.push({dist1[s]=0, s});
	djkasra(dist1, adjout);
	pq.push({dist2[t]=0, t});
	djkasra(dist2, adjin);
	for (int i=1; i<=m; i++){
		bad[i]=(dist1[E[i].u]+E[i].w+dist2[E[i].v]>dist1[t]);
		if (!bad[i]){
			G[E[i].u].pb({E[i].v, i});
			G[E[i].v].pb({E[i].u, i});
		}
	}
	for (int i=1; i<=n; i++) if (!mark[i]) dfs(i, 0, 0);
	
	for (int i=1; i<=m; i++){
		if (bad[i]){
			ll w=dist1[t]-1-dist1[E[i].u]-dist2[E[i].v];
			if (w<=0){
				cout<<"NO\n";
				continue ;
			}
			w=E[i].w-w;
			if (w>=E[i].w){
				cout<<"NO\n";
				continue ;
			}
			cout<<"CAN "<<w<<'\n';
			continue ;
		}
		if (cut[i]) cout<<"YES\n";
		else{
			if (E[i].w>1) cout<<"CAN 1\n";
			else cout<<"NO\n";
		}
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