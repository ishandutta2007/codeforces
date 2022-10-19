#include<bits/stdc++.h>
#define rep(i, n) for(int i = 0; i < n; i++)
using namespace std;
typedef long long ll;
ll Mod;

int n;
ll dp[444][444];
ll pow2[444];
ll C[444][444];

int main(){
	ios::sync_with_stdio(false);
	cin >> n >> Mod;
	rep(i, n + 1) C[i][0] = 1;
	for(int i = 1; i <= n; i++) for(int j = 1; j <= n; j++) C[i][j] = (C[i - 1][j - 1] + C[i - 1][j]) % Mod;
	pow2[0] = 1LL;
	for(int i = 1; i <= n; i++) pow2[i] = pow2[i - 1] * 2LL % Mod;
	rep(i, n) dp[i][1] = pow2[i];
	rep(i, n) rep(j, i + 2) for(int k = i + 2; k < n; k++) dp[k][j + 1] = (dp[k][j + 1] + dp[i][j] * pow2[k - i - 2] % Mod * C[((i + 1) - (j - 1)) + (k - (i + 2) + 1)][k - (i + 2) + 1]) % Mod;
    ll ans = 0;
	for(int num = 1; num < n; num++) ans = (ans + dp[n - 1][num]) % Mod;
	cout << ans << endl;
	return 0;
}