# include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>

using namespace std;
using namespace __gnu_pbds;
 
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
# define ordered_set                                     tree<pii, null_type, less<pii>, rb_tree_tag, tree_order_statistics_node_update>
# define InTheNameOfGod                                  ios::sync_with_stdio(0);cin.tie(0); cout.tie(0);
 
ll power(ll a, ll b, ll md) {return (!b ? 1 : (b & 1 ? a * power(a * a % md, b / 2, md) % md : power(a * a % md, b / 2, md) % md));}
 
const int xn = 1e5 + 10;
const int xm = - 20;
const int sq = 320;
const int inf = 1e9 + 10;
const ll INF = 1e18 + 10;
const int mod = 1e9 + 7;
const int base = 257;
 
int n, k;
ll ans;
pip a[xn];
map <int, ordered_set> st;

int main(){
	InTheNameOfGod;
	
	cin >> n >> k;
	for (int i = 1; i <= n; ++ i)
		cin >> a[i].B.A >> a[i].A >> a[i].B.B;
	sort(a + 1, a + n + 1);
	reverse(a + 1, a + n + 1);
	for (int i = 1; i <= n; ++ i){
		for (int j = a[i].B.B - k; j <= a[i].B.B + k; ++ j){
			if (st.find(j) == st.end())
				continue;
			pii r = {a[i].B.A + a[i].A, i};
			pii l = {a[i].B.A - a[i].A, 0};
			ans += st[j].order_of_key(r) - st[j].order_of_key(l);
		}
		st[a[i].B.B].insert({a[i].B.A, i});
	}
	cout << ans << endl;
	
	return 0;
}