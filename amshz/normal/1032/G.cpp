// khodaya khodet komak kon
# include <bits/stdc++.h>
# include <ext/pb_ds/assoc_container.hpp>
 
using namespace std;
using namespace __gnu_pbds;
 
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
# define ordered_set                                     tree<pii, null_type, less<pii>, rb_tree_tag, tree_order_statistics_node_update>
# define InTheNameOfGod                                  ios::sync_with_stdio(0);cin.tie(0); cout.tie(0);
 
ll power(ll a, ll b, ll md) {return (!b ? 1 : (b & 1 ? a * power(a * a % md, b / 2, md) % md : power(a * a % md, b / 2, md) % md));}
 
const int xn = 3e5 + 10;
const int xm = 10 + 10;
const int sq = 320;
const int inf = 1e9 + 10;
const ll INF = 1e18 + 10;
const int mod = 998244353;
const int base = 257;

int n, a[xn], lg[xn];
pii rmq[xm][xn], dp[xm][xn];

pii get(int l, int r){
	int bit = lg[r - l + 1];
	pii res = rmq[bit][l];
	r = r + 1 - (1 << bit);
	if (dp[0][rmq[bit][r].A].A < dp[0][res.A].A)
		res.A = rmq[bit][r].A;
	if (dp[0][rmq[bit][r].B].B > dp[0][res.B].B)
		res.B = rmq[bit][r].B;
	return res;
}

int main(){
	InTheNameOfGod;
	
	for (int i = 2; i < xn; ++ i)
		lg[i] = lg[i >> 1] + 1;
	cin >> n;
	if (n == 1)
		kill(0);
	for (int i = n + 1; i <= n + n; ++ i)
		cin >> a[i], a[i - n] = a[i + n] = a[i];
	for (int i = 1; i <= n + n + n; ++ i){
		dp[0][i].A = max(1, i - a[i]);
		dp[0][i].B = min(n + n + n, i + a[i]);
		rmq[0][i] = {i, i};
	}
	for (int bit = 1; bit < xm; ++ bit){
		for (int i = 1; i <= n + n + n; ++ i){
			rmq[bit][i] = rmq[bit - 1][i];
			if (i + (1 << (bit - 1)) - 1 > n + n + n)
				continue;
			pii ind = rmq[bit - 1][i + (1 << (bit - 1))];
			if (dp[0][ind.A].A < dp[0][rmq[bit][i].A].A)
				rmq[bit][i].A = ind.A;
			if (dp[0][ind.B].B > dp[0][rmq[bit][i].B].B)
				rmq[bit][i].B = ind.B;
		}
	}
	for (int bit = 1; bit < xm; ++ bit){
		for (int i = 1; i <= n + n + n; ++ i){
			pii ind = get(dp[bit - 1][i].A, dp[bit - 1][i].B);
			dp[bit][i].A = min(dp[bit - 1][ind.A].A, dp[bit - 1][ind.B].A);
			dp[bit][i].B = max(dp[bit - 1][ind.A].B, dp[bit - 1][ind.B].B);
		}
	}
	for (int i = n + 1; i <= n + n; ++ i){
		int l = i, r = i, ans = 1;
		for (int bit = xm - 1; bit >= 0; -- bit){
			if (max(dp[bit][l].B, dp[bit][r].B) - min(dp[bit][l].A, dp[bit][r].A) + 1 >= n)
				continue;
			pii ind = get(dp[bit][l].A, dp[bit][r].B);
			l = ind.A, r = ind.B, ans += (1 << bit);
		}
		cout << ans << sep;
	}
	cout << endl;
			
	return 0;
}