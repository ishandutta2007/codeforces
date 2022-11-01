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

int n, m, k, d[xn], col[xn], ans;
pii last[10][10];
vector <int> vec;
vector <pii> adj[2][xn];
map <ppp, bool> mp;

bool CMP(pii i, pii j){ return i.B < j.B;}

void solve(int s, int t){
	if (t == k){
		vec.clear();
		while (s){
			vec.push_back(s % 10);
			s /= 10;
		}
		vec.push_back(0);
		reverse(all(vec));
		bool flag = true;
		for (int i = 1; i <= k; ++ i){
			for (int j = i; j <= k; ++ j){
				flag &= !(mp[{{i, vec[i]}, {j, vec[j]}}]);
			}
		}
		ans += flag;
		return;
	}
	for (int i = 1; i <= t + 1; ++ i) solve(s * 10 + i, t + 1);
}
 
int main(){
    InTheNameOfGod;
    
    cin >> n >> m >> k;
    for (int i = 0; i < m; ++ i){
    	int v, u, w;
    	cin >> v >> u >> w;
    	adj[0][v].push_back({u, w});
    	adj[1][u].push_back({v, w});
    	++ d[v];
	}
	for (int v = 1; v <= n; ++ v){
		sort(all(adj[0][v]), CMP);
		int ptr = 0;
		for (pii u : adj[0][v]) col[u.B] = ++ ptr;
	}
	int ptr = 1;
	for (int v = 1; v <= n; ++ v){
		for (pii u : adj[1][v]){
			if (last[d[u.A]][col[u.B]].A == ptr) mp[{{d[u.A], col[u.B]}, {d[u.A], col[u.B]}}] = true;
			last[d[u.A]][col[u.B]] = {ptr, 1};
		}
		for (int i = 1; i <= k; ++ i){
			for (int j = 1; j <= i; ++ j){
				for (int i2 = i + 1; i2 <= k; ++ i2){
					for (int j2 = 1; j2 <= i2; ++ j2){
						if (last[i][j].A != ptr) continue;
						if (last[i2][j2].A != ptr) continue;
						mp[{{i, j}, {i2, j2}}] = true;
						mp[{{i2, j2}, {i, j}}] = true;
					}
				}
			}
		}
		++ ptr;
	}
	solve(0, 0);
	cout << ans << endl;
	
    return 0;
}