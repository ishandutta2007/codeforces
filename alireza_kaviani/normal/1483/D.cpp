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

int n , m , q , par[MAXN] , sz[MAXN] , cnt[MAXN] , ans[MAXN][MAXN];
ll dist[MAXN][MAXN];
vector<pair<int , pii>> E;

int main() {
    ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
	fill(par , par + MAXN , -1);
	fill(sz , sz + MAXN , 1);
	for(int i = 0 ; i < MAXN ; i++){
		fill(dist[i] , dist[i] + MAXN , INF);
		dist[i][i] = 0;
	}

	cin >> n >> m;
	for(int i = 0 ; i < m ; i++){
		int v , u , w;
		cin >> v >> u >> w;
		dist[v][u] = dist[u][v] = w;
		E.push_back({w , {v , u}});
	}
	for(int k = 1 ; k <= n ; k++){
		for(int i = 1 ; i <= n ; i++){
			for(int j = 1 ; j <= n ; j++){
				dist[i][j] = min(dist[i][j] , dist[i][k] + dist[k][j]);
			}
		}
	}
	cin >> q;
	for(int i = 1 ; i <= q ; i++){
		int v , u , w;
		cin >> v >> u >> w;
		for(int j = 1 ; j <= n ; j++){
			ans[j][v] = max((ll)ans[j][v] , w - dist[j][u]);
			ans[j][u] = max((ll)ans[j][u] , w - dist[j][v]);
		}
	}
	int res = 0;
	for(auto & i : E){
		ll w = i.X , v = i.Y.X , u = i.Y.Y , flag = 0;
		for(int j = 1 ; j <= n ; j++){
			if(ans[v][j] >= w + dist[u][j])	flag = 1;
		}
		res += flag;
	}
	cout << res << endl;
	//for(int i = 1 ; i <= q ; i++)	cout << ans[i] << endl;

    return 0;
}
/*

*/