#include <iostream>
using namespace std;



char c[65][65];

int main() {
	int t;
	cin >> t;
	for (int ii = 0; ii < t; ii++) {
		int n, m;
		cin >> n >> m;
		bool a = false, b = true;
		for (int i = 1; i <= n; i++) {
			for (int j = 1; j <= m; j++) {
				cin >> c[i][j];
				if (c[i][j] == 'A') {
					a = true;
				}
				else {
					b = false;
				}
			}
		}

		if (!a) {
			cout << "MORTAL" << endl;
			continue;
		}
		if (b) {
			cout << 0 << endl;
		}
		else {
			int ans = 4;
			if (c[1][1] == 'A' || c[n][1] == 'A' || c[1][m] == 'A' || c[n][m] == 'A') {
				ans = 2;
			}
			for (int i = 1; i <= n; i++) {
				bool b = true;
				for (int j = 1; j <= m; j++) {
					if (c[i][j] == 'P') {
						b = false;
					}
					else {
						if (i == 1 || j == 1 || i == n || j == m) {
							ans = min(ans, 3);
						}
					}
					
				}
				if (b) {
					if (i == 1 || i == n) {
						ans = 1;
					}
					else {
						ans = min(ans, 2);
					}
				}
			}
			for (int j = 1; j <= m; j++) {
				bool b = true;
				for (int i = 1; i <= n; i++) {
					if (c[i][j] == 'P') {
						b = false;
					}
					
				}
				if (b) {
					if (j == 1 || j == m) {
						ans = 1;
					}
					else {
						ans = min(ans, 2);
					}
				}
			}	
			cout << ans << endl;		
		}
		
	}
	return 0;
}