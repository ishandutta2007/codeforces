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
const int MAXN = 10010;

struct edge{
	int u, v;
	ll l, r, val;
} E[110];
bool emark[110];
set<pll> G[MAXN];

priority_queue<pll, vector<pll>, greater<pll>> pq;
void djkasra(ll dist[], int root){
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

int n, m, k, s1, s2, f, u, v, x, y, t, a, b, ans;
ll dist1[MAXN], dist2[MAXN];

int main(){
	ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	cin>>n>>m>>k>>s1>>s2>>f;
	while (m--){
		cin>>u>>v>>x;
		G[u].insert({v, x});
	}
	for (int i=1; i<=k; i++){
		cin>>u>>v>>x>>y;
		E[i]={u, v, x, y, y};
		G[u].insert({v, y});
	}
	int flag=1;
	while (flag--){
		memset(dist1, 63, sizeof(dist1));
		memset(dist2, 63, sizeof(dist2));
		djkasra(dist1, s1);
		djkasra(dist2, s2);
		//cerr<<"dist1 : ";for (int i=1; i<=n; i++) cerr<<dist1[i]<<' ';cerr<<endl;
		//cerr<<"dist2 : ";for (int i=1; i<=n; i++) cerr<<dist2[i]<<' ';cerr<<endl;
		for (int i=1; i<=k; i++){
			if (emark[i]) continue ;
			if (dist1[E[i].u]<dist2[E[i].u]){
				debug(i)
				emark[i]=1;
				G[E[i].u].erase({E[i].v, E[i].val});
				G[E[i].u].insert({E[i].v, E[i].val=E[i].l});
				flag=1;
				break ;
			}
		}
	}
	if (dist1[f]>dist2[f]) kill("LOSE");
	if (dist1[f]==dist2[f]) cout<<"DRAW\n";
	else cout<<"WIN\n";
	for (int i=1; i<=k; i++) cout<<E[i].val<<' ';
	
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