
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;


int h[(int)2e5 + 999];
int dp[(int)2e5 + 999];

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);

	int n, k;
	cin >> n >> k;
	for(int i = 0; i < n; ++i)
		cin >> h[i];


	{
		const int m = *min_element(h, h + n);
		for(int i = 0; i < n; ++i) {
			h[i] -= m;
			dp[0]++;
			dp[h[i]]--;
		}
	}
	partial_sum(begin(dp), end(dp), dp);

	if(!dp[0]) {
		cout << "0\n";
		return 0;
	}
	int ans = 1;
	int curr = 0;
	for(int i = 0; dp[i]; ++i) {
		curr += dp[i];
		if(curr > k) {
			ans++;
			curr = dp[i];
		}
		assert(curr <= k);
	}
	cout << ans << '\n';
	return 0;
}