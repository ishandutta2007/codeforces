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
 
const int xn = 2e5 + 10;
const int xm = - 20 + 10;
const int sq = 320;
const int inf = 1e9 + 10;
const ll INF = 1e18 + 10;
const int mod = 998244353;
const int base = 257;
 
int n, m, a[xn], col[xn], ptr;
vector <int> adj[2][xn], vec[xn], topo;
bool mark[xn];

void add(int v, int u){
	adj[0][v].push_back(u);
	adj[1][u].push_back(v);
}
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
	for (int u : adj[1][v])
		if (!mark[u])
			SFD(u, c);
}

int main(){
	InTheNameOfGod;
	
	cin >> n >> m;
	for (int i = 1; i <= n; ++ i)
		cin >> a[i];
	for (int i = 1; i <= m; ++ i){
		int sz;
		cin >> sz;
		while (sz --){
			int x;
			cin >> x;
			vec[x].push_back(i);
		}
	}
	for (int i = 1; i <= n; ++ i){
		int x = vec[i][0], y = vec[i][1];
		if (a[i]){
			add(x + x, y + y);
			add(y + y, x + x);
			add(x + x + 1, y + y + 1);
			add(y + y + 1, x + x + 1);
		}
		else{
			add(x + x, y + y + 1);
			add(y + y + 1, x + x);
			add(x + x + 1, y + y);
			add(y + y, x + x + 1);
		}
	}
	for (int i = 2; i <= m + m + 1; ++ i)
		if (!mark[i])
			DFS(i);
	memset(mark, false, sizeof mark);
	reverse(all(topo));
	for (int v : topo)
		if (!mark[v])
			SFD(v, ptr ++);
	for (int i = 1; i <= m; ++ i)
		if (col[i + i] == col[i + i + 1])
			kill("NO");
	kill("YES");
	
	return 0;
}