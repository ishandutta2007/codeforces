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

const int xn = 3e5 + 10;
const int xm = - 20 + 10;
const int sq = 320;
const int inf = 1e9 + 10;
const ll INF = 1e18 + 10;
const int mod = 998244353;
const int base = 257;

int n, m, ptr, col[xn], res, a[xn], ans;
pii E[xn];
vector <int> adj[2][xn], G[2][xn], vec[xn], topo;
bool mark[xn], flag[xn];

void DFS(int v){
	mark[v] = true;
	for (int u : adj[0][v])
		if (!mark[u])
			DFS(u);
	topo.push_back(v);
}
void SFD(int v, int c){
	mark[v] = true;
	col[v] = c;
	vec[c].push_back(v);
	for (int u : adj[1][v])
		if (!mark[u])
			SFD(u, c);
}

int main(){
	InTheNameOfGod;

	cin >> n >> m;
	for (int i = 1; i <= m; ++ i){
		int v, u;
		cin >> v >> u;
		adj[0][v].push_back(u);
		adj[1][u].push_back(v);
		E[i] = {v, u};
	}
	for (int i = 1; i <= n; ++ i)
		if (!mark[i])
			DFS(i);
	reverse(all(topo));
	memset(mark, false, sizeof mark);
	for (int v : topo)
		if (!mark[v])
			SFD(v, ++ ptr);
	for (int i = 1; i <= m; ++ i){
		int v = E[i].A, u = E[i].B;
		if (col[v] == col[u])
			continue;
		G[0][col[v]].push_back(col[u]);
		G[1][col[u]].push_back(col[v]);
	}
	memset(mark, false, sizeof mark);
	for (int v = 1; v <= ptr; ++ v){
		for (int u : G[1][v]){
			if (mark[u])
				continue;
			mark[u] = true;
			for (int w : G[1][u]){
				res -= 1 - flag[w];
				flag[w] = true;
				res += 1 - flag[w];
			}
		}
		for (int u : G[1][v])
			res -= 1 - flag[u];
		a[v] += res;
		for (int u : G[1][v])
			res += 1 - flag[u];
		res += 1;
	}
	memset(mark, false, sizeof mark);
	memset(flag, false, sizeof flag);
	res = 0;
	for (int v = ptr; v >= 1; -- v){
		for (int u : G[0][v]){
			if (mark[u])
				continue;
			mark[u] = true;
			for (int w : G[0][u]){
				res -= 1 - flag[w];
				flag[w] = true;
				res += 1 - flag[w];
			}
		}
		for (int u : G[0][v])
			res -= 1 - flag[u];
		a[v] += res;
		for (int u : G[0][v])
			res += 1 - flag[u];
		if (a[v] < 2)
			ans += SZ(vec[v]);
		res += 1;
	}
	cout << ans << endl;

	return 0;
}