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

const int xn = 20;
const int xm = - 20 + 10;
const int sq = 320;
const int inf = 1e9 + 10;
const ll INF = 1e18 + 10;
const ld eps = 1e-15;
const int mod = 998244353;
const int base = 257;

int n, k;
ld P[xn], dp[1 << xn], ans[xn];

int main(){
	fast_io;

	cin >> n >> k;
	for (int i = 0; i < n; ++ i)
		cin >> P[i];
	dp[0] = 1;
	for (int mask = 1; mask < (1 << n); ++ mask){
		ld sum = 1;
		int ted = 0;
		for (int i = 0; i < n; ++ i)
			if ((mask & (1 << i)))
				sum -= P[i], ++ ted;
		for (int i = 0; i < n; ++ i)
			if ((mask & (1 << i)) && 0 < sum + P[i])
				dp[mask] += P[i] / (sum + P[i]) * dp[mask ^ (1 << i)];
		if (ted - k)
			continue;
		for (int i = 0; i < n; ++ i)
			if ((mask & (1 << i)))
				ans[i] += dp[mask];
	}
	int ted = 0;
	for (int i = 0; i < n; ++ i)
		ted += bool(0 < P[i]);
	if (ted < k){
		for (int i = 0; i < n; ++ i){
			if (0 < P[i])
				ans[i] = 1;
			else
				ans[i] = 0;
		}
	}
	cout << fixed << setprecision(9);
	for (int i = 0; i < n; ++ i)
		cout << ans[i] << sep;
	cout << endl;

	return 0;
}