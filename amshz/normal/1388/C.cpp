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
# define Sort(x)                                         sort(all(x))
# define InTheNameOfGod                                  ios::sync_with_stdio(0);cin.tie(0); cout.tie(0);
 
ll power(ll a, ll b, ll md) {return (!b ? 1 : (b & 1 ? a * power(a * a % md, b / 2, md) % md : power(a * a % md, b / 2, md) % md));}
 
const int xn = 2e5 + 10;
const int xm = -20 + 10;
const int SQ = 320;
const int sq = 320 + 10;
const int inf = 1e9 + 10;
const ll INF = 1e18 + 10;
const int MOD = 1e9 + 7;
const int TM = 3;
const int BASE = 257;

ll n, m, p[xn], qq, h[xn], sum[xn], s[xn];
vector <int> adj[xn];
bool mark[xn], flag;

void DFS(int v){
	sum[v] = 0;
	mark[v] = true;
	for (int u : adj[v]){
		if (mark[u]) continue;
		DFS(u);
		p[v] += sum[u];
		s[v] += s[u];
	}
	h[v] -= s[v];
	flag &= ((p[v] + h[v]) % 2 == 0);
	flag &= ((p[v] + h[v]) / 2 <= p[v]);
	flag &= ((p[v] + h[v]) / 2 >= 0);
	s[v] += (p[v] + h[v]) / 2;
	sum[v] += p[v] - (p[v] + h[v]) / 2;
}
 
int main(){
    InTheNameOfGod;
    
    cin >> qq;
    while (qq --){
    	cin >> n >> m;
    	for (int i = 1; i <= n; ++ i) adj[i].clear();
    	for (int i = 1; i <= n; ++ i) cin >> p[i], s[i] = 0;
    	for (int i = 1; i <= n; ++ i) cin >> h[i];
    	for (int i = 0; i < n - 1; ++ i){
    		int v, u;
    		cin >> v >> u;
    		adj[v].push_back(u);
    		adj[u].push_back(v);
		}
    	for (int i = 1; i <= n; ++ i) mark[i] = false;
    	flag = true;
    	DFS(1);
    	if (flag) cout << "YES" << endl;
    	else cout << "NO" << endl;
	}
	
    return 0;
}