#include <iostream>
using namespace std;

int main() {
	ios :: sync_with_stdio(false);
	int t;
	cin >> t;
	for (int ii = 0; ii < t; ii++) {
		int n, m, p;
		cin >> n >> m >> p;
		bool b = false;
		for (int i = 0; i < m; i++) {
			int x;
			cin >> x;
			if (x == n) {
				b = true;
			}
		}
		for (int i = 0; i < p; i++) {
			int x;
			cin >> x;
		}
		if (b) {
			cout << "YES" << '\n';
		}
		else {
			cout << "NO" << '\n';
		}
	}
	return 0;
}