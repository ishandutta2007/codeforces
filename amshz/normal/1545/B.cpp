//khodaya khodet komak kon
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
# define fast_io                                         ios::sync_with_stdio(0);cin.tie(0); cout.tie(0);

ll power(ll a, ll b, ll md) {return (!b ? 1 : (b & 1 ? a * power(a * a % md, b / 2, md) % md : power(a * a % md, b / 2, md) % md));}

const int xn = 1e5 + 10;
const int xm = - 20 + 10;
const int sq = 320;
const int inf = 1e9 + 10;
const ll INF = 1e18 + 10;
const ld eps = 1e-15;
const int mod = 998244353;
const int base = 257;

int qq, n, fact[xn], ifact[xn], sum, res, cnt;
string S;

int C(int n, int r){
	if (r < 0 || n < 0 || n - r < 0)
		return 0;
	return 1ll * fact[n] * ifact[r] % mod * ifact[n - r] % mod;
}

int main(){
	fast_io;

	fact[0] = 1;
	for (int i = 1; i < xn; ++ i)
		fact[i] = 1ll * fact[i - 1] * i % mod;
	ifact[xn - 1] = power(fact[xn - 1], mod - 2, mod);
	for (int i = xn - 2; i >= 0; -- i)
		ifact[i] = 1ll * ifact[i + 1] * (i + 1) % mod;
	cin >> qq;
	while (qq --){
		cin >> n >> S, sum = cnt = res = 0;
		for (char c : S){
			if (c == '1')
				++ sum, ++ res;
			else
				cnt += res % 2, res = 0;
		}
		cnt += res % 2;
		cout << C(n - cnt - (sum - cnt) / 2, n - sum) << endl;
	}

	return 0;
}