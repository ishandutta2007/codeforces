#include <bits/stdc++.h>
#define endl '\n'
using namespace std;




int main() {
	ios :: sync_with_stdio(false);
	int t;
	cin >> t;
	for (int ii = 0; ii < t; ii++) {
		int n;
		cin >> n;
		for (int i = 0; i < n; i++) {
			int x;
			cin >> x;
			if (x < 0) {
				x = -x;
			}
			if (i % 2) {
				cout << -x << " ";
			}
			else {
				cout << x << " ";
			}
		}
		cout << endl;
	}
	
	return 0;
}