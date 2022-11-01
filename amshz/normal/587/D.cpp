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
const int xm = - 20 + 10;
const int SQ = 450;
const int inf = 1e9 + 10;
const ll INF = 1e18 + 10;
const int mod = 998244353;
const int base = 257;

int n, m, ptr, tohi, col[xn], a[xn], cnt;
vector <pii> adj[xn];
stack <pii> st;
vector <int> ans, topo, G[2][xn], part[xn];
bool mark[xn];

void add(int v, int u){
	G[0][v].push_back(u);
	G[1][u].push_back(v);
	G[0][u ^ 1].push_back(v ^ 1);
	G[1][v ^ 1].push_back(u ^ 1);
	st.push({v, u});
}
void DFS(int v){
	mark[v] = true;
	for (int u : G[0][v])
		if (!mark[u])
			DFS(u);
	topo.push_back(v);
}
void SFD(int v, int c){
	mark[v] = true;
	col[v] = c;
	for (int u : G[1][v])
		if (!mark[u])
			SFD(u, c);
}
bool check(int x){
	while (SZ(st)){
		int v = st.top().A, u = st.top().B;
		st.pop();
		G[1][v ^ 1].pop_back();
		G[0][u ^ 1].pop_back();
		G[1][u].pop_back();
		G[0][v].pop_back();
	}
	for (int i = 1; i <= n; ++ i)
		for (pii u : adj[i])
			if (a[u.B] > x)
				add(u.B << 1, u.B << 1 | 1);
	memset(mark, false, sizeof mark);
	topo.clear();
	for (int i = 2; i <= ptr + ptr + 1; ++ i)
		if (!mark[i])
			DFS(i);
	reverse(all(topo));
	memset(mark, false, sizeof mark);
	cnt = 0;
	for (int i : topo)
		if (!mark[i])
			SFD(i, cnt ++);
	for (int i = 1; i <= ptr; ++ i)
		if (col[i << 1] == col[i << 1 | 1])
			return false;
	return true;
}

int main(){
	InTheNameOfGod;
	
	cin >> n >> m;
	ptr = m;
	for (int i = 1; i <= m; ++ i){
		int v, u, t, c;
		cin >> v >> u >> c >> t;
		a[i] = t;
		adj[v].push_back({c, i});
		adj[u].push_back({c, i});
		part[v].push_back(++ ptr);
		part[u].push_back(++ ptr);
	}
	for (int i = 1; i <= n; ++ i){
		sort(all(adj[i]));
		int ind = 0, ted = 0;
		for (int j = 0; j < SZ(adj[i]); ++ j){
			add(part[i][j] << 1, adj[i][j].B << 1 | 1);
			if (j){
				add(part[i][j] << 1, part[i][j - 1] << 1);
				add(adj[i][j].B << 1, part[i][j - 1] << 1);
				if (adj[i][j].A == adj[i][j - 1].A)
					++ ted, ind = j;
			}
		}
		if (ted > 1)
			kill("No");
		if (ind){
			add(adj[i][ind - 1].B << 1 | 1, adj[i][ind].B << 1);
			add(adj[i][ind - 1].B << 1, adj[i][ind].B << 1 | 1);
		}
	}
	while (SZ(st))
		st.pop();
	int l = - 1, r = inf;
	while (r - l > 1){
		int mid = l + r >> 1;
		if (check(mid))
			r = mid;
		else
			l = mid;
	}
	if (r == inf)
		kill("No");
	check(r);
	cout << "Yes" << endl;
	for (int i = 1; i <= m; ++ i)
		if (col[i << 1] > col[i << 1 | 1])
			ans.push_back(i);
	cout << r << sep << SZ(ans) << endl;
	for (int x : ans)
		cout << x << sep;
	cout << endl;
	
	return 0;
}