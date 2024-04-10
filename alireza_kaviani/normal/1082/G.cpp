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
const ll INF = 1e18;
const ll MOD = 1e9 + 7; //998244353; //1e9 + 9;

struct MaxFlow{
	struct Edge{
		ll to , flow , cap;
	};
	ll n , s , t , D;
	vector<Edge> E;
	vector<vector<int>> adj;
	vector<int> ptr,  dist;

	void init(int N){
		n = N;
		E.clear(); adj.clear(); ptr.clear(); dist.clear();
		adj.resize(n); ptr.resize(n); dist.resize(n);
	}
	int addEdge(int v , int u , ll cap){
		adj[v].push_back(SZ(E)); E.push_back({u , 0 , cap});
		adj[u].push_back(SZ(E)); E.push_back({v , 0 , 0});
		return SZ(E) - 2;
	}

	int BFS(){
		fill(all(ptr) , 0);
		fill(all(dist) , MOD);
		queue<int> Q;
		Q.push(s); dist[s] = 0;
		while(!Q.empty()){
			int v = Q.front(); Q.pop();
			for(int i : adj[v]){
				ll u = E[i].to, rem = E[i].cap - E[i].flow;
				if(dist[u] == MOD && rem >= D){
					dist[u] = dist[v] + 1;
					Q.push(u);
				}
			}
		}
		return (dist[t] < MOD);
	}

	ll DFS(int v, ll f){
		if(v == t || f == 0){
			return f;
		}
		ll res = 0;
		for( ; ptr[v] < SZ(adj[v]) ; ptr[v]++){
			ll ind = adj[v][ptr[v]] , u = E[ind].to, rem = E[ind].cap - E[ind].flow;
			if(dist[v] + 1 != dist[u])	continue;
			ll cur = DFS(u , min(f , rem));
			f -= cur; res += cur;
			E[ind].flow += cur;
			E[ind ^ 1].flow -= cur;
			if(f == 0)	break;
		}
		return res;
	}

	ll maxFlow(int v , int u){
		ll ans = 0;
		s = v; t = u; D = INF;
		while(D > 0){
			while(BFS()){
				ans += DFS(v , INF);
			}
			D /= 2;
		}
		return ans;
	}
} flow;

ll n , m , sum , deg[MAXN] , A[MAXN];

int main() {
    ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);

	cin >> n >> m;
	flow.init(n + 2);
	for(int i = 1 ; i <= n ; i++)	cin >> A[i];
	for(int i = 1 ; i <= m ; i++){
		int v , u , w;
		cin >> v >> u >> w;
		flow.addEdge(v , u , w);
		flow.addEdge(u , v , w);
		deg[v] += w;
		deg[u] += w;
	}
	for(int i = 1 ; i <= n ; i++){
		flow.addEdge(0 , i , deg[i]);
		flow.addEdge(i , n + 1 , 2 * A[i]);
		sum += deg[i];
	}
	ll res = flow.maxFlow(0 , n + 1);
	cout << (sum - res) / 2 << endl;

    return 0;
}
/*

*/