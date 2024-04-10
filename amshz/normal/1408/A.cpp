# include <bits/stdc++.h>
 
using namespace std;
 
typedef long long                                        ll;
typedef long double                                      ld;
typedef pair <int, int>                                  pii;
 
# define A                                               first
# define B                                               second
# define endl                                            '\n'
# define sep                                             ' '
# define all(x)                                          x.begin(), x.end()
# define kill(x)                                         return cout << x << endl, 0
# define InTheNameOfGod                                  ios::sync_with_stdio(0);cin.tie(0); cout.tie(0);
 
ll power(ll a, ll b, ll md) {return (!b ? 1 : (b & 1 ? a * power(a * a % md, b / 2, md) % md : power(a * a % md, b / 2, md) % md));}
 
const int xn = 1e3 + 10;
const int xm = - 20 + 10;
const int sq = 320;
const int inf = 1e9 + 10;
const ll INF = 1e18 + 10;
const int mod = 1e9 + 7;
const int base = 257;

int qq, n, a[xn], b[xn], c[xn], par[3][xn], ans[xn];
bool dp[3][xn];

int main(){
    InTheNameOfGod;
    
	cin >> qq;
	while (qq --){
		cin >> n;
		for (int i = 1; i <= n; ++ i) cin >> a[i];
		for (int i = 1; i <= n; ++ i) cin >> b[i];
		for (int i = 1; i <= n; ++ i) cin >> c[i];
		a[n + 1] = a[1];
		b[n + 1] = b[1];
		c[n + 1] = c[1];
		for (int j = 0; j < 3; ++ j){
			memset(dp, false, sizeof dp);
			dp[j][1] = true;
			for (int i = 2; i <= n + 1; ++ i){
				if (dp[0][i - 1]){
					if (a[i - 1] != a[i]){
						dp[0][i] = true;
						par[0][i] = 0;
					}
					if (a[i - 1] != b[i]){
						dp[1][i] = true;
						par[1][i] = 0;
					}
					if (a[i - 1] != c[i]){
						dp[2][i] = true;
						par[2][i] = 0;
					}
				}
				if (dp[1][i - 1]){
					if (b[i - 1] != a[i]){
						dp[0][i] = true;
						par[0][i] = 1;
					}
					if (b[i - 1] != b[i]){
						dp[1][i] = true;
						par[1][i] = 1;
					}
					if (b[i - 1] != c[i]){
						dp[2][i] = true;
						par[2][i] = 1;
					}
				}
				if (dp[2][i - 1]){
					if (c[i - 1] != a[i]){
						dp[0][i] = true;
						par[0][i] = 2;
					}
					if (c[i - 1] != b[i]){
						dp[1][i] = true;
						par[1][i] = 2;
					}
					if (c[i - 1] != c[i]){
						dp[2][i] = true;
						par[2][i] = 2;
					}
				}
			}
			for (int k = 0; k < 3; ++ k) if (j != k) dp[k][n + 1] = false;
		}
		int x = n + 1, y;
		if (dp[0][n + 1]) y = 0;
		else if (dp[1][n + 1]) y = 1;
		else y = 2;
		while (x){
			if (y == 0) ans[x] = a[x];
			else if (y == 1) ans[x] = b[x];
			else ans[x] = c[x];
			y = par[y][x];
			-- x;
		}
		for (int i = 1; i <= n; ++ i) cout << ans[i] << sep;
		cout << endl;
	}
 
    return 0;
}