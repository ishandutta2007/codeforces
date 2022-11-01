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
 
const int xn = 5e4 + 10;
const int xm = - 20 + 10;
const int sq = 320;
const int inf = 1e9 + 10;
const ll INF = 1e18 + 10;
const int mod = 998244353;
const int base = 257;

ll p, q, qq, ans;
vector <int> primes;
bool isp[xn];

int main(){
	InTheNameOfGod;
	
	for (int i = 2; i < xn; ++ i){
		if (isp[i]) continue;
		primes.push_back(i);
		for (int j = i + i; j < xn; j += i)
			isp[j] = true;
	}
	cin >> qq;
	while (qq --){
		cin >> p >> q;
		if (p % q){
			cout << p << endl;
			continue;
		}
		ans = 1;
		for (ll x : primes){
			ll t = 0;
			while (q % x == 0){
				q /= x;
				++ t;
			}
			if (!t) continue;
			ll t2 = 0, p2 = p;
			while (p2 % x == 0){
				p2 /= x;
				++ t2;
			}
			ll res = p;
			for (int i = 0; i < t2 - t + 1; ++ i)
				res /= x;
			ans = max(ans, res);
		}
		if (q > 1){
			ll res = p;
			while (res % q == 0)
				res /= q;
			ans = max(ans, res);
		}
		cout << ans << endl;
	}
			
	return 0;
}