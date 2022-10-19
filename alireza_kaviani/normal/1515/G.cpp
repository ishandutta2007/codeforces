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

const ll MAXN = 1e6 + 10;
const ll LOG = 22;
const ll INF = 8e18;
const ll MOD = 1e9 + 7; //998244353; //1e9 + 9;

ll n , m , q , cnt , H[MAXN] , comp[MAXN] , mark[MAXN] , g[MAXN];
vector<pii> adj[MAXN] , radj[MAXN];
vector<int> vec;
vector<pair<pii , int>> E;

void DFS1(int v){
	mark[v] = 1;
	for(pii i : adj[v]){
		int u = i.X , w = i.Y;
		if(mark[u])	continue;
		DFS1(u);
	}
	vec.push_back(v);
}

void DFS2(int v){
	mark[v] = 1;
	comp[v] = cnt;
	for(pii i : radj[v]){
		int u = i.X , w = i.Y;
		if(mark[u])	continue;
		DFS2(u);
	}
}

void SCC(){
	for(int i = 1 ; i <= n ; i++){
		if(!mark[i]){
			DFS1(i);
		}
	}
	reverse(all(vec));
	fill(mark , mark + MAXN , 0);
	for(int i : vec){
		if(!mark[i]){
			DFS2(i); cnt++;
		}
	}
}

void DFS3(int v , int p = -1){
	mark[v] = 1;
	int flag = 0;
	for(pii i : adj[v]){
		int u = i.X , w = i.Y;
		if(u == p && flag == 0){
			flag = 1;
			continue;
		}
		if(mark[u] == 1){
			g[comp[u]] = __gcd(g[comp[u]] , H[v] - H[u] + w);
		}
		if(mark[u])	continue;
		H[u] = H[v] + w;
		DFS3(u , v);
	}
	mark[v] = 2;
}

int main() {
    ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);

	cin >> n >> m;
	for(int i = 0 ; i < m ; i++){
		int v , u , w;
		cin >> v >> u >> w;
		adj[v].push_back({u , w});
		radj[u].push_back({v , w});
		E.push_back({{v , u} , w});
	}
	SCC();
	for(int i = 1 ; i <= n ; i++)	adj[i].clear();
	for(pair<pii , int> i : E){
		int v = i.X.X , u = i.X.Y , w = i.Y;
		if(comp[v] != comp[u])	continue;
		adj[v].push_back({u , w});
		adj[u].push_back({v , -w});
	}
	fill(mark , mark + MAXN , 0);
	for(int i = 1 ; i <= n ; i++){
		if(!mark[i]){
			DFS3(i);
		}
	}
	cin >> q;
	while(q--){
		ll v , s , t;
		cin >> v >> s >> t;
		t = __gcd(t , g[comp[v]]);
		if(s % t == 0)	cout << "YES" << endl;
		else	cout << "NO" << endl;
	}

    return 0;
}
/*

*/