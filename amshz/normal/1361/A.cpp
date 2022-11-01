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

const int xn = 5e5 + 10;
const int xm = -20 + 10;
const int SQ = 320;
const int sq = 320 + 10;
const int inf = 1e9 + 10;
const ll INF = 1e18 + 10;
const int MOD = 1e9 + 7;
const int TM = 3;
const int BASE = 257;

int n, m, num[xn], O[xn], cnt, last, ans[xn], ptr;
vector <int> adj[xn];
bool flag;

bool CMP(int v, int u){return num[v] < num[u];}

int main(){
    InTheNameOfGod;
    
    cin >> n >> m;
    for (int i = 0; i < m; ++ i){
    	int v, u;
    	cin >> v >> u;
    	adj[v].push_back(u);
    	adj[u].push_back(v);
	}
	for (int i = 1; i <= n; ++ i) cin >> num[i], O[i] = i;
	sort(O + 1, O + n + 1, CMP);
	for (int i = 1; i <= n; ++ i){
		int v = O[i];
		sort(all(adj[v]), CMP);
		cnt = 0;
		flag = true;
		last = 0;
		for (int u : adj[v]){
			flag &= (num[u] != num[v]);
			if (num[u] >= num[v]) break;
			flag &= (num[u] - last < 2);
			cnt += (num[u] - last);
			last = num[u];
		}
		flag &= (cnt == num[v] - 1);
		if (!flag) kill(-1);
		ans[++ ptr] = v;
	}
	for (int i = 1; i <= n; ++ i) cout << ans[i] << sep;
	cout << endl;
	
    return 0;
}