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
# define lc                                              id << 1
# define rc                                              id << 1 | 1
# define all(x)                                          x.begin(), x.end()
# define kill(x)                                         return cout << x << endl, 0
# define SZ(x)                                           int(x.size())
# define InTheNameOfGod                                  ios::sync_with_stdio(0);cin.tie(0); cout.tie(0);
 
ll power(ll a, ll b, ll md) {return (!b ? 1 : (b & 1 ? a * power(a * a % md, b / 2, md) % md : power(a * a % md, b / 2, md) % md));}
 
const int xn = 3e5 + 10;
const int xm = - 20;
const int sq = 320;
const int inf = 1e9 + 10;
const ll INF = 1e18 + 10;
const int mod = 998244353;
const int base = 257;

int n, q, a[xn];
ll part[xn], ans[xn];
vector <pii> query[xn];
vector <int> vec[xn];
 
int main(){
	InTheNameOfGod;
	
	cin >> n;
	for (int i = 1; i <= n; ++ i)
		cin >> a[i];
	cin >> q;
	for (int i = 0; i < q; ++ i){
		int x, y;
		cin >> x >> y;
		if (y > sq)
			for (int j = x; j <= n; j += y)
				ans[i] += a[j];
		else
			query[y].push_back({x, i});
	}
	for (int i = 1; i <= sq; ++ i){
		for (int j = 1; j <= n; ++ j)
			vec[j].clear();
		for (pii x : query[i])
			vec[x.A].push_back(x.B);
		for (int j = n; j >= 1; -- j){
			part[j] = a[j];
			if (j + i <= n)
				part[j] += part[j + i];
			for (int x : vec[j])
				ans[x] = part[j];
		}
	}
	for (int i = 0; i < q; ++ i)
		cout << ans[i] << endl;
	
	return 0;
}