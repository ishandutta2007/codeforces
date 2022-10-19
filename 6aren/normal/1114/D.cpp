#include <bits/stdc++.h>

using namespace std;

const int N = 5005;

int f[N][N], n, a[N];

vector<int> c;

int main() {
	cin >> n;
	for (int i = 1; i <= n; i++) {
		cin >> a[i];
	}
	c.push_back(a[1]);
	for (int i = 2; i <= n; i++) {
		if (a[i] != a[i - 1]) {
			c.push_back(a[i]);
		}
	}
	n = c.size();
	for (int i = 1; i <= n; i++) {
		f[i][i] = 1;
	}
	for (int l = 2; l <= n; l++) {
		for (int i = 1; i <= n - l + 1; i++) {
			if (c[i - 1] == c[i + l - 2]) {
				f[i][i + l - 1] = f[i + 1][i + l - 2] + 2;
			} else {
				f[i][i + l - 1] = max(f[i][i + l - 2], f[i + 1][i + l - 1]);
			}
		}
	}
	int t = f[1][n] / 2;
	cout << n - 1 - t << endl;
	return 0;
}