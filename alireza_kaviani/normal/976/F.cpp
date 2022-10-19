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

const ll MAXN = 1e4 + 10;
const ll LOG = 22;
const ll INF = 8e18;
const ll MOD = 1e9 + 7; //998244353; //1e9 + 9;

struct MaxFlow{
	struct Edge{
		int from , to , flow , cap;
	};
	int s , t;
	vector<Edge> E;
	vector<vector<int>> adj;
	vector<int> ptr , dist;
	
	void init(int n){
		E.clear(); adj.clear(); ptr.clear(); dist.clear();
		adj.resize(n); ptr.resize(n); dist.resize(n);
	}
	int addEdge(int v , int u , int cap){
		adj[v].push_back(SZ(E)); E.push_back({v , u , 0 , cap});
		adj[u].push_back(SZ(E)); E.push_back({u , v , 0 , 0});
		return SZ(E) - 2;
	}

	int BFS(){
		fill(all(dist) , -1);
		fill(all(ptr) , 0);
		queue<int> Q;
		Q.push(s); dist[s] = 0;
		while(!Q.empty()){
			int v = Q.front(); Q.pop();
			for(int i : adj[v]){
				int u = E[i].to;
				if(E[i].cap == E[i].flow || dist[u] != -1)	continue;
				dist[u] = dist[v] + 1;
				Q.push(u);
			}
		}
		return (dist[t] != -1);
	}

	int DFS(int v , int F){
		if(v == t || F == 0)	return F;
		int res = 0;
		for( ; ptr[v] < SZ(adj[v]) ; ptr[v]++){
			int ind = adj[v][ptr[v]] , u = E[ind].to , rem = E[ind].cap - E[ind].flow;
			if(rem == 0 || dist[u] != dist[v] + 1)	continue;
			int cur = DFS(u , min(F , rem));
			F -= cur; res += cur;
			E[ind].flow += cur;
			E[ind ^ 1].flow -= cur;
			if(F == 0)	break;
		}
		return res;
	}

	int maxFlow(int _s , int _t){
		s = _s; t = _t;
		int ans = 0;
		while(BFS()){
			ans += DFS(s , MOD);
		}
		return ans;
	}
} flow;

int n1 , n2 , m , deg[MAXN];
vector<int> E , E2 , D , ans[MAXN];

int main() {
    ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);

	cin >> n1 >> n2 >> m;
	flow.init(n1 + n2 + 2);
	for(int i = 0 ; i < m ; i++){
		int v , u;
		cin >> v >> u;
		E2.push_back(flow.addEdge(v , u + n1 , 1));
		deg[v]++;
		deg[u + n1]++;
	}
	for(int i = 1 ; i <= n1 ; i++){
		E.push_back(flow.addEdge(0 , i , 0));
		D.push_back(deg[i]);
	}
	for(int i = n1 + 1 ; i <= n1 + n2 ; i++){
		E.push_back(flow.addEdge(i , n1 + n2 + 1 , 0));
		D.push_back(deg[i]);
	}
	int mnDeg = MOD;
	for(int i : D){
		mnDeg = min(mnDeg , i);
	}
	for(int i = MAXN ; i >= 0 ; i--){
		flow.maxFlow(0 , n1 + n2 + 1);
		if(i <= mnDeg){
			for(int j = 0 ; j < m ; j++){
				if(flow.E[E2[j]].flow == 0){
					ans[i].push_back(j + 1);
				}
			}
		}
		for(int j = 0 ; j < SZ(E) ; j++){
			if(D[j] >= i){
				flow.E[E[j]].cap++;
			}
		}
	}
	for(int i = 0 ; i <= mnDeg ; i++){
		cout << SZ(ans[i]) << sep;
		for(int j : ans[i]){
			cout << j << sep;
		}
		cout << endl;
	}

    return 0;
}
/*

*/