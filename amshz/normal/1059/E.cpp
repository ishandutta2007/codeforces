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
# define InTheNameOfGod                                  ios::sync_with_stdio(0);cin.tie(0); cout.tie(0);
 
ll power(ll a, ll b, ll md) {return (!b ? 1 : (b & 1 ? a * power(a * a % md, b / 2, md) % md : power(a * a % md, b / 2, md) % md));}
 
const int xn = 1e5 + 10;
const int xm = 10 + 10;
const int sq = 320;
const int inf = 1e9 + 10;
const ll INF = 1e18 + 10;
const int mod = 998244353;
const int base = 257;

int n, L, par[xm][xn], H[xn], l;
ll S, w[xm][xn], res, s;
vector <int> adj[xn];

pii DFS(int v){
	for (int i = 1; i < xm; ++ i){
		par[i][v] = par[i - 1][par[i - 1][v]];
		w[i][v] = w[i - 1][v] + w[i - 1][par[i - 1][v]];
	}
	s = S, l = L;
	int res = v;
	for (int i = xm - 1; i >= 0; -- i){
		if (w[i][res] > s || (1 << i) > l)
			continue;
		l -= (1 << i);
		s -= w[i][res];
		res = par[i][res];
	}
	pii x = {H[v], 0};
	for (int u : adj[v]){
		H[u] = H[v] + 1;
		pii y = DFS(u);
		x.B += y.B;
		x.A = min(x.A, y.A);
	}
	if (x.A < H[v])
		return x;
	++ x.B;
	x.A = H[res];
	return x;
}

int main(){
	InTheNameOfGod;
	
	cin >> n >> L >> S;
	for (int i = 1; i <= n; ++ i)
		cin >> w[0][i];
	for (int i = 2; i <= n; ++ i){
		cin >> par[0][i];
		adj[par[0][i]].push_back(i);
	}
	for (int i = 1; i <= n; ++ i)
		if (w[0][i] > S)
			kill(- 1);
	H[1] = 1;
	cout << DFS(1).B << endl;
	
	return 0;
}