#include<bits/stdc++.h>
#define rep(i, n) for(int i = 0; i < n; i++)
using namespace std;
typedef long long ll;
const ll Mod = 998244353;

int n;
ll a[555];

ll dp[555][555];
ll solve(int now){
	memset(dp, 0, sizeof(dp));
	dp[0][0] = 1;
	rep(i, n){
		if(i == now){
			rep(j, n + 1)
				dp[i + 1][j] = dp[i][j];
			continue;
		}
		if(a[i] < 0){
			rep(j, n + 1){
				if(!j){
					if(i < now)
						dp[i + 1][j] = (dp[i + 1][j] + dp[i][j]) % Mod;
				} else {
					dp[i + 1][j - 1] = (dp[i + 1][j - 1] + dp[i][j]) % Mod;
				}
				dp[i + 1][j] = (dp[i + 1][j] + dp[i][j]) % Mod;
			}
		} else {
			if(a[i] < a[now] || (a[i] == a[now] && i < now)){
				rep(j, n + 1){
					dp[i + 1][j + 1] = (dp[i + 1][j + 1] + dp[i][j]) % Mod;
					dp[i + 1][j] = (dp[i + 1][j] + dp[i][j]) % Mod;
				}
			} else {
				rep(j, n + 1)
					dp[i + 1][j] = (dp[i][j] * 2LL) % Mod;
			}
		}
	}
	ll ret = 0LL;
	rep(j, n + 1)
		ret = (ret + dp[n][j]) % Mod;
	return ret;
} 

int main(){
	ios::sync_with_stdio(false);
	cin >> n;
	rep(i, n){
		char tp;
		cin >> tp;
		if(tp == '-'){
			a[i] = -1;
		} else {
			cin >> a[i];
		}
	}
	ll ans = 0;
	rep(i, n){
		if(a[i] > 0){
			ans = (ans + solve(i) * a[i]) % Mod;
		}
	}
	cout << ans << endl;
	return 0;
}