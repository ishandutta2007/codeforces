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
 
const int xn = 2e5 + 10;
const int xm = 1e7 + 10;
const int sq = 320;
const int inf = 1e9 + 10;
const ll INF = 1e18 + 10;
const int mod = 998244353;
const int base = 257;

ll n, k, a[xn], sum, part[xm], ptr, b[xm], res;

int main(){
	InTheNameOfGod;
	
	cin >> n >> k;
	for (int i = 1; i <= n; ++ i)
		cin >> a[i];
	sort(a + 1, a + n + 1);
	reverse(a + 1, a + n + 1);
	b[0] = 1;
	for (int i = 0; i + 2 < xm; ++ i){
		res += part[i], b[i] += res, sum += b[i];
		if (sum >= k)
			kill(i);
		if (sum + b[i + 1] + res + part[i + 1] >= k)
			kill(i + 1);
		while (b[i] && ptr < n){
			ll x = a[++ ptr] - 1;
			-- b[i], -- sum;
			part[i + 2] += 2;
			-- part[i + 2 + x / 2];
			-- part[i + 2 + (x + 1) / 2];
		}
	}
	kill(- 1);
	
	return 0;
}