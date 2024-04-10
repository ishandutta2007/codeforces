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
const int MAXN = 1010;

ll n, m, k, u, v, x, w, t, c, ans, a, b;
ll D[MAXN][MAXN];
ll dist[MAXN];
vector<pll> G[MAXN];
ll G2[MAXN][MAXN];
priority_queue<pll, vector<pll>, greater<pll>> pq;
bool mark[MAXN];

int main(){
	ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	memset(dist, 63, sizeof(dist));
	memset(D, 63, sizeof(D));
	memset(G2, 63, sizeof(G2));
	cin>>n>>m>>a>>b;
	for (int i=0; i<m; i++){
		cin>>u>>v>>w;
		G[u].pb({v, w});
		G[v].pb({u, w});
	}
	for (int i=1; i<=n; i++){
		cin>>t>>c;
		pq.push({D[i][i]=0, i});
		while (!pq.empty()){
			int v=pq.top().second;
			pq.pop();
			//if (D[i][v]>t) continue ;
			for (pii p:G[v]){
				ll u=p.first, w=p.second;
				if (D[i][v]+w<D[i][u]) pq.push({D[i][u]=D[i][v]+w, u});
			}
		}
		G2[i][i]=0;
		for (int j=1; j<=n; j++) if (D[i][j]<=t) G2[i][j]=min(G2[i][j], c);
	}/*
	for (int i=1; i<=n; i++){
		for (int j=1; j<=n; j++) cerr<<G2[i][j]<<' ';cerr<<endl;
	}*/
	dist[a]=0;
	for (int tmp=0; tmp<n; tmp++){
		int v=0;
		for (int i=1; i<=n; i++) if (!mark[i] && dist[i]<=dist[v]) v=i;
		mark[v]=1;
		//debug(v)
		for (int i=1; i<=n; i++) dist[i]=min(dist[i], dist[v]+G2[v][i]);
	}
	//for (int i=1; i<=n; i++) cerr<<dist[i]<<' ';cerr<<endl;
	ll ans=dist[b];
	if (ans>INF) ans=-1;
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