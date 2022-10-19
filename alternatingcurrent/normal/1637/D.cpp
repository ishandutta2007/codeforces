#include<bits/stdc++.h>
#define rep(i, n) for(int i = 0; i < n; i++)
using namespace std;
typedef long long ll;

int T;
int n;
int a[111], b[111];
int sum = 0;
ll dp[111][11111];
ll ans = 0;

int main(){
	ios::sync_with_stdio(false);
	cin >> T;
	while(T--){
		cin >> n;
		rep(i, n)
			cin >> a[i];
		rep(i, n)
			cin >> b[i];
		ans = 0;
		rep(i, n)
			ans += 1ll * a[i] * a[i] + 1ll * b[i] * b[i];
		ans = ans * (ll)(n - 1);
		memset(dp, 0x3f, sizeof(dp));
		sum = 0;
		dp[0][0] = 0;
		rep(i, n){
			rep(nowsum, sum + 1){
				if(dp[i][nowsum] <= 0x3f3f3f3f3f3f3f3fll){
					dp[i + 1][nowsum + a[i]] = min(dp[i + 1][nowsum + a[i]], dp[i][nowsum] + 2ll * nowsum * a[i] + 2ll * (sum - nowsum) * b[i]);
					dp[i + 1][nowsum + b[i]] = min(dp[i + 1][nowsum + b[i]], dp[i][nowsum] + 2ll * nowsum * b[i] + 2ll * (sum - nowsum) * a[i]);
				}
			}
			sum += a[i] + b[i];
		}
		ll res = 0x3f3f3f3f3f3f3f3fll;
		rep(nowsum, sum + 1)
			res = min(res, dp[n][nowsum]);
		cout << ans + res << endl;
	}
	return 0;
}