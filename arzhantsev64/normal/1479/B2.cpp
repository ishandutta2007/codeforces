#pragma GCC optimize("O3", "unroll-loops")
#pragma GCC target("sse4.2")

#include <bits/stdc++.h>

using namespace std;

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	srand(time(NULL));
	int n;
	// n = 10;
	cin >> n;
	vector<int> a(n);
	unordered_map<int, set<int>> pos;
	for (int i = 0; i < n; ++i) {
		// a[i] = rand() % 3 + 1;
		// cout << a[i] << ' ';
		cin >> a[i];
		pos[a[i]].insert(i);
	}
	// cout << endl;
	int c1 = -1;
	int c2 = -1;
	int ans = 0;
	for (int i = 0; i < n; ++i) {
		// cout << c1 << ' ' << c2 << endl;
		pos[a[i]].erase(i);
		if (c1 == a[i]) {
			continue;
		} else if (c2 == a[i]) {
			continue;
		} else if (c1 == -1) {
			ans++;
			c1 = a[i];
		} else if (c2 == -1) {
			ans++;
			c2 = a[i];
		} else if (pos[c2].empty()) {
			ans++;
			c2 = a[i];
		} else if (pos[c1].empty()) {
			ans++;
			c1 = a[i];
		} else if (*pos[c1].begin() < *pos[c2].begin()) {
			ans++;
			c2 = a[i];
		} else {
			ans++;
			c1 = a[i];
		}
	}
	cout << ans << endl;
	return 0;
}