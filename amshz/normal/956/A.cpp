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
 
const int xn = 1e2 + 10;
const int xm = - 20 + 10;
const int sq = 320;
const int inf = 1e9 + 10;
const ll INF = 1e18 + 10;
const int mod = 998244353;
const int base = 257;

int n, m, cnt[3], d[xn];
string s[xn];
vector <int> adj[xn];
bool flag, mark[xn];

void DFS(int v){
	mark[v] = true;
	if (v <= n)
		++ cnt[0];
	else
		++ cnt[1];
	cnt[2] += d[v];
	for (int u : adj[v])	
		if (!mark[u])
			DFS(u);
}

int main(){
	InTheNameOfGod;
	
	cin >> n >> m;
	for (int i = 1; i <= n; ++ i){
		cin >> s[i], s[i] = '.' + s[i];
		for (int j = 1; j <= m; ++ j){
			if (s[i][j] == '#'){
				adj[i].push_back(j + n);
				adj[j + n].push_back(i);
				++ d[i], ++ d[j + n];
			}
		}
	}
	for (int i = 1; i <= n; ++ i){
		if (mark[i])
			continue;
		cnt[0] = cnt[1] = cnt[2] = 0;
		DFS(i);
		flag |= (cnt[0] * cnt[1] * 2 != cnt[2]);
	}
	if (flag)
		cout << "No" << endl;
	else
		cout << "Yes" << endl;
			
	return 0;
}