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
# define lc                                              id << 1
# define rc                                              id << 1 | 1
# define all(x)                                          x.begin(), x.end()
# define kill(x)                                         return cout << x << endl, 0
# define SZ(x)                                           int(x.size())
# define InTheNameOfGod                                  ios::sync_with_stdio(0);cin.tie(0); cout.tie(0);
 
ll power(ll a, ll b, ll md) {return (!b ? 1 : (b & 1 ? a * power(a * a % md, b / 2, md) % md : power(a * a % md, b / 2, md) % md));}
 
const int xn = 75 + 10;
const int xm = 20;
const int sq = 320;
const int inf = 1e9 + 10;
const ll INF = 1e18 + 10;
const int mod = 1e9 + 7;
const int base = 257;

int n, dp[xn][xn][xn][2], c[3];
int f[xn], ind[3][xn], ptr[3];
string s;
 
int main(){
	InTheNameOfGod;
	
	cin >> n >> s;
	s = '.' + s;
	for (int i = 1; i <= n; ++ i){
		if (s[i] == 'V'){
			f[i] = ++ ptr[0];
			ind[0][ptr[0]] = i;
		}
		else if (s[i] == 'K'){
			f[i] = ++ ptr[1];
			ind[1][ptr[1]] = i;
		}
		else{
			f[i] = ++ ptr[2];
			ind[2][ptr[2]] = i;
		}
	}
	for (int i = 0; i <= ptr[0]; ++ i){
		for (int j = 0; j <= ptr[1]; ++ j){
			for (int k = 0; k <= ptr[2]; ++ k){
				if (!(i + j + k))
					continue;
				dp[i][j][k][0] = dp[i][j][k][1] = inf;
				c[0] = c[1] = c[2] = 0;
				for (int ii = 1; ii <= n; ++ ii){
					if (s[ii] == 'V' && f[ii] > i)
						continue;
					if (s[ii] == 'K' && f[ii] > j)
						continue;
					if (s[ii] != 'V' && s[ii] != 'K' && f[ii] > k)
						continue;
					c[0] += (ii > ind[0][i]);
					c[1] += (ii > ind[1][j]);
					c[2] += (ii > ind[2][k]);
				}
				if (i) dp[i][j][k][1] = min(dp[i - 1][j][k][0], dp[i - 1][j][k][1]) + c[0];
				if (k) dp[i][j][k][0] = min(dp[i][j][k - 1][0], dp[i][j][k - 1][1]) + c[2];
				if (j) dp[i][j][k][0] = min(dp[i][j][k][0], dp[i][j - 1][k][0] + c[1]);
			}
		}
	}
	cout << min(dp[ptr[0]][ptr[1]][ptr[2]][0], dp[ptr[0]][ptr[1]][ptr[2]][1]) << endl;
	
	return 0;
}