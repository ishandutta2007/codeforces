//khodaya khodet komak kon
# include <bits/stdc++.h>
# pragma GCC optimize ("O2")
# pragma GCC optimize ("unroll-loops")

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

const int xn = 1e3 + 10;
const int xm = 2e4 + 10;
const int sq = 300;
const int inf = 1e9 + 10;
const ll INF = 1e18 + 10;
const int mod = 1e6 + 7;//998244353;
const int base = 257;
const int SIG = 26;

int n, k, tb[1 << 20], dp[xn][xm], ptr, a[xm], C[xm][SIG], ans = inf;
string S;

int main(){
	InTheNameOfGod;

	cin >> S >> k, n = SZ(S);
	if (k == 1){
		ans = 0;
		for (int i = 0; i < n; ++ i)
			ans += (S[i] == '1');
		kill(ans);
	}
	for (int mask = 0; mask < (1 << k); ++ mask){
		bool flag = true;
		for (int i = 0; i < k; ++ i)
			flag &= (!((mask & (1 << i))) | !(mask & (1 << (i + 1))));
		flag &= !(mask & 1), flag &= !(mask & 2);
		if (flag)
			tb[mask] = ptr, a[ptr ++] = mask;
	}
	for (int t = 0; t < ptr; ++ t){
		int mask = a[t] + 1;
		for (int i = 2; i < 10; ++ i){
			for (int bit = i; bit <= k; ++ bit)
				if ((mask & (1 << (bit - i))))
					C[t][i] += (1 << bit);
			bool flag = !(C[t][i] & (1 << k));
			for (int j = 1; j < k; ++ j)
				if (k % j == 0)
					flag |= (C[t][i] & (1 << j));
			for (int b1 = 2; b1 < k; ++ b1)
				for (int b2 = b1 + 1; b2 <= k; ++ b2)
					if ((C[t][i] & (1 << b1)) && (C[t][i] & (1 << b2)))
						flag |= (k % (b2 - b1) == 0);
			C[t][i] = (C[t][i] & (C[t][i] ^ (1 << k)));
			if (!flag)
				C[t][i] = - 1;
		}
	}
	for (int i = 0; i < xn; ++ i)
		for (int j = 0; j < ptr; ++ j)
			dp[i][j] = inf;
	dp[0][0] = 0;
	for (int i = 0; i < n; ++ i){
		for (int j = 0; j < ptr; ++ j){
			int mask = a[j];
			if (S[i] == '1')
				dp[i + 1][0] = min(dp[i + 1][0], dp[i][j]);
			else{
				dp[i + 1][j] = min(dp[i + 1][j], dp[i][j] + 1);
				int x = C[j][S[i] - '0'];
				if (x != - 1)
					dp[i + 1][tb[x]] = min(dp[i + 1][tb[x]], dp[i][j]);
			}
		}
	}
	for (int i = 0; i < ptr; ++ i)
		ans = min(ans, dp[n][i]);
	cout << ans << endl;

	return 0;
}