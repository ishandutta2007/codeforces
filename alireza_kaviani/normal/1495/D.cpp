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

const ll MAXN = 400 + 10;
const ll LOG = 22;
const ll INF = 8e18;
const ll MOD = 998244353; //1e9 + 9;

int n , m , mark[MAXN] , inDeg[MAXN] , dist[MAXN][MAXN] , par[MAXN][MAXN] , cnt[MAXN][MAXN];
vector<int> adj[MAXN];
vector<pii> E , E2;

void BFS(int ind , int v){
	fill(dist[ind] , dist[ind] + MAXN , MOD);
	dist[ind][v] = 0;
	queue<int> q;
	q.push(v);
	while(!q.empty()){
		v = q.front(); q.pop();
		for(int u : adj[v]){
			if(dist[ind][u] == MOD){
				dist[ind][u] = dist[ind][v] + 1;
				q.push(u);
			}
			if(dist[ind][u] == dist[ind][v] + 1){
				par[ind][u] = v;
				cnt[ind][u]++;
			}
		}
	}
}

int main() {
    ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);

	cin >> n >> m;
	for(int i = 0 ; i < m ; i++){
		int v , u;
		cin >> v >> u;
		adj[v].push_back(u);
		adj[u].push_back(v);
		E.push_back({v , u});
	}
	for(int i = 1 ; i <= n ; i++)	BFS(i , i);
	for(int i = 1 ; i <= n ; i++){
		for(int j = 1 ; j <= n ; j++){
			int x = j;
			fill(mark , mark + MAXN , 0);
			while(cnt[i][x] == 1)	mark[x] = 1 , x = par[i][x];
			mark[x] = 1;
			if(x != i){
				cout << 0 << sep;
				continue;
			}
			fill(inDeg , inDeg + MAXN , 0);
			for(pii k : E){
				int v = k.X , u = k.Y;
				if(dist[i][v] == dist[i][u] + 1 && dist[j][v] == dist[j][u] + 1)	inDeg[v]++;
				if(dist[i][u] == dist[i][v] + 1 && dist[j][u] == dist[j][v] + 1)	inDeg[u]++;
			}
			ll ans = 1;
			for(int k = 1 ; k <= n ; k++){
				if(mark[k])	continue;
				ans = ans * inDeg[k] % MOD;
			}
			cout << ans << sep;
		}
		cout << endl;
	}

    return 0;
}
/*

*/