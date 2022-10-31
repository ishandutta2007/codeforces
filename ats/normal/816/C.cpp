#include <bits/stdc++.h>
using namespace std;

int main() {
	int n, m;
	cin >> n >> m;
	vector<vector<int> > a(n, vector<int>(m));
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cin >> a[i][j];
		}
	}
	vector<int> x(m);
	vector<int> y(n);
	x[0] = 0;
	int mini = 10000;
	
	for (int i = 0; i < m; i++) {
		mini = min(mini, a[0][i]);
	}
	for (int i = 0; i < m; i++) {
		x[i] = a[0][i] - mini;
	}
	mini = 10000;
	for (int i = 0; i < n; i++) {
		mini = min(mini, a[i][0]);
	}
	//cerr << "A" << endl;
	for (int i = 0; i < n; i++) {
		y[i] = a[i][0] - mini;
	}
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			a[i][j] -= x[j] + y[i];
		}
	}
	//cerr << "A" << endl;
	if (a[0][0] < 0) {
		cout << -1 << endl;
		return 0;
	}
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			if (a[i][j] != a[0][0]) {
				cout << -1 << endl;
				return 0;
			}
		}
	}
	if (n > m) {
		for (int i = 0; i < m; i++) {
			x[i] += a[0][0];
		}
	}
	else {
		for (int i = 0; i < n; i++) {
			y[i] += a[0][0];
		}
	}
	int res = 0;

	for (int i = 0; i < m; i++) {
		res += x[i];
	}

	for (int i = 0; i < n; i++) {
		res += y[i];
	}
	cout << res << endl;
	for (int i = 0; i < m; i++) {
		for (int j = 0; j < x[i]; j++) {
			cout << "col " << (i + 1) << endl;
		}
	}
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < y[i]; j++) {
			cout << "row " << (i + 1) << endl;
		}
	}
	return 0;
}