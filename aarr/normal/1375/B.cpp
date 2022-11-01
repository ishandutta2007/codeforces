#include <bits/stdc++.h>
#define endl '\n'
using namespace std;




int main() {
	ios :: sync_with_stdio(false);
	int t;
	cin >> t;
	for (int ii = 0; ii < t; ii++) {
		int n, m;
		cin >> n >> m;
		bool b = true;
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < m; j++) {
				int x;
				cin >> x;
				int y = 4;
				if (i == 0 || i == n - 1) {
					y--;
				}
				if (j == 0 || j == m - 1) {
					y--;
				}
				if (x > y) {
					b = false;
				}
			}
		}
		if (!b) {
			cout << "NO\n";
		}
		else {
			cout << "YES\n";
			for (int i = 0; i < n; i++) {
				for (int j = 0; j < m; j++) {
				int y = 4;
				if (i == 0 || i == n - 1) {
					y--;
				}
				if (j == 0 || j == m - 1) {
					y--;
				}					
					cout << y << " ";
				}
				cout << '\n';
			}
		}
	}
	
	return 0;
}