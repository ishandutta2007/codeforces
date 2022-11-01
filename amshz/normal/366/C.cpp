# include <bits/stdc++.h>
 
using namespace std;
 
typedef long long ll;
typedef long double ld;
typedef pair <int, int> pii;
 
# define A first
# define B second
# define endl '\n'
# define sep ' '
# define pb push_back
# define InTheNameOfGod ios::sync_with_stdio(0);cin.tie(0); cout.tie(0);
 
const ll md = 1e9 + 7;
const int xn = 1e2 + 10;
const int xm = 2e5 + 10;
const int SQ = 450;
const int sq = 1e3 + 10;
const int inf = 1e9 + 10;
const ll INF = 1e18 + 10;
 
ll power(ll a, ll b) {return (!b ? 1 : (b & 1 ? a * power(a * a % md, b / 2) % md : power(a * a % md, b / 2) % md));}
ll zarb(ll a, ll b){return (a * b + 10 * md) % md;}
ll jaam(ll a, ll b){return (a + b + 10 * md) % md;}

int n, a[xn], b[xn], k, dp[xn][xm];

int main(){
	InTheNameOfGod;
	
	cin >> n >> k;
	for (int i = 1; i <= n; i ++) cin >> a[i];
	for (int i = 1; i <= n; i ++) cin >> b[i], b[i] *= k;
	for (int i = 0; i <= n; i ++) for (int j = 0; j <= 2e5; j ++) dp[i][j] = -1;
	dp[0][100000] = 0;
	for (int i = 1; i <= n; i ++){
		for (int j = 0; j <= 2e5; j ++){
			int d = a[i] - b[i];
			dp[i][j] = max(dp[i][j], dp[i - 1][j]);
			if (j - d >= 0 && j - d <= 2e5 && dp[i - 1][j - d] != -1) dp[i][j] = max(dp[i][j], dp[i - 1][j - d] + a[i]);
		}
	}
	if (dp[n][100000] == 0) cout << -1 << endl;
	else cout << dp[n][100000] << endl;
	
	return 0;
}