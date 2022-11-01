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
 
const int xn = 2e5 + 10;
const int xm = - 20 + 10;
const int sq = 320;
const int inf = 1e9 + 10;
const ll INF = 1e18 + 10;
const int mod = 998244353;
const int base = 257;

ll qq, n, k, a[xn], p[xn], b[xn], c[xn];
ll dp[xn], part[xn];
pii last[xn];

int main(){
	InTheNameOfGod;
	
	cin >> qq;
	while (qq --){
		cin >> n >> k;
		for (int i = 1; i <= n; ++ i)
			cin >> a[i], p[a[i]] = i, c[i] = 0;
		for (int i = 1; i <= k; ++ i)
			cin >> b[i], c[p[b[i]]] = i;
		for (int i = 1; i <= n; ++ i){
			last[i] = {0, i};
			if (c[i] > c[i - 1] && i - 1)
				last[i].A = last[i - 1].A;
			if (!c[i])
				last[i].A = i;
			last[i].B = i;
			if (c[i] < c[i - 1])
				last[i].B = last[i - 1].B;
		}
		dp[0] = part[0] = 1;
		for (int i = 1; i <= n; ++ i){
			dp[i] = 0;
			if (!c[i]) dp[i] = dp[i - 1];
			if (last[i].A){
				int l = last[last[i].A].B;
				int r = last[i].A;
				if (!c[i]) -- r;
				if (r >= l){
					dp[i] = (dp[i] + part[r - 1]) % mod;
					if (l - 2 > - 1)
						dp[i] = (dp[i] - part[l - 2] + mod) % mod;
				}
			}
			part[i] = (part[i - 1] + dp[i]) % mod;
		}
		cout << dp[n] << endl;
	}
			
	return 0;
}