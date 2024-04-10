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

priority_queue<pll, vector<pll>, greater<pll>> pq;
vector<pll> G[MAXN];
void djkasra(ll dist[], ll root){
	pq.push({dist[root]=0, root});
	while (!pq.empty()){
		int v=pq.top().second;
		pq.pop();
		for (pll p:G[v]){
			ll u=p.first, w=p.second;
			if (dist[v]+w<dist[u]) pq.push({dist[u]=dist[v]+w, u});
		}
	}
}

ll n, m, s, u, v, x, y, t, l, ans;
ll dist[MAXN];
pll E[MAXN];
ll W[MAXN];

int main(){
	ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	memset(dist, 63, sizeof(dist));
	cin>>n>>m>>s;
	for (int i=1; i<=m; i++){
		cin>>u>>v>>W[i];
		E[i]={u, v};
		G[u].pb({v, W[i]});
		G[v].pb({u, W[i]});
	}
	djkasra(dist, s);
	//for (int i=1; i<=n; i++) cerr<<dist[i]<<' ';cerr<<endl;
	cin>>l;
	for (int i=1; i<=n; i++) ans+=(dist[i]==l);
	//debug(ans)
	for (int i=1; i<=m; i++){
		int u=E[i].first, v=E[i].second;
		if (dist[u]<dist[v]) swap(u, v);
		if (dist[u]>=l && dist[v]>=l) continue ;
		if (dist[u]<l && dist[v]<l) ans+=(dist[u]+dist[v]+W[i]==2*l);
		if (dist[v]<l) ans+=(l<dist[v]+W[i] && dist[u]+dist[v]+W[i]>2*l);
		if (dist[u]<l) ans+=(l<dist[u]+W[i] && dist[u]+dist[v]+W[i]>2*l);
		//cerr<<u<<' '<<v<<endl;
	}
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