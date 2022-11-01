#include <bits/stdc++.h>
using namespace std;

const int maxn = 1e5 + 17;
int n, a[maxn], mx[maxn];
long long dp[maxn];
int main(){
	ios::sync_with_stdio(0), cin.tie(0);
	cin >> n;
	for(int i = 0; i < n; i++){
		cin >> a[i];
		dp[i + 1] = dp[i] + max(0, mx[i] + 1 - a[i]);
		mx[i + 1] = max(mx[i] + 1, a[i]);
	}
	int mxx = 0;
	long long cur = 0, ans = 1e18;
	for(int i = n - 1; i >= 0; i--){
		cur += max(0, mxx + 1 - a[i]);
		mxx = max(mxx + 1, a[i]);
		ans = min(ans, cur + dp[i] + max(0, mx[i] + 1 - mxx));
	}
	cout << ans << '\n';
	return 0;
}