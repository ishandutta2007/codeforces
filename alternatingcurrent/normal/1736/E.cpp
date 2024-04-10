#include<bits/stdc++.h>
#define rep(i, n) for(int i = 0; i < n; ++i)
using namespace std;

int n;
int a[555];
int dp[2][555][555];

int main(){
	ios::sync_with_stdio(false);
	
	cin >> n;
	rep(i, n)
		cin >> a[i];
	a[n] = 0;
	
	memset(dp, 0xc0, sizeof(dp));
	dp[0][1][0] = dp[0][0][1] = 0;
	for(int i = 1; i <= n; ++i){
		int now = i & 1, pre = (i-1) & 1;
		memset(dp[now], 0xc0, sizeof(dp[now]));
//		rep(j, n+1) rep(k, n)
//			if(dp[pre][j][k] >= 0)
//				cout << i-1 << " " << j << " " << k << ": " << dp[pre][j][k] << endl;
		for(int j = 0; j <= i+1; ++j){
			rep(k, n){
				dp[now][j][k] = max(dp[now][j][k], dp[pre][j][k] + a[k]);
				dp[now][j+1][(k<i) ? i : n] = max(dp[now][j+1][(k<i) ? i : n], dp[pre][j][k] + a[k]);
			}
		}
		rep(j, i+2){
			int mxval = 0xc0c0c0c0;
			rep(k, n+1)
				mxval = max(mxval, dp[now][j][k]);
			for(int d = 1; j-d >= 0 && i+d < n; ++d)
				dp[now][j-d][i+d] = max(dp[now][j-d][i+d], mxval);
		}
	}
	
	int ans = 0xc0c0c0c0;
	rep(j, n+1) rep(k, n)
		ans = max(ans, dp[n&1][j][k]);
	cout << ans << endl;
	
	return 0;
}