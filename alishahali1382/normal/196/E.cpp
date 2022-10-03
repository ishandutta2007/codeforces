#include <bits/stdc++.h>
#if defined(__GNUC__)
#pragma GCC optimize ("Ofast")
#endif
using namespace std;
typedef long long ll;
typedef long double ld;
typedef pair<int, int> pii;
typedef pair<ll, pii> edge;
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

struct DSU{
	int par[MAXN];
	DSU(){
		for (int i=1; i<MAXN; i++) par[i]=i;
	}
	int get(int x){
		if (par[x]==x) return x;
		return par[x]=get(par[x]);
	}
	int join(int x, int y){
		if (get(x)==get(y)) return 0;
		par[get(x)]=get(y);
		return 1;
	}
} dsu;

int n, m, k, u, v, w, x, y, t, a, b;
ll ans;
int P[MAXN];
edge E[MAXN];
vector<pii> G[MAXN];
ll dist[MAXN];
int par[MAXN];
bool mark[MAXN];
priority_queue<pii, vector<pii>, greater<pii>> pq;

int main(){
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	scanf("%d%d", &n, &m);
	for (int i=0; i<m; i++){
		scanf("%d%d%d", &u, &v, &w);
		G[u].pb({v, w});
		G[v].pb({u, w});
		E[i]={w, {u, v}};
	}
	memset(dist, 63, sizeof(dist));
	scanf("%d", &k);
	for (int i=0; i<k; i++){
		scanf("%d", &P[i]);
		pq.push({dist[P[i]]=0, P[i]});
		par[P[i]]=P[i];
	}
	while (!pq.empty()){
		int u=pq.top().second;
		pq.pop();
		if (mark[u]) continue ;
		mark[u]=1;
		for (pii p:G[u]){
			int v=p.first, w=p.second;
			if (dist[u]+w<dist[v]){
				pq.push({dist[v]=dist[u]+w, v});
				par[v]=par[u];
			}
		}
	}
	for (int i=0; i<m; i++){
		ll w=E[i].first, u=E[i].second.first, v=E[i].second.second;
		E[i]={w+dist[v]+dist[u], {par[u], par[v]}};
	}
	sort(E, E+m);
	for (int i=0; i<m; i++){
		ll w=E[i].first, u=E[i].second.first, v=E[i].second.second;
		ans+=w*dsu.join(u, v);
	}
	printf("%lld\n", ans+dist[1]);
	
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