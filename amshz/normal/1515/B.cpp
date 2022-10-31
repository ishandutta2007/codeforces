// khodaya khodet komak kon
// Toxicity
# include <bits/stdc++.h>

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

const int xn = - 20 + 10;
const int xm = - 20 + 10;
const int sq = 320;
const int inf = 1e9 + 10;
const ll INF = 1e18 + 10;
const int mod = 998244353;
const int base = 257;

ll qq, n;

bool check(ll x){
	ll l = 1, r = 1e5;
	while (r - l > 1){
		ll mid = l + r >> 1;
		if (mid * mid <= x)
			l = mid;
		else
			r = mid;
	}
	return l * l == x;
}

int main(){
	InTheNameOfGod;

	cin >> qq;
	while (qq --){
		cin >> n;
		if ((n % 2 == 0 && check(n / 2)) || (n % 4 == 0 && check(n / 4)))
			cout << "YES" << endl;
		else
			cout << "NO" << endl;
	}

	return 0;
}