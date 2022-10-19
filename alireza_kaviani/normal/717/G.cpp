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

int n , m , x , F[MAXN] , P[MAXN];
string s , t;

struct mcmf{
	struct edge{
		int to , flow , cap , cost;
	};
	int s , t , x;
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
		return (dist[t] != MOD);
	}
	int solve(){
		int x = t;
		while(par[x] != -1){
			E[par[x]].flow--;
			E[par[x] ^ 1].flow++;
			x = E[par[x]].to;
		}
		return dist[t];
	}
	int maxFlow(int v , int u , int w){
		s = v; t = u; x = w;
		int ans = 0;
		for(int i = 0 ; i < x && SPFA() ; i++){
			ans += solve();
		}
		return ans;
	}
} flow;


int main() {
    ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);

	cin >> n >> s >> m;
	flow.init(n + 1);
	for(int i = 0 ; i < n ; i++)	flow.add(i , i + 1 , MOD , 0);
	for(int i = 0 ; i < m ; i++){
		cin >> t >> P[i]; int l = SZ(t);
		for(int j = 1 , k = 0 ; j < l ; j++){
			while(k > 0 && t[j] != t[k])	k = F[k - 1];
			if(t[j] == t[k])	k++;
			F[j] = k;
//			cout << j << sep << F[j] << endl;
		}
		for(int j = 0 , k = 0 ; j < n ; j++){
			while(k > 0 && s[j] != t[k])	k = F[k - 1];
			if(s[j] == t[k])	k++;
			if(k == l){
				flow.add(j - k + 1 , j + 1 , 1 , -P[i]);
				k = F[k - 1];
			}
		}
	}
	cin >> x;
	cout << -flow.maxFlow(0 , n , x);

    return 0;
}
/*

*/