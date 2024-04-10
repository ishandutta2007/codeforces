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

const ll MAXN = 50 + 10;
const ll LOG = 22;
const ll INF = 8e18;
const ll MOD = 1e9 + 7; //998244353; //1e9 + 9;

int n , k , C[MAXN][MAXN];

struct mcmf{
	struct edge{
		int to , flow , cap , cost;
	};
	int n , s , t , k;
	vector<int> dist , par;
	vector<edge> E;
	vector<vector<int>> adj;
	void init(int n){
		dist.clear(); par.clear(); E.clear(); adj.clear();
		dist.resize(n); par.resize(n); adj.resize(n);
	}
	void add(int v , int u , int cap , int cost){
		adj[v].push_back(SZ(E)); E.push_back({u , 0 , cap , cost});
		adj[u].push_back(SZ(E)); E.push_back({v , 0 , 0 , -cost});
	}
	int SPFA(){
		fill(all(dist) , MOD);
		fill(all(par) , -1);
		queue<int> q;
		dist[s] = 0; q.push(s);
		while(!q.empty()){
			int v = q.front(); q.pop();
			for(int i : adj[v]){
				int u = E[i].to , w = E[i].cost;
				if(E[i].flow == E[i].cap)	continue;
				if(dist[u] > dist[v] + w){
					dist[u] = dist[v] + w;
					par[u] = (i ^ 1);
					q.push(u);
				}
			}
		}
		return (dist[t] <= k);
	}
	int solve(){
		int x = t , mn = (dist[t] == 0 ? MOD : k / dist[t]) , ans = 0;
		while(par[x] != -1){
			mn = min(mn , E[par[x] ^ 1].cap - E[par[x] ^ 1].flow);
			x = E[par[x]].to;
		}
		ans += mn; k -= dist[t] * mn;
		x = t;
		while(par[x] != -1){
			E[par[x]].flow -= mn;
			E[par[x] ^ 1].flow += mn;
			x = E[par[x]].to;
		}
		return ans;
	}
	int maxFlow(int v , int u , int x){
		s = v , t = u , k = x;
		int ans = 0;
		while(SPFA())	ans += solve();
		return ans;
	}
} flow;

int main() {
    ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);

	cin >> n >> k;
	flow.init(n);
	for(int i = 0 ; i < n ; i++){
		for(int j = 0 ; j < n ; j++){
			cin >> C[i][j];
			if(C[i][j] == 0)	continue;
			flow.add(i , j , C[i][j] , 0);
			flow.add(i , j , k , 1);
		}
	}
	cout << flow.maxFlow(0 , n - 1 , k) << endl;

    return 0;
}
/*

*/