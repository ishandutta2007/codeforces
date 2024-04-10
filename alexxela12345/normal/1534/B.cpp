#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef long double ldb;

#define int ll

void solve() {
	int n;
	cin >> n;
	vector<int> arr(n + 2);
	for (int i = 1; i <= n; i++) {
		cin >> arr[i];
	}
	int cnt = 0;
	for (int i = 1; i <= n; i++) {
		if (arr[i] > arr[i - 1] && arr[i] > arr[i + 1]) {
			int need = max(arr[i - 1], arr[i + 1]);
			cnt += arr[i] - need;
			arr[i] = need;
		}
	}
	for (int i = 1; i <= n + 1; i++) {
		cnt += abs(arr[i] - arr[i - 1]);
	}
	cout << cnt << endl;
}

signed main() {
	int t = 1;
	cin >> t;
	while (t--) {
		solve();
	}
}