#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef long double ldb;

void solve() {
	int n, m;
	cin >> n >> m;
	vector<string> arr(n);
	for (int i = 0; i < n; i++) {
		cin >> arr[i];
	}
	map<char, vector<int>> has;
	has['R'].resize(2);
	has['W'].resize(2);
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			if (arr[i][j] != '.') {
				has[arr[i][j]][(i + j) % 2] = 1;
			}
		}
	}
	if (has['R'][0] && has['R'][1]) {
		cout << "NO" << endl;
		return;
	}
	if (has['W'][0] && has['W'][1]) {
		cout << "NO" << endl;
		return;
	}
	if (has['R'][0] && has['W'][0]) {
		cout << "NO" << endl;
		return;
	}
	if (has['R'][1] && has['W'][1]) {
		cout << "NO" << endl;
		return;
	}
	bool b = false;
	if (has['R'][0] || has['W'][1]) {
		b = 1;
	}
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			char c;
			if ((((i + j) % 2 == 0) ^ b)) {
				c = 'W';
			} else {
				c = 'R';
			}
			if (arr[i][j] != '.')
				assert(arr[i][j] == c);
			arr[i][j] = c;
		}
	}
	cout << "YES" << endl;
	for (int i = 0; i < n; i++) {
		cout << arr[i] << endl;
	}
}

signed main() {
	int t = 1;
	cin >> t;
	while (t--) {
		solve();
	}
}