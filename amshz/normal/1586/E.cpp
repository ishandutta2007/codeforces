//khodaya khodet komak kon
# include <bits/stdc++.h>
 
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
# define fast_io                                         ios::sync_with_stdio(0);cin.tie(0); cout.tie(0);
 
ll power(ll a, ll b, ll md) {return (!b ? 1 : (b & 1 ? a * power(a * a % md, b / 2, md) % md : power(a * a % md, b / 2, md) % md));}
 
const int xn = 3e5 + 10;
const int xm = - 20 + 10;
const int sq = 320;
const int inf = 1e9 + 10;
const ll INF = 1e18 + 10;
const ld eps = 1e-15;
const int mod = 1e9 + 7;//998244353;
const int base = 257;
 
int n, m, q, par[xn], H[xn], ans, a[xn];
vector <int> adj[xn];
bool f[xn], mark[xn], fl[xn];
vector <int> vec[2][xn];
 
void preDFS(int v){
	mark[v] = true;
	for (int u : adj[v]){
		if (mark[u])
			continue;
		par[u] = v;
		H[u] = H[v] + 1;
		preDFS(u);
	}
}
void DFS(int v){
	mark[v] = true;
	for (int u : adj[v]){
		if (mark[u])
			continue;
		DFS(u), fl[v] ^= fl[u];
		if (fl[u] ^ f[u])
			++ ans, fl[v] ^= 1;
	}
}
 
int main(){
	fast_io;
 
	cin >> n >> m;
	while (m --){
		int v, u;
		cin >> v >> u;
		adj[v].push_back(u);
		adj[u].push_back(v);
	}
	preDFS(1);
	cin >> q;
	for (int i = 1; i <= q; ++ i){
		int v, u;
		cin >> v >> u;
		a[i] = v;
		if (H[u] < H[v])
			swap(v, u);
		while (H[v] < H[u]){
			vec[1][i].push_back(u);
			f[u] ^= 1, u = par[u];
		}
		while (v != u){
			vec[0][i].push_back(v);
			vec[1][i].push_back(u);
			f[v] ^= 1, f[u] ^= 1;
			v = par[v], u = par[u];
		}
		vec[0][i].push_back(v);
	}
	memset(mark, false, sizeof mark);
	DFS(1);
	ans = (ans + 1) / 2;
	if (ans)
		cout << "NO" << endl << ans << endl;
	else{
		cout << "YES" << endl;
		for (int i = 1; i <= q; ++ i){
			reverse(all(vec[1][i]));
			for (int v : vec[1][i])
				vec[0][i].push_back(v);
			if (a[i] != vec[0][i][0])
				reverse(all(vec[0][i]));
			cout << SZ(vec[0][i]) << endl;
			for (int v : vec[0][i])
				cout << v << sep;
			cout << endl;
		}
	}
 
	return 0;
}