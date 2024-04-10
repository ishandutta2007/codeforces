#include <bits/stdc++.h>
using namespace std;

int main() {
	ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);

	int n, k;
	cin >> n >> k;

	vector<set<int>> ss(10);
	ss[0] = {1, 2, 3, 5, 6, 7};
	ss[1] = {3, 6};
	ss[2] = {1, 3, 4, 5, 7};
	ss[3] = {1, 3, 4, 6, 7};
	ss[4] = {2, 3, 4, 6};
	ss[5] = {1, 2, 4, 6, 7};
	ss[6] = {1, 2, 4, 5, 6, 7};
	ss[7] = {1, 3, 6};
	ss[8] = {1, 2, 3, 4, 5, 6, 7};
	ss[9] = {1, 2, 3, 4, 6, 7};

	auto get = [&](set<int>& from, set<int>& to) {
		for (int i : from) {
			if (!to.count(i)) {
				return -1;
			}
		}
		return int(to.size()) - int(from.size());
	};

	vector<set<int>> a(n);
	for (int i = 0; i < n; i++) {
		string s;
		cin >> s;
		for (int j = 0; j < s.size(); j++) {
			if (s[j] == '1') {
				a[i].insert(j + 1);
			}
		}
	}

	vector<vector<int>> d(n + 1, vector<int>(k + 1));
	d[n][0] = 1;
	for (int i = n - 1; i >= 0; i--) {
		for (int j = 0; j <= k; j++) {
			for (int c = 0; c <= 9; c++) {
				int z = get(a[i], ss[c]);
				if (z == -1 || z > j) {
					continue;
				}
				d[i][j] |= d[i + 1][j - z];
			}
		}
	}

	for (int i = 0; i < n; i++) {
		bool ok = false;
		for (int c = 9; c >= 0; c--) {
			int z = get(a[i], ss[c]);
			if (z == -1 || z > k || !d[i + 1][k - z]) {
				continue;
			}
			a[i] = ss[c];
			k -= z;
			ok = true;
			break;
		}
		if (!ok) {
			cout << "-1\n";
			return 0;
		}
	}

	for (int i = 0; i < n; i++) {
		for (int c = 0; c <= 9; c++) {
			if (a[i] == ss[c]) {
				cout << c;
				break;
			}
		}
	}
	cout << "\n";

	return 0;
}