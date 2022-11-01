# include <bits/stdc++.h>
 
using namespace std;
 
typedef long long ll;
typedef long double ld;
typedef pair <ll, int> pii;
 
# define F first
# define S second
# define endl '\n'
# define sep ' '
# define pb push_back
# define fast_io ios::sync_with_stdio(0);cin.tie(0); cout.tie(0);
 
const ll md = 998244353;
const int xn = 5e3 + 10;
const int xm = 550;
const int SQ = 750;
const int sq = 1e3 + 10;
const ll inf = 1e18 + 10;
 
 
ll power(ll a, ll b) {
    return (!b ? 1 : (b & 1 ? a * power(a * a % md, b / 2) % md : power(a * a % md, b / 2) % md));
}

ll n, k, a[xn], dp[xn][xn], ans;
 
 
int main(){
	fast_io;
	
	
	cin >> n >> k;
	for (int i = 1; i <= n; i ++) cin >> a[i];
	a[n + 1] = a[1];
	
	dp[0][n + 1] = 1LL;
	for (int i = 1; i <= n; i ++){
		for (int j = 1; j <= n + n + 1; j ++){
			if (a[i] == a[i + 1]) dp[i][j] = (dp[i - 1][j] * k) % md;
			else {
				dp[i][j] += dp[i - 1][j - 1], dp[i][j] %= md;
				dp[i][j] += dp[i - 1][j + 1], dp[i][j] %= md;
				dp[i][j] += (dp[i - 1][j] * max(0LL, k - 2)) % md, dp[i][j] %= md;
			}
		}
	}
	for (int i = n + 2; i <= n + n + 1; i ++) ans = (ans + dp[n][i]) % md;
	cout << ans << endl;
	
	return 0;
}