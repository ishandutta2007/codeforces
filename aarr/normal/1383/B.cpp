#include <bits/stdc++.h>
using namespace std;

const int N = 100 * 1000 + 5, LG = 31;

int get(int x, int y) {
	return (x >> y) & 1;
}

int a[N];

int main() {
	ios :: sync_with_stdio(false);
	int t;
	cin >> t;
	for (int ii = 0; ii < t; ii++) {
		int n;
		cin >> n;
		for (int i = 0; i < n; i++) {
			cin >> a[i];
		}
		bool b = false;
		for (int j = LG; j >= 0; j--) {
			int c = 0;
			for (int i = 0; i < n; i++) {
				if (get(a[i], j)) {
					c++;
				}
			}
			if (c % 2) {
				if (c % 4 == 1 || (n - c) % 2 == 1) {
					cout << "WIN\n";
				}		
				else {
					cout << "LOSE\n";
				}
				b = true;
				break;
			}
		}
		if (!b)
			cout << "DRAW\n";
	}
	
	return 0;
}