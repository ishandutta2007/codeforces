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
 
const int xn = 1e5 + 10;
const int xm = -20 + 10;
const int SQ = 500;
const int sq = 200 + 10;
const int inf = 1e9 + 10;
const ll INF = 1e18 + 10;
const int MOD = 1e9 + 7;
const int TM = 3;
const int BASE = 257;

int n, m, q, ind[xn], sz[xn];
ll num[xn], lazy[xn], share[sq][xn], ans[xn], res;
vector <int> vec[2], st[xn];
bool mark[xn];
 
int main(){
    InTheNameOfGod;
    
    cin >> n >> m >> q;
    for (int i = 1; i <= n; ++ i) cin >> num[i];
    for (int i = 1; i <= m; ++ i){
    	cin >> sz[i];
    	for (int j = 0; j < sz[i]; ++ j){
    		int x;
    		cin >> x;
    		st[i].push_back(x);
		}
		if (sz[i] > SQ){
			ind[i] = SZ(vec[0]);
			vec[0].push_back(i);
		}
		vec[1].push_back(i);
		for (int x : st[i]) ans[i] += num[x];
		if (sz[i] <= SQ) ans[i] = 0;
	}
	for (int x : vec[0]){
		memset(mark, false, sizeof mark);
		for (int y : st[x]) mark[y] = true;
		for (int y : vec[1]) for (int z : st[y]) share[ind[x]][y - 1] += mark[z];
	}
	while (q --){
		char c;
		cin >> c;
		if (c == '+'){
			int k;
			ll val;
			cin >> k >> val;
			if (sz[k] <= SQ){
				for (int x : st[k]) num[x] += val;
				for (int x : vec[0]) ans[x] += val * share[ind[x]][k - 1];
			}
			else lazy[ind[k]] += val;
		}
		else{
			int k;
			cin >> k;
			res = 0;
			for (int x : vec[0]) res += share[ind[x]][k - 1] * lazy[ind[x]];
			if (sz[k] <= SQ) for (int x : st[k]) res += num[x];
			cout << ans[k] + res << endl;
		}
	}
	
    return 0;
}