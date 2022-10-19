#include <bits/stdc++.h>
#define int long long
#define double long double
using namespace std;

signed main() {
	int n, k;
	cin >> n >> k;
	vector<int> arr(n);
	for (int i = 0; i < n; i++) {
		cin >> arr[i];
	}
	vector<int> prefSum(n + 1);
	for (int i = 1; i <= n; i++) {
		prefSum[i] = prefSum[i - 1] + arr[i - 1];
	}
	double ans = -1e14;
	for (int l = 0; l < n; l++) {
		for (int r = l + k; r <= n; r++) {
			ans = max(ans, (double) (prefSum[r] - prefSum[l]) / (r - l));
		}
	}
	cout.precision(15);
	cout << ans;
	return 0;
}