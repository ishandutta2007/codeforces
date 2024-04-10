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
 
const ll md = 1e9+7;
const int xn = 5e3+10;
const int xm = 5e5;
const int SQ = 320;
const int sq = 1e3+10;
const ll inf = 1e18+10;
 
 
ll power(ll a, ll b) {
    return (!b ? 1 : (b & 1 ? a * power(a * a % md, b / 2) % md : power(a * a % md, b / 2) % md));
}
 
int n, k, a[xn], par[xn], dp[xn][xn];
 
 
int main(){
	fast_io;
	
	cin >> n >> k;
	for (int i = 1; i <= n; i++) cin >> a[i];
	a[0] = -5;
	
	sort(a, a + n + 1);
	
	for (int i = n - 1; i >= 0; i--){
		par[n] = i;
		if (a[n] - a[i] > 5) break;
	}
	
	for (int i = n - 1; i >= 1; i--){
		par[i] = par[i + 1];
		for (int j = par[i + 1]; j >= 0; j--){
			par[i] = j;
			if (a[i] - a[j] > 5) break;
		}
	}
	
	for (int i = 1; i <= n; i++)
		for (int j = 1; j <= k; j++)
			dp[i][j] = max(dp[i - 1][j], dp[par[i]][j - 1] + i - par[i]);
	
	cout << dp[n][k] << endl;
 
	
	return 0;
}