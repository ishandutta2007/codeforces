#include <bits/stdc++.h>

using namespace std;


int main() {
	int q; cin >> q;
	while (q--) {
		int n; cin >> n;
		vector<int> a(n * 4);
		for (int i = 0; i < n * 4; ++i) cin >> a[i];
		sort(begin(a), end(a));
		bool ok = true;
		for (int i = 0, l = 0, r = n * 4 - 1; i < n; ++i, l += 2, r -= 2) {
			if ((a[l] - a[l + 1]) || (a[r] - a[r - 1]) || (a[l] * a[r] - a[0] * a[n * 4 - 1])) {
				ok = false; break;
			}
		}
		cout << (ok ? "YES" : "NO") << endl;
	}
}