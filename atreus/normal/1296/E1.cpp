#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int maxn = 2e5 + 5;

int dp[maxn], c[maxn];

int main(){
	ios_base::sync_with_stdio(false);
	int n;
	string s;
	cin >> n >> s;
	memset(dp, 63, sizeof dp);
	dp[0] = 0;
	int ans = 0;
	for (int i = n - 1; i >= 0; i--){
		int k = (int)(s[i] - 'a') + 1;
		int idx = lower_bound(dp, dp + n, k) - dp;
		c[i] = idx;
		dp[idx] = k;
		ans = max(ans, idx);
	}
	if (ans > 2)
		return cout << "No\n", 0;
	cout << "Yes\n";
	for (int i = 0; i < n; i++)
		cout << c[i]-1;
	cout << '\n';
}