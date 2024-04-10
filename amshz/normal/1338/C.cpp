# include <bits/stdc++.h>
 
using namespace std;

/*
// ordered_set 
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
#define ordered_set tree<int, null_type,less<int>, rb_tree_tag,tree_order_statistics_node_update> 
*/
 
typedef long long          ll;
typedef long double        ld;
typedef pair <int, int>    pii;
typedef pair <pii, int>    ppi;
typedef pair <pii, pii>    pip;
 
# define A                                first
# define B                                second
# define endl                             '\n'
# define sep                              ' '
# define all(x)                           x.begin(), x.end()
# define Kill(x)                          return cout << x << endl, 0
# define SZ(x)                            int(x.size())
# define InTheNameOfGod                   ios::sync_with_stdio(0);cin.tie(0); cout.tie(0);
 
const ll md = 998244353;
const int xn = 1e5 + 10;
const int xm = -20 + 10;
const int SQ = 450;
const int sq = 1e3 + 10;
const int inf = 1e9 + 10;
const ll INF = 1e18 + 10;

ll power(ll a, ll b) {return (!b ? 1 : (b & 1 ? a * power(a * a % md, b / 2) % md : power(a * a % md, b / 2) % md));}
ll zarb(ll a, ll b){return (a * b + 10 * md) % md;}
ll jaam(ll a, ll b){return (a + b + 10 * md) % md;}
string abc = "abcdefghijklmnopqrstuvwxyz";

ll n, qq, k, ind, sum, m = 0;

int main(){
	//InTheNameOfGod;
	
	cin >> qq;
	while (qq --){
		cin >> n;
		//n = ++ m;
		n --;
		ind = n / 3 + 1;
		sum = 0;
		k = 0;
		while (true){
			sum += (1LL << (2 * k));
			if (ind <= sum) break;
			++ k;
		}
		sum -= (1LL << (2 * k));
		ll a = ind - sum - 1 + (1LL << (2 * k));
		ll last = (1LL << (k + k + 1));
		ll dx = (ind - sum - 1) / 4;
		ll x = (ind - sum - 1);
		ll b = last;
		ll kk = 0;
		while (x){
			ll t = x % 4;
			if (t % 4 < 3 && t % 4) ++ t;
			else if (t % 4) t -= 2;
			b += t * (1LL << (2 * kk));
			++ kk;
			x /= 4;
		}
		ll c = a^b;
		if (n % 3 == 0) cout << a << endl;
		else if (n % 3 == 1) cout << b << endl;
		else cout << c << endl;
	}
	
	return 0;
}