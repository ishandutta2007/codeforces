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
typedef pair <pii, int>                                  ppi;
typedef pair <int, pii>                                  pip;
typedef pair <pii, pii>                                  ppp;
typedef pair <ll, ll>                                    pll;
 
# define A                                               first
# define B                                               second
# define endl                                            '\n'
# define sep                                             ' '
# define all(x)                                          x.begin(), x.end()
# define kill(x)                                         return cout << x << endl, 0
# define SZ(x)                                           int(x.size())
# define InTheNameOfGod                                  ios::sync_with_stdio(0);cin.tie(0); cout.tie(0);
 
ll power(ll a, ll b, ll md) {return (!b ? 1 : (b & 1 ? a * power(a * a % md, b / 2, md) % md : power(a * a % md, b / 2, md) % md));}
 
const int xn = 1e5 + 10;
const int xm = - 20;
const int sq = 320;
const int inf = 1e9 + 10;
const ll INF = 1e18 + 10;
const int mod = 1e9 + 7;
const int base = 257;

ll n, k, p, a[xn], ans, pt1, pt2, part[xn];
vector <int> adj[xn];

void DFS(int v, int par){
	for (int u : adj[v]){
		if (u == par)
			continue;
		a[u] = a[v] + 1;
		DFS(u, v);
	}
}
ll check(int l, int r){ return a[r] * (r - l) - (part[r - 1] - part[l - 1]);}

int main(){
	InTheNameOfGod;
	
	cin >> n >> k >> p;
	for (int i = 0; i < n - 1; ++ i){
		int v, u;
		cin >> v >> u;
		adj[v].push_back(u);
		adj[u].push_back(v);
	}
	DFS(1, - 1);
	sort(a + 2, a + n + 1);
	for (int i = 1; i <= n; ++ i)
		part[i] = part[i - 1] + a[i];
	pt1 = pt2 = 2;
	while (pt1 <= n){
		while (pt2 < n && pt2 - pt1 + 2 <= k && check(pt1, pt2 + 1) <= p) ++ pt2;
		ans = max(ans, pt2 - pt1 + 1);
		++ pt1;
	}
	cout << ans << endl;
	
	return 0;
}