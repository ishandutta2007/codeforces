#include <bits/stdc++.h>

using namespace std;

int main() {
	int n, q;
	cin >> n >> q;
	vector<int> a(n);
	int cnt = 0;
	for (int i = 0; i < n; ++i) {
		cin >> a[i];
		cnt += a[i];
	}
	for (int i = 0; i < q; ++i) {
		int t;
		cin >> t;
		if (t == 1) {
			int x;
			cin >> x;
			x--;
			cnt -= a[x];
			a[x] = 1 - a[x];
			cnt += a[x];
		} else {
			int k;
			cin >> k;
			if (cnt >= k)
				cout << 1 << '\n';
			else
				cout << 0 << '\n';
		}
	}
}