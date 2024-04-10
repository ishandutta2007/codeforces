#include <bits/stdc++.h>
using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);

	int tt;
	cin >> tt;

	while (tt--) {
		int n;
		cin >> n;
		vector<int> a(n);
		for (int &e : a) cin >> e;
		long long res = 0;
		for (int i = 1; i < n; i++) {
			res = max(res, 1LL * a[i - 1] * a[i]);
		} 
		cout << res << '\n';
	}

	return 0;
}