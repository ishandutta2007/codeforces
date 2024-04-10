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
 
const int xn = 1e5 + 10;
const int xm = - 20;
const int sq = 320;
const int inf = 1e9 + 10;
const ll INF = 1e18 + 10;
const int mod = 1e9 + 7;//998244353;
const int base = 257;

int n, m, H[xn], part[2][xn], ted;
pii E[xn];
vector <pii> adj[xn];
bitset <xn> mark, inTree, ans;

void DFS4(int v, int id){
	mark[v] = 1;
	part[1][v] = part[0][v];
	for (pii u : adj[v]){
		if (mark[u.A])
			continue;
		DFS4(u.A, u.B);
		part[1][v] += part[1][u.A];
	}
	ans[id] = (part[1][v] == 1);
}
void DFS3(int v){
	mark[v] = 1;
	for (pii u : adj[v]){
		if (mark[u.A])
			continue;
		part[1][u.A] += part[1][v];
		DFS3(u.A);
	}
}
void DFS2(int v){
	mark[v] = 1;
	part[1][v] = part[0][v];
	for (pii u : adj[v]){
		if (mark[u.A])
			continue;
		DFS2(u.A);
		part[1][v] += part[1][u.A];
	}
}
void DFS(int v){
	mark[v] = 1;
	for (pii u : adj[v]){
		if (mark[u.A]){
			if (H[u.A] < H[v] - 1)
				++ part[0][v], -- part[0][u.A];
			continue;
		}
		H[u.A] = H[v] + 1;
		inTree[u.B] = 1;
		DFS(u.A);
	}
}

int main(){
	InTheNameOfGod;
	
	cin >> n >> m;
	for (int i = 1; i <= m; ++ i){
		int v, u;
		cin >> v >> u;
		adj[v].push_back({u, i});
		adj[u].push_back({v, i});
		E[i] = {v, u};
	}
	for (int i = 1; i <= n; ++ i){
		if (mark[i])
			continue;
		adj[0].push_back({i, 0});
		H[i] = 1, DFS(i);
	}
	mark.reset();
	DFS2(0);
	mark.reset();
	DFS3(0);
	ans.set();
	for (int i = 1; i <= m; ++ i){
		if (inTree[i])
			continue;
		int v = E[i].A, u = E[i].B;
		if (H[v] > H[u])
			swap(v, u);
		if (part[1][u] - part[1][v] > H[u] - H[v])
			++ part[0][u], -- part[0][v], ans[i] = 0;
	}
	mark.reset();
	DFS4(0, 0);
	for (int i = 1; i <= m; ++ i)
		ted += ans[i];
	cout << ted << endl;
	for (int i = 1; i <= m; ++ i)
		if (ans[i])
			cout << i << sep;
	cout << endl;
	
	return 0;
}