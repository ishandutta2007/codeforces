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
	struct Edge{
		int from , to , flow , cap;
	};
	int s , t , D , cnt;
	vector<Edge> E;
	vector<vector<int>> adj;
	vector<int> ptr , dist;

	void init(int n){
		E.clear(); adj.clear(); dist.clear(); ptr.clear();
		adj.resize(n); dist.resize(n); ptr.resize(n);
	}
	int addEdge(int v , int u , int cap){
		adj[v].push_back(SZ(E)); E.push_back({v , u , 0 , cap});
		adj[u].push_back(SZ(E)); E.push_back({u , v , 0 , 0});
		return SZ(E) - 2;
	}
	
	int BFS(){
		fill(all(ptr) , 0);
		fill(all(dist) , -1);
		queue<int> Q;
		Q.push(s); dist[s] = 0;
		while(!Q.empty()){
			int v = Q.front(); Q.pop();
			for(int i : adj[v]){
				int u = E[i].to;
				if(dist[u] != -1 || E[i].cap - E[i].flow < D)	continue;
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
			if(dist[u] != dist[v] + 1 || rem < D)	continue;
			int cur = DFS(u , min(F , rem));
			F -= cur; res += cur;
			E[ind].flow += cur;
			E[ind ^ 1].flow -= cur;
			if(F == 0)	break;
		}
		return res;
	}

	int maxFlow(int _s , int _t){
		s = _s; t = _t; D = MOD;
		int ans = 0;
		while(D > 0){
			while(BFS()){
				ans += DFS(s , MOD);
			}
			D /= 2;
		}
		return ans;
	}
} flow;

int n , h , m;

int getInd(int x , int y){
	return (x - 1) * (h + 1) + y + 1;
}

int main() {
    ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);

	cin >> n >> h >> m;
	int last = getInd(n , h);
	flow.init(last + m + 2);
	for(int i = 1 ; i <= n ; i++){
		flow.addEdge(0 , getInd(i , 0) , MOD);
		for(int j = 1 ; j <= h ; j++){
			flow.addEdge(0 , getInd(i , j) , 2 * j - 1);
			flow.addEdge(getInd(i , j) , getInd(i , j - 1) , MOD);
		}
	}
	for(int i = 1 ; i <= m ; i++){
		int l , r , x , c;
		cin >> l >> r >> x >> c;
		if(x == h)	continue;
		for(int j = l ; j <= r ; j++){
			flow.addEdge(getInd(j , x + 1) , last + i , MOD);
		}
		flow.addEdge(last + i , last + m + 1 , c);
	}
	int ans = flow.maxFlow(0 , last + m + 1);
	ans = ans - n * h * h;
	cout << -ans << endl;

    return 0;
}
/*

*/