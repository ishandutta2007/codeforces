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
const double eps = 1e-8;

struct mcmf{
	struct edge{
		int to , flow , cap;
		double cost;
	};
	int s , t;
	vector<double> dist;
	vector<int> par , mark;
	vector<edge> E;
	vector<vector<int>> adj;
	void init(int n){
		dist.clear(); par.clear(); E.clear() ; adj.clear(); mark.clear();
		dist.resize(n); par.resize(n); adj.resize(n); mark.resize(n);
	}
	void add(int v , int u , int cap , double cost){
		adj[v].push_back(SZ(E)); E.push_back({u , 0 , cap , cost});
		adj[u].push_back(SZ(E)); E.push_back({v , 0 , 0 , -cost});
	}
	int SPFA(){
		fill(all(dist) , MOD);
		fill(all(par) , -1);
		fill(all(mark) , 0);
		queue<int> q;
		dist[s] = 0; q.push(s);
		while(!q.empty()){
			int v = q.front(); q.pop();
			mark[v] = 0;
			for(int i : adj[v]){
				int u = E[i].to;
				double w = E[i].cost;
				if(E[i].flow == E[i].cap)	continue;
				if(dist[u] > dist[v] + w + eps){
					dist[u] = dist[v] + w;
					par[u] = (i ^ 1);
					if(!mark[u]){
						q.push(u);
						mark[u] = 1;
					}
				}
			}
		}
		return (dist[t] != MOD);
	}
	pair<int, double> solve(){
		int x = t , mn = 1;
		while(par[x] != -1){
			mn = min(mn , E[par[x] ^ 1].cap - E[par[x] ^ 1].flow);
			x = E[par[x]].to;
		}
		x = t;
		while(par[x] != -1){
			E[par[x]].flow -= mn; E[par[x] ^ 1].flow += mn;
			x = E[par[x]].to;
		}
		return {mn , mn * dist[t]};
	}
	pair<int , double> maxFlow(int v , int u){
		s = v; t = u;
		pair<int , double> ans = {0 , 0};
		while(SPFA()){
			pair<int , double> A = solve();
			ans.X += A.X; ans.Y += A.Y;
		}
		return ans;
	}
} flow;

int n , x[MAXN] , y[MAXN];

int main() {
    ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);

	cin >> n;
	for(int i = 1 ; i <= n ; i++){
		cin >> x[i] >> y[i];
	}
	flow.init(2 * n + 5);
	for(int i = 1 ; i <= n ; i++){
		flow.add(0 , i , 2 , 0);
		flow.add(i + n , 2 * n + 1 , 1 , 0);
	}
	for(int i = 1 ; i <= n ; i++){
		for(int j = 1 ; j <= n ; j++){
			if(y[i] <= y[j])	continue;
			double dist = sqrt((x[i] - x[j]) * (x[i] - x[j]) + (y[i] - y[j]) * (y[i] - y[j]));
			flow.add(i , j + n , 1 , dist);
		}
	}
	pair<int, double> A = flow.maxFlow(0 , 2 * n + 1);
	if(A.X != n - 1)	return cout << -1 << endl , 0;
	printf("%.15f" , A.Y);

    return 0;
}
/*

*/