#include <bits/stdc++.h>
#include <ext/pb_ds/tree_policy.hpp>
#include <ext/pb_ds/assoc_container.hpp>

using namespace std;
using namespace __gnu_pbds;

template <class T> using Tree = tree<T, null_type, less<T>, rb_tree_tag,tree_order_statistics_node_update>;

typedef long long ll;
typedef long double ld;
typedef pair<ll, ll> pll;
typedef pair<int, int> pii;

#define all(x)                      (x).begin(),(x).end()
#define Sort(x)                     sort(all((x)))
#define X                           first
#define Y                           second
#define sep                         ' '
#define endl                        '\n'
#define SZ(x)                       ll(x.size())

ll poww(ll a, ll b, ll md) {
	return (!b ? 1 : (b & 1 ? a * poww(a * a % md, b / 2, md) % md : poww(a * a % md, b / 2, md) % md));
}

const ll MAXN = 1e6 + 10;
const ll LOG = 30;
const ll INF = 8e18;
const ll MOD = 1e9 + 7; // 998244353; // 1e9 + 9;

int n , m , ans , val[MAXN] , mark[MAXN] , res[LOG];
vector<pii> adj[MAXN];
vector<pair<pii , int>> E;

void DFS(int v){
	mark[v] = 1;
	for(pii i : adj[v]){
		int u = i.X , w = i.Y;
		if(mark[u])	continue;
		val[u] = val[v] ^ w;
		DFS(u);
	}
}

int main() {
	ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);

	cin >> n >> m;
	for(int i = 0 ; i < m ; i++){
		int v , u , w;
		cin >> v >> u >> w;
		adj[v].push_back({u , w});
		adj[u].push_back({v , w});
		E.push_back({{v , u} , w});
	}
	DFS(1);
	vector<int> vec;
	for(auto& i : E){
		int v = i.X.X , u = i.X.Y , w = i.Y;
		vec.push_back(val[u] ^ val[v] ^ w);
	}
	for(int i : vec){
		int cur = i;
		for(int j = LOG - 1 ; j >= 0 ; j--){
			if((cur & (1 << j)) == 0)	continue;
			cur ^= res[j];
			if(res[j] == 0){
				res[j] = cur;
				break;
			}
		}
	}
	int ans = val[n];
	for(int i = LOG - 1 ; i >= 0 ; i--){
		// cout << i << sep << res[i] << endl;
		ans = min(ans , ans ^ res[i]);
	}
	cout << ans << endl;

	return 0;
}
/*

*/