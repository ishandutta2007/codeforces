//khodaya khodet komak kon
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
# define lc                                              id << 1
# define rc                                              id << 1 | 1
# define InTheNameOfGod                                  ios::sync_with_stdio(0);cin.tie(0); cout.tie(0);
 
ll power(ll a, ll b, ll md) {return (!b ? 1 : (b & 1 ? a * power(a * a % md, b / 2, md) % md : power(a * a % md, b / 2, md) % md));}
 
const int xn = 5e5 + 10;
const int xm = 22;
const int sq = 320;
const int inf = 1e9 + 10;
const ll INF = 1e18 + 10;
const int mod = 998244353;
const int base = 257;

int n, c[xn], f[1 << xm], ans[xn], sz[xn];
int H[xn], arshad[xn];
vector <pii> adj[xn];
vector <int> vec;

void preDFS(int v){
	sz[v] = 1;
	for (pii u : adj[v]){
		H[u.A] = H[v] + 1;
		c[u.A] = (c[v] ^ u.B);
		preDFS(u.A);
		if (sz[u.A] > sz[arshad[v]])
			arshad[v] = u.A;
		sz[v] += sz[u.A];
	}
}
void solve(int v, int fl, int root = 0){
	if (fl == 1)
		f[c[v]] = max(f[c[v]], H[v]);
	else if (fl == 2)
		f[c[v]] = 0;
	else
		for (int x : vec)
			ans[root] = max(ans[root], f[c[v] ^ x] + H[v] - 2 * H[root]);
	for (pii u : adj[v])
		solve(u.A, fl, root);
}
void DFS(int v){
	if (!SZ(adj[v])){
		f[c[v]] = max(f[c[v]], H[v]);
		return;
	}
	for (pii u : adj[v]){
		if (u.A == arshad[v])
			continue;
		DFS(u.A);
		solve(u.A, 2);
		ans[v] = max(ans[v], ans[u.A]);
	}
	DFS(arshad[v]);
	ans[v] = max(ans[v], ans[arshad[v]]);
	for (int x : vec)
		ans[v] = max(ans[v], f[c[v] ^ x] - H[v]);
	f[c[v]] = max(f[c[v]], H[v]);
	for (pii u : adj[v]){
		if (u.A == arshad[v])
			continue;
		solve(u.A, 3, v);
		solve(u.A, 1);
	}
}

int main(){
	InTheNameOfGod;
	
	cin >> n;
	for (int i = 2; i <= n; ++ i){
		int p;
		char c;
		cin >> p >> c;
		adj[p].push_back({i, 1 << (c - 'a')});
	}
	vec.push_back(0);
	for (int i = 0; i < xm; ++ i)
		vec.push_back((1 << i));
	H[1] = n, preDFS(1), DFS(1);
	for (int i = 1; i <= n; ++ i)
		cout << ans[i] << sep;
	cout << endl;
	
	return 0;
}