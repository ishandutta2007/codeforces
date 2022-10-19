#include<bits/stdc++.h>

using namespace std;

int n, m, a[505][505];

int main() {
	ios::sync_with_stdio(false); cin.tie(0);
	//freopen("in", "r", stdin);
	cin >> n >> m;
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= m; j++) {
			cin >> a[i][j];
		}
	}
	int flag = 0;
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j < m; j++) {
			if (a[i][j] != a[i][j + 1]) flag = i;
		}
	}
	if (flag == 0) {
		int res = 0;
		for (int i = 1; i <= n; i++) {
			res ^= a[i][1];
		}
		if (res > 0) {
			cout << "TAK" << endl;
			for (int i = 1; i <= n; i++) {
				cout << "1 ";
			}
		} else cout << "NIE";
	} else {
		int res = 0;
		for (int i = 1; i <= n; i++) {
			if (flag == i) continue;
			res ^= a[i][1];
		}
		int u;
		for (int i = 1; i < m; i++) {
			if (a[flag][i] != a[flag][i + 1]) {
				u = i;
				break;
			}
		}
		if ((res ^ a[flag][u]) > 0) {
			cout << "TAK" << endl;
			for (int i = 1; i <= n; i++) {
				if (i != flag) cout << "1 ";
				else cout << u << " ";
			}
		} else {
			cout << "TAK" << endl;
			for (int i = 1; i <= n; i++) {
				if (i != flag) cout << "1 ";
				else cout << u + 1 << " ";
			}
		}
	}
	return 0;
}