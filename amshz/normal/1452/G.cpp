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
 
const int xn = 4e5 + 10;
const int xm = - 20 + 10;
const int sq = 320;
const int inf = 1e9 + 10;
const ll INF = 1e18 + 10;
const int mod = 998244353;
const int base = 257;

int n, k, c[xn], ans[xn], ptr, sz[xn];
ppi a[xn];
queue <int> q;
vector <int> adj[xn];
bool hide[xn];

void plant(int v, int p = - 1){
	sz[v] = 1;
	for (int u : adj[v])
		if (u != p && !hide[u])
			plant(u, v), sz[v] += sz[u];
}
int centroid(int v, int s, int p = - 1){
	for (int u : adj[v])
		if (u != p && !hide[u] && sz[u] + sz[u] > s)
			return centroid(u, s, v);
	return v;
}
void DFS(int v, int h = 0, int p = - 1){
	a[ptr ++] = {{h, 1}, v};
	a[ptr ++] = {{c[v] - h, 0}, c[v]};
	for (int u : adj[v])
		if (u != p && !hide[u])
			DFS(u, h + 1, v);
}
void solve(int v){
	plant(v);
	v = centroid(v, sz[v]);
	hide[v] = true;
	ptr = 0, DFS(v);
	sort(a, a + ptr);
	int res = 0;
	for (int i = ptr - 1; i >= 0; -- i){
		if (a[i].A.B == 1)
			ans[a[i].B] = max(ans[a[i].B], res);
		else
			res = max(res, a[i].B);
	}
	for (int u : adj[v])
		if (!hide[u])
			solve(u);
}

int main(){
	InTheNameOfGod;
	
	cin >> n;
	for (int i = 0; i < n - 1; ++ i){
		int v, u;
		cin >> v >> u;
		adj[v].push_back(u);
		adj[u].push_back(v);
	}
	for (int i = 1; i <= n; ++ i)
		c[i] = n - 1;
	cin >> k;
	while (k --){
		int x;
		cin >> x;
		c[x] = 0;
		q.push(x);
	}
	while (SZ(q)){
		int v = q.front();
		q.pop();
		for (int u : adj[v]){
			if (c[v] + 1 < c[u]){
				c[u] = c[v] + 1;
				q.push(u);
			}
		}
	}
	solve(1);
	for (int i = 1; i <= n; ++ i)
		cout << ans[i] << sep;
	cout << endl;
			
	return 0;
}