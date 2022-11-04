#include <bits/stdc++.h>
using namespace std;
int n, vis[1005];
int main() {
	cin >> n;
	int mx = -1, k = 0;
	for (int i = 1; i <= n; i++) {
		int cur = n - (n + i - 1) / i - i + 1;
		if (mx < cur) {
			mx = cur;
			k = i;
		}
	}
	int cnt = 0;
	while (cnt < mx) {
		vector<int> vec;
		for (int i = 0; i < n && (int)vec.size() < k; i++) if (i % k && !vis[i]) {
			vec.push_back(i);
			vis[i] = 1;
			cnt++;
		}
		cout << k;
		for (int x : vec) cout << ' ' << x + 1;
		cout << endl;
		int l;
		cin >> l;
		l--;
		for (int i = 0; i < k; i++) {
			int j = (i + l) % n;
			if (vis[j]) {
				vis[j] = 0;
				cnt--;
			}
		}
	}
	cout << 0 << endl;
	return 0;
}