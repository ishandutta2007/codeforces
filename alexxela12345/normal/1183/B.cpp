#include <bits/stdc++.h>
using namespace std;

int main() {
	int q;
	cin >> q;
	while (q--) {
		int n, m;
		cin >> n >> m;
		vector<int> arr(n);
		for (int i = 0; i < n; i++) {
			cin >> arr[i];
		}
		int maxx = *max_element(arr.begin(), arr.end());
		int minn = *min_element(arr.begin(), arr.end());
		if (maxx - minn > 2 * m) {
			cout << -1 << endl;
			continue;
		}
		cout << minn + m << endl;
	}
}