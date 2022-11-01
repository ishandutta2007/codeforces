#include <iostream>
#include <cmath>
using namespace std;

int a[105], b[105][105];

int main() {
	int n, m, ans = 0;
	cin >> n >> m;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			char c;
			cin >> c;
			b[i][j] = c - '0';
			a[j] = max(a[j], b[i][j]);
		}
	}
	for (int i = 0; i < n; i++) {
		bool d = false;
		for (int j = 0; j < m; j++) {
			if (b[i][j] == a[j]) {
				d = true;
			}
		}
		if (d)
			ans++;
	}
	cout << ans;
	return 0;
}