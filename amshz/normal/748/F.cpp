// khodaya khodet komak kon
# include <bits/stdc++.h>
 
/*
// ordered_set 
# include <ext/pb_ds/assoc_container.hpp>
# include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
# define ordered_set tree<int, null_type,less<int>, rb_tree_tag,tree_order_statistics_node_update> 
*/
 
using namespace std;
 
typedef long long                                        ll;
typedef long double                                      ld;
typedef pair <int, int>                                  pii;
typedef pair <ll, ll>                                    pll;
typedef pair <pii, int>                                  ppi;
typedef pair <pll, ll >                                  ppl;
typedef pair <int, pii>                                  pip;
typedef pair <ll , pll>                                  plp;
typedef pair <pii, pii>                                  ppp;
typedef pair <pll, pll>                                  PPP;
 
# define A                                               first
# define B                                               second
# define endl                                            '\n'
# define sep                                             ' '
# define all(x)                                          x.begin(), x.end()
# define kill(x)                                         return cout << x << endl, 0
# define SZ(x)                                           int(x.size())
# define lc                                              id << 1
# define rc                                              id << 1 | 1
# define InTheNameOfGod                                  ios::sync_with_stdio(0);cin.tie(0); cout.tie(0);
 
ll power(ll a, ll b, ll md) {return (!b ? 1 : (b & 1 ? a * power(a * a % md, b / 2, md) % md : power(a * a % md, b / 2, md) % md));}
 
const int xn = 2e5 + 10;
const int xm = - 20 + 10;
const int sq = 320;
const int inf = 1e9 + 10;
const ll INF = 1e18 + 10;
const ll mod = 1e9 + 7;//998244353;
const int base = 257;

int n, k, a[xn], stm[xn], sz[xn], root, ptr;
vector <int> adj[xn];
bool flag[xn];

void plant(int v, int p = - 1){
	sz[v] = flag[v];
	for (int u : adj[v])
		if (u != p)
			plant(u, v), sz[v] += sz[u];
}
int find_centroid(int v, int p = - 1){
	for (int u : adj[v])
		if (u != p && sz[u] > k)
			return find_centroid(u, v);
	return v;
}
void DFS(int v, int p = - 1){
	stm[v] = ptr ++;
	for (int u : adj[v])
		if (u != p)
			DFS(u, v);
}
bool cmp(int v, int u){ return stm[v] < stm[u];}

int main(){
	InTheNameOfGod;
	
	cin >> n >> k;
	for (int i = 0; i < n - 1; ++ i){
		int v, u;
		cin >> v >> u;
		adj[v].push_back(u);
		adj[u].push_back(v);
	}
	for (int i = 0; i < k + k; ++ i)
		cin >> a[i], flag[a[i]] = true;
	plant(1);
	root = find_centroid(1);
	DFS(1);
	sort(a, a + k + k, cmp);
	cout << 1 << endl << root << endl;
	for (int i = 0; i < k; ++ i)
		cout << a[i] << sep << a[i + k] << sep << root << endl;
	
	return 0;
}