#include<bits/stdc++.h>

using namespace std;

int n, m, h, a[105], b[105], c[105][105], res[105][105];

int main() {
	ios::sync_with_stdio(false); cin.tie(0);
	//freopen("in", "r", stdin);
	cin >> n >> m >> h;
	for (int i = 1; i <= m; i++) {
		cin >> a[i];
	}
	for (int i = 1; i <= n; i++) {
		cin >> b[i];
	}
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= m; j++) {
			cin >> c[i][j];
			if (c[i][j] == 1) {
				res[i][j] = min(b[i], a[j]);
			}
		}
	}
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= m; j++) {
			cout << res[i][j] << ' ';
		}
		cout << endl;
	}
	return 0;
}