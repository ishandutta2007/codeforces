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

const int xn = 22;
const int xm = 2e5 + 10;
const int sq = 320;
const int inf = 1e9 + 10;
const ll INF = 1e18 + 10;
const ld eps = 1e-15;
const int mod = 1e9 + 7;//998244353;
const int base = 257;

int n, k, t, a[xn][xn], last[xn], b[xn], ps[xn][xm], ans, MSK;
ll dp[1 << xn];
string S;

int main(){
	fast_io;

	cin >> n >> k >> t >> S;
	for (int i = 0; i < k; ++ i)
		cin >> b[i];
	for (int i = 0; i < k; ++ i)
		for (int j = 0; j < k; ++ j)
			cin >> a[i][j];
	S = '.' + S;
	for (int i = 0; i < k; ++ i)
		for (int j = 1; j <= n; ++ j)
			ps[i][j] = ps[i][j - 1] + (S[j] - 'A' == i);
	for (int i = 1; i <= n; ++ i){
		int x = S[i] - 'A';
		MSK |= (1 << x);
		for (int j = 0; j < k; ++ j){
			int y = last[j];
			if (y < last[x] || !y)
				continue;
			int mask = 0;
			for (int p = 0; p < k; ++ p)
				if (ps[p][i - 1] - ps[p][y])
					mask += (1 << p);
			dp[mask] += a[j][x];
			dp[mask ^ (1 << x)] -= a[j][x];
			if (x == j)
				continue;
			dp[mask ^ (1 << j)] -= a[j][x];
			dp[mask ^ (1 << x) ^ (1 << j)] += a[j][x];
		}
		last[x] = i;
	}
	for (int bit = 0; bit < k; ++ bit)
		for (int mask = 0; mask < (1 << k); ++ mask)
			if ((mask & (1 << bit)))
				dp[mask] += dp[mask ^ (1 << bit)];
	for (int mask = 0; mask + 1 < (1 << k) && mask < MSK; ++ mask){
		if (MSK < (mask | MSK))
			continue;
		for (int bit = 0; bit < k; ++ bit)
			if ((mask & (1 << bit)))
				dp[mask] += b[bit];
		ans += (dp[mask] <= t);
	}
	cout << ans << endl;

	return 0;
}