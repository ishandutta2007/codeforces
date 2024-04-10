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

int n , cntE , A[MAXN] , mark[MAXN];
vector<int> cur , adj[MAXN];
vector<vector<int>> ans;

int isPrime(int x){
	for(int i = 2 ; i * i <= x ; i++){
		if(x % i == 0){
			return 0;
		}
	}
	return 1;
}

void DFS(int v){
	mark[v] = 1;
	cur.push_back(v);
	for(int u : adj[v]){
		if(!mark[u]){
			DFS(u);
		}
	}
}

int main() {
	ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);

	cin >> n; flow.init(n + 2);
	for(int i = 1 ; i <= n ; i++){
		cin >> A[i];
		if(A[i] % 2 == 0){
			flow.add(0 , i , 2);
			cntE++;
		}
		else{
			flow.add(i , n + 1 , 2);
		}
	}
	if(cntE * 2 != n){
		return cout << "Impossible" << endl , 0;
	}
	for(int i = 1 ; i <= n ; i++){
		if(A[i] & 1)	continue;
		for(int j = 1 ; j <= n ; j++){
			if(isPrime(A[i] + A[j])){
				flow.add(i , j , 1);
			}
		}
	}
	int result = flow.maxFlow(0 , n + 1);
	if(result != n){
		return cout << "Impossible" << endl , 0;
	}
	for(int i = 1 ; i <= n ; i++){
		if(A[i] & 1)	continue;
		for(int j : flow.adj[i]){
			int to = flow.E[j].to;
			if(to == 0 || to == n + 1)	continue;
			if(flow.E[j].flow == 1){
				adj[i].push_back(to);
				adj[to].push_back(i);
			}
		}
	}

	for(int i = 1 ; i <= n ; i++){
		if(mark[i])	continue;
		cur.clear();
		DFS(i);
		ans.push_back(cur);
	}
	cout << ans.size() << endl;
	for(vector<int> vec : ans){
		cout << vec.size() << sep;
		for(int i : vec){
			cout << i << sep;
		}
		cout << endl;
	}

	return 0;
}
/*

*/