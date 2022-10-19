#include<bits/stdc++.h>
#define rep(i, n) for(int i = 0; i < n; i++)
using namespace std;
typedef long long ll;
const ll Mod = 1000000007;

int n, k, q;
ll a[5050];
ll dp[5050][5050];
ll freq[5050];

int main(){
	ios::sync_with_stdio(false);
	cin >> n >> k >> q;
	rep(i, n) cin >> a[i];
	rep(i, n) dp[0][i] = 1;
	for(int i = 0; i < k; i++){
		rep(j, n){
			if(j < n-1) dp[i+1][j+1] = (dp[i+1][j+1] + dp[i][j]) % Mod;
			if(j > 0)   dp[i+1][j-1] = (dp[i+1][j-1] + dp[i][j]) % Mod;
		}
	}
	rep(i, k+1){
		rep(j, n) freq[j] = (freq[j] + dp[i][j] * dp[k-i][j]) % Mod;
	}
	ll ans = 0;
	rep(i, n) ans = (ans + freq[i] * a[i]) % Mod;
	rep(i, q){
		int pos;
		ll val;
		cin >> pos >> val;
		pos--;
		ans = ((ans - freq[pos] * a[pos]) % Mod + Mod) % Mod;
		a[pos] = val;
		ans = (ans + freq[pos] * a[pos]) % Mod;
		cout << ans << endl;
	}
	return 0;
}