# include <bits/stdc++.h>
 
using namespace std;
 
const int xn = 2e5+10;
int a[xn], dp[xn], lst[xn], mxs[xn], f[xn], cnt[xn];
 
int main(){
	int n;
	cin >> n;
	for (int i=0; i<n; i++) cin >> a[i];
	for (int i=1; i<n; i++) lst[i] = 1e9+10;
	for (int i=0; i<n; i++){
		int k = lower_bound(lst, lst+n, a[i]) - lst - 1;
		dp[i] = k+1;
		lst[k+1] = min(lst[k+1], a[i]);
	}
	int mx = 0;
	for (int i=0; i<n; i++) mx = max(mx, dp[i]);
	for (int i=n-1; i>=0; i--){
		if (dp[i] == mx) f[i] = 1, cnt[dp[i]]++, mxs[dp[i]] = max(mxs[dp[i]], a[i]);
		else if (mxs[dp[i]+1] > a[i]) f[i] = 1, cnt[dp[i]]++, mxs[dp[i]] = max(mxs[dp[i]], a[i]);
	}
	for (int i=0; i<n; i++){
		if (f[i] == 0) cout << 1;
		else if (cnt[dp[i]] > 1) cout << 2;
		else cout << 3;
	}
}