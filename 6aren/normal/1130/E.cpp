#include <bits/stdc++.h>

using namespace std;

int k;

int main() {
	cin >> k;
	for (int m = 1; m <= 999; m++) {
		int x = (k + m *(2 * m + 1)) / (2 * m);
		x = max(1, x);
		int y = (k + 999999) / (2 * m + 1) + m;
		y = min(y, 999999);
		for (int j = x; j <= y; j++) {
			if ((j-m)*(2*m+1)-j >= k && (j-m)*(2*m+1) <= k + 999999) {
				cout << 2 * m + 1 << endl;
				int t = (j - m) * (2*m + 1) - k;
				cout << t << " " << -(t + 1) << " " << j << " ";
				for (int i = 1; i <= m - 1; i++) {
					cout << -(j + 1) << " " << j << " "; 
				}
				return 0;
			}
		}
	}
//	cout << -1;
	return 0;
}