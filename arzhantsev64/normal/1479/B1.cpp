#pragma GCC optimize("O3", "unroll-loops")
#pragma GCC target("sse4.2")

#include <bits/stdc++.h>

using namespace std;

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	int n;
	cin >> n;
	vector<int> a(n);
	for (int i = 0; i < n; ++i)
		cin >> a[i];
	int c1 = -1;
	int c2 = -1;
	int ans = 0;
	for (int i = 0; i < n; ++i) {
		if (c1 == a[i]) {
			if (c2 != a[i])
				ans++;
			c2 = a[i];
		} else if (c2 == a[i]) {
			if (c1 != a[i])
				ans++;
			c1 = a[i];
		} else if (i < n - 1 && c1 == a[i + 1]) {
			ans++;
			c1 = a[i];
		} else {
			ans++;
			c2 = a[i];
		}
	}
	cout << ans << endl;
	return 0;
}