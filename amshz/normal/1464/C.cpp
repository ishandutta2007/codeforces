// khodaya khodet komak kon
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
typedef pair <ll, ll>                                    pll;
typedef pair <pii, int>                                  ppi;
typedef pair <pll, ll >                                  ppl;
typedef pair <int, pii>                                  pip;
typedef pair <ll , pll>                                  plp;
typedef pair <pii, pii>                                  ppp;
typedef pair <pll, pll>                                  PPP;
 
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
const int xm = - 20 + 10;
const int sq = 320;
const int inf = 1e9 + 10;
const ll INF = 1e18 + 10;
const int mod = 998244353;
const int base = 257;

ll n, T, cnt[xn];
string s;

int main(){
	InTheNameOfGod;
	
	cin >> n >> T >> s;
	s = '.' + s;
	for (int i = 1; i <= n; ++ i)
		T += (1LL << (s[i] - 'a'));
	T -= (1LL << (s[n] - 'a' + 1));
	if (T < 0)
		kill("No");
	for (int i = 1; i < n - 1; ++ i)
		++ cnt[s[i] - 'a' + 1];
	for (ll bit = 0; bit < 60; ++ bit){
		if (!(T & (1LL << bit))){
			while (cnt[bit] > 1)
				cnt[bit] -= 2, ++ cnt[bit + 1];
		}
		else{
			if (!cnt[bit])
				kill("No");
			while (cnt[bit] > 2){
				cnt[bit] -= 2, ++ cnt[bit + 1];
			}
		}
	}
	kill("Yes");
	
	return 0;
}