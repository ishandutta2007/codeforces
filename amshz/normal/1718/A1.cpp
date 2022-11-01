// khodaya khodet komak kon
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

int power(int a, ll b, int md){
	int res = 1;
	while (b){
		if ((b & 1))
			res = 1ll * res * a % md;
		a = 1ll * a * a % md;
		b >>= 1;
	}
	return res;
}
 
const int xn = 1e5 + 10;
const int xm = - 20 + 10;
const int sq = 320;
const int inf = 1e9 + 10;
const ll INF = 1e18 + 10;
const ld eps = 1e-15;
const int mod = 998244353;
const int base = 257;

int qq, n, a[xn], res, ans, dp[xn];
map <int, int> mp;

int main(){
	fast_io;

	cin >> qq;
	while (qq --){
		cin >> n, res = 0;
		mp.clear();
		for (int i = 1; i <= n; ++ i){
			cin >> a[i];
			res ^= a[i];
			mp[res] = inf;
		}
		mp[0] = - 1;
		res = 0;
		for (int i = 1; i <= n; ++ i){
			res ^= a[i];
			dp[i] = min(dp[i - 1] + 1, i + mp[res]);
			mp[res] = min(mp[res], dp[i] - i - 1);
		}
		cout << dp[n] << endl;
	}

	return 0;
}