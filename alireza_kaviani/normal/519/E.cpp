#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<ll, ll> pll;
typedef pair<int, int> pii;

#define all(x)						(x).begin(),(x).end()
#define X							first
#define Y							second
#define sep							' '
#define endl						'\n'
#define SZ(x)						ll(x.size())

const ll MAXN = 1e5 + 10;
const ll LOG = 22;
const ll INF = 8e18;
const ll MOD = 1e9 + 7; //998244353; //1e9 + 9;

int n , q , par[LOG][MAXN] , H[MAXN] , sz[MAXN];
vector<int> adj[MAXN];

void DFS(int v , int p = 0){
	sz[v] = 1;
	par[0][v] = p;
	H[v] = H[p] + 1;
	for(int u : adj[v]){
		if(u == p)	continue;
		DFS(u , v);
		sz[v] += sz[u];
	}
}

int getPar(int v , int h){
	for(int i = 0 ; i < LOG ; i++){
		if(h & (1 << i)){
			v = par[i][v];
		}
	}
	return v;
}

int LCA(int v , int u){
	if(H[u] < H[v])	swap(v , u);
	u = getPar(u , H[u] - H[v]);
	if(v == u)	return u;
	for(int i = LOG - 1 ; i >= 0 ; i--){
		if(par[i][v] != par[i][u]){
			v = par[i][v];
			u = par[i][u];
		}
	}
	return par[0][v];
}

int main() {
    ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);

	cin >> n;
	for(int i = 1 ; i < n ; i++){
		int v , u;
		cin >> v >> u;
		adj[v].push_back(u);
		adj[u].push_back(v);
	}
	DFS(1);
	for(int i = 1 ; i < LOG ; i++){
		for(int j = 0 ; j <= n ; j++){
			par[i][j] = par[i - 1][par[i - 1][j]];
		}
	}
	cin >> q;
	while(q--){
		int v , u;
		cin >> v >> u;
		if(H[v] < H[u])	swap(v , u);
		int lca = LCA(v , u);
		int dist = H[v] + H[u] - 2 * H[lca];
		if(dist % 2 == 1){
			cout << 0 << endl;
			continue;
		}
		dist /= 2;
		if(H[v] == H[u]){
			v = getPar(v , dist - 1);
			u = getPar(u , dist - 1);
			cout << n - sz[v] - sz[u] << endl;
			continue;
		}
		v = getPar(v , dist - 1);
		cout << sz[par[0][v]] - sz[v] << endl;
	}

    return 0;
}
/*

*/