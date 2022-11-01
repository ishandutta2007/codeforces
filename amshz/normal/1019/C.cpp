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

const int xn = 1e6 + 10;
const int xm = - 20 + 10;
const int sq = 320;
const int inf = 1e9 + 10;
const ll INF = 1e18 + 10;
const int mod = 1e9 + 7;//998244353;
const int base = 257;

int n, m;
vector <int> adj[2][xn];
set <int> st, ans;
bool mark[xn];

void solve(){
	if (!SZ(st))
		return;
	int v = *st.begin();
	st.erase(v);
	for (int u : adj[0][v])
		st.erase(u);
	solve();
	for (int u : adj[1][v])
		if (mark[u])
			return;
	mark[v] = true;
	ans.insert(v);
}

int main(){
	InTheNameOfGod;
	
	cin >> n >> m;
	while (m --){
		int v, u;
		cin >> v >> u;
		adj[0][v].push_back(u);
		adj[1][u].push_back(v);
	}
	for (int i = 1; i <= n; ++ i)
		st.insert(i);
	solve();
	cout << SZ(ans) << endl;
	for (int v : ans)
		cout << v << sep;
	cout << endl;

	return 0;
}