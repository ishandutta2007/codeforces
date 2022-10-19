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

const ll MAXN = 1e3 + 10;
const ll LOG = 22;
const ll INF = 1e18;
const ll MOD = 1e9 + 7; //998244353; //1e9 + 9;

struct MaxFlow{
	struct edge{
		int to , flow , cap;
	};
	int n , s , t;
	vector<int> dist , ptr;
	vector<edge> E;
	vector<vector<int>> adj;
	void init(int n){
		dist.clear(); ptr.clear(); E.clear(); adj.clear();
		adj.resize(n); ptr.resize(n); dist.resize(n);
	}
	void add(int v , int u , int cap){
		adj[v].push_back(SZ(E)); E.push_back({u , 0 , cap});
		adj[u].push_back(SZ(E)); E.push_back({v , 0 , 0});
	}
	int BFS(){
		fill(all(dist) , MOD);
		fill(all(ptr) , 0);
		queue<int> q;
		q.push(s); dist[s] = 0;
		while(!q.empty()){
			int v = q.front() ; q.pop();
			for(int i : adj[v]){
				if(E[i].flow == E[i].cap)	continue;
				if(dist[E[i].to] != MOD)	continue;
				dist[E[i].to] = dist[v] + 1;
				q.push(E[i].to);
			}
		}
		return (dist[t] != MOD);
	}
	ll DFS(int v , ll flow){
		if(v == t)	return flow;
		ll ans = 0;
		for( ; ptr[v] < SZ(adj[v]) ; ptr[v]++){
			int i = adj[v][ptr[v]] , u = E[i].to;
			if(E[i].cap == E[i].flow || dist[u] != dist[v] + 1)	continue;
			ll res = DFS(u , min(flow , ll(E[i].cap - E[i].flow)));
			ans += res; flow -= res;
			E[i].flow += res; E[i ^ 1].flow -= res;
			if(flow == 0)	break;
		}
		return ans;
	}
	ll maxFlow(int v , int u){
		ll ans = 0;
		s = v , t = u;
		while(BFS())	ans += DFS(s , INF);
		return ans;
	}
} flow;

int n , A[MAXN] , C[MAXN] , adj[MAXN][MAXN];

int main() {
    ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);

	cin >> n;
	flow.init(2 * n + 5);
	for(int i = 1 ; i <= n ; i++)	flow.add(0 , i , 1);
	for(int i = 1 ; i <= n ; i++)	flow.add(i + n , 2 * n + 1 , 1);
	for(int i = 1 ; i <= n ; i++){
		int k; cin >> k;
		for(int j = 0 ; j < k ; j++){
			int x; cin >> x;
			adj[i][x] = 1;
			flow.add(i , x + n , 1);
		}
	}
	flow.maxFlow(0 , 2 * n + 1);
	for(int i = 1 ; i <= n ; i++){
		for(int j : flow.adj[i]){
			if(flow.E[j].flow == 1){
				A[i] = flow.E[j].to - n;
			}
		}
		//cout << i << sep << A[i] << endl;
	}
	flow.init(n + 2);
	ll ans = 0;
	for(int i = 1 ; i <= n ; i++){
		cin >> C[i];
		if(C[i] >= 0){
			flow.add(i , n + 1 , C[i]);
		}
		else{
			flow.add(0 , i , -C[i]);
			ans += C[i];
		}
	}
	for(int i = 1 ; i <= n ; i++){
		for(int j = 1 ; j <= n ; j++){
			if(i != j && adj[i][A[j]]){
				flow.add(i , j , MOD);
				//cout << i << sep << j << endl;
			}
		}
	}
	cout << ans + flow.maxFlow(0 , n + 1) << endl;

    return 0;
}
/*

*/