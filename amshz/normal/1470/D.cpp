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
const int mod = 1e9 + 7;//998244353;
const int base = 257;

int n, m, qq, ted;
vector <int> adj[xn], vec, ans;
bool mark[xn], flag;

void DFS(int v){
	mark[v] = true;
	vec.push_back(v);
	for (int u : adj[v])
		if (!mark[u])
			DFS(u);
}

int main(){
	InTheNameOfGod;
	
	cin >> qq;
	while (qq --){
		cin >> n >> m;
		for (int i = 1; i <= n; ++ i)
			adj[i].clear(), mark[i] = false;
		while (m --){
			int v, u;
			cin >> v >> u;
			adj[v].push_back(u);
			adj[u].push_back(v);
		}
		vec.clear(), DFS(1), flag = false;
		for (int i = 1; i <= n; ++ i)
			flag |= !mark[i];
		if (flag){
			cout << "NO" << endl;
			continue;
		}
		cout << "YES" << endl;
		for (int i = 1; i <= n; ++ i)
			mark[i] = false;
		ans.clear();
		for (int v : vec){
			flag = true;
			for (int u : adj[v])
				flag &= !mark[u];
			if (flag)
				ans.push_back(v);
			mark[v] = flag;
		}
		cout << SZ(ans) << endl;
		for (int v : ans)
			cout << v << sep;
		cout << endl;
	}
	
	return 0;
}