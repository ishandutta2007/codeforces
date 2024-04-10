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
const int xn = 5e2+10;
const int xm = 5e5;
const int SQ = 320;
const int sq = 1e3+10;
const ll inf = 1e18+10;


ll power(ll a, ll b) {
    return (!b ? 1 : (b & 1 ? a * power(a * a % md, b / 2) % md : power(a * a % md, b / 2) % md));
}

int n, a[xn], dp[xn][xn], dp2[xn];



int main(){
	fast_io;
	
	
	cin >> n;
	for (int i = 0; i < n; i ++) cin >> a[i];
	
	for (int i = 0; i < n - 1; i ++)
		if (a[i] == a[i + 1]) dp[i][i + 1] = a[i] + 1;
	for (int i = 0; i < n; i ++) dp[i][i] = a[i];
	
	
	for (int k = 3; k <= n; k ++){
		for (int i = 0; i <= n - k; i ++){
			for (int j = i; j < i + k - 1; j ++){
				if (dp[i][j] == dp[j + 1][i + k - 1] && dp[i][j]) dp[i][i + k - 1] = dp[i][j] + 1;
			}
		}
	}
	//cout << dp[0][3] << endl;
	
	dp2[0] = 1;
	for (int i = 1; i < n; i ++){
		dp2[i] = i + 1;
		for (int j = 0; j <= i; j ++){
			if (dp[j][i]){
				if (j == 0) dp2[i] = 1;
				else dp2[i] = min(dp2[i], 1 +  dp2[j - 1]);
			}
		}
		//dp2[i] = min(dp2[i], dp2[i - 1]);
	}
	
	//cout << dp[0][3] << endl;
	//cout << dp2[n - 2] << endl;
	
	cout << dp2[n - 1] << endl;
	
	
	return 0;
}