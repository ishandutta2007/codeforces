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
const int xm = - 20 + 10;
const int sq = 320;
const int inf = 1e9 + 10;
const ll INF = 1e18 + 10;
const int mod = 998244353;
const int base = 257;

int n, m, f[xn], dp[2][xn], ptr, st[xn], ft[xn];
vector <int> adj[xn];
string s, t;

void DFS(int v){
	st[v] = ptr ++;
	for (int u : adj[v])
		DFS(u);
	ft[v] = ptr ++;
}

int main(){
	InTheNameOfGod;
	
	cin >> s >> t;
	n = SZ(s), m = SZ(t);
	s = '.' + s;
	adj[0].push_back(1);
	for (int i = 1; i < m; ++ i){
		while (ptr && t[ptr] != t[i]) ptr = f[ptr];
		if (t[ptr] == t[i]) ++ ptr;
		f[i + 1] = ptr;
		adj[ptr].push_back(i + 1);
	}
	DFS(0);
	for (int i = 1; i <= n; ++ i){
		dp[0][i] = dp[0][i - 1];
		dp[1][i] = - inf;
		if (i < m)
			continue;
		bool flag = true;
		for (int j = 1; j <= m; ++ j)
			flag &= (s[i - m + j] == '?' || s[i - m + j] == t[j - 1]);
		if (!flag)
			continue;
		dp[1][i] = dp[0][i - m] + 1;
		for (int j = 1; j < m; ++ j)
			if (st[j] <= st[m] && ft[m] <= ft[j])
				dp[1][i] = max(dp[1][i], dp[1][i - m + j] + 1);
		dp[0][i] = max(dp[0][i], dp[1][i]);
	}
	cout << dp[0][n] << endl;
	
	return 0;
}