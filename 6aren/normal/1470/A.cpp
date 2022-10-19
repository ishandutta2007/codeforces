#include <bits/stdc++.h>
using namespace std;

#define int long long

int32_t main() {
	ios::sync_with_stdio(false); cin.tie(0);

	int ntest;
	cin >> ntest;

	while (ntest--) {
		int n, m;
		cin >> n >> m;
		vector<int> a(n);

		for (int &e : a) {
			cin >> e;
			e--;
		}

		vector<int> c(m);
		for (int &e : c) {
			cin >> e;
		}

		int cur = 0;
		int ans = 0;

		sort(a.begin(), a.end());

		for (int i = n - 1; i >= 0; i--) {
			if (cur <= a[i]) {
				ans += c[cur];
				cur++;
			} else {
				ans += c[a[i]];
			}
		}

		cout << ans << '\n';
	}

	return 0;
}