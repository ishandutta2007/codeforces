#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<ll, ll> pll;
typedef pair<int, int> pii;

#define all(x)      (x).begin(),(x).end()
#define X           first
#define Y           second
#define sep         ' '
#define endl        '\n'
#define SZ(x)       ll(x.size())

const ll MAXN = 1e6 + 10;
const ll LOG = 22;
const ll INF = 8e18;
const ll MOD = 1e9 + 7; //998244353; //1e9 + 9;

ll n , ans = INF , mnA , mnB , sum , sz[MAXN] , dist[MAXN];
vector<pll> adj[MAXN];
vector<pair<pll , ll>> E;

void PreDFS(int v , int p){
	sz[v] = 1; dist[v] = 0;
	for(pll i : adj[v]){
		ll u = i.X , w = i.Y;
		if(u == p)	continue;
		PreDFS(u , v);
		sz[v] += sz[u];
		dist[v] += dist[u] + w * sz[u];
	}
}

void DFS(int v , int p , int n){
	sum += dist[v];
	mnA = min(mnA , dist[v]);
	for(pll i : adj[v]){
		ll u = i.X , w = i.Y;
		if(u == p)	continue;
		dist[u] = dist[v] + (n - 2 * sz[u]) * w;
		DFS(u , v , n);
	}
}

int main() {
    ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);

	cin >> n;
	for(int i = 1 ; i < n ; i++){
		int v , u , w;
		cin >> v >> u >> w;
		adj[v].push_back({u , w});
		adj[u].push_back({v , w});
		E.push_back({{v , u} , w});
	}
	sort(all(E));
	for(auto &i : E){
		int v = i.X.X , u = i.X.Y , w = i.Y; sum = 0;
		mnA = INF ; PreDFS(u , v); DFS(u , v , sz[u]); mnB = mnA;
		mnA = INF ; PreDFS(v , u); DFS(v , u , sz[v]);
		//cout << sum << sep << sz[u] << sep << sz[v] << sep << mnA << sep << mnB << endl;
		ans = min(ans , sum / 2 + sz[u] * mnA + sz[v] * mnB + sz[v] * sz[u] * w);
	}
	cout << ans << endl;

    return 0;
}
/*

*/