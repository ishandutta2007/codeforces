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
const int xn = 1e2+10;
const int xm = 5e5;
const int SQ = 320;
const int sq = 1e3+10;
const ll inf = 1e18+10;



string a, abc= "abcdefghijklmnopqrstuvwxyz";
int n;
ll ans, dp[xn][xn], k;



int main(){
	fast_io;
	
	cin >> n >> k >> a;
	a = '.' + a;
	
	for (int i = 0; i <= n; i++) dp[i][0] = 1;
	for (int i = 1; i <= n; i++){
		for (int j = 1; j <= n; j++){
			for (int p = 0; p < abc.size(); p++){
				int ind = -1;
				for (int pnt = i; pnt >= 1; pnt--){
					if (a[pnt] == abc[p]){
						ind = pnt - 1;
						break;
					}
				}
				if (ind == -1) continue;
				dp[i][j] += dp[ind][j - 1];
			}
		}
	}
	for (int i = n; i >= 0; i--){
		ans += min(dp[n][i], k) * (n - i);
		k -= dp[n][i];
		if (k <= 0) break;
	}
	if (k > 0){
		cout << -1 << endl;
		return 0;
	}
	cout << ans << endl;
	
	return 0;
}