#pragma GCC optimize("O3", "unroll-loops")
#pragma GCC target("sse4.2")

#include <bits/stdc++.h>

using namespace std;

#define int long long
#define pt pair<int, int>
#define x first
#define y second

void solve() {
	int n;
	cin >> n;

	vector<int> know(n, -1);
	int last = -1;
	for (int i = 0; i < n; ++i) {
		if (know[i] != -1)
			continue;

		cout << "? " << i + 1 << endl;
		int x;
		cin >> x;
		x--;
		last = x;

		while (1) {
			cout << "? " << i + 1 << endl;
			int x;
			cin >> x;
			x--;
			know[last] = x;
			last = x;
			if (know[last] != -1)
				break;
		}
	}

	cout << "! ";
	for (int i : know)
		cout << i + 1 << ' ';
	cout << endl;

}

signed main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	int t;
	cin >> t;
	while (t--) {
		solve();
	}

	return 0;
}