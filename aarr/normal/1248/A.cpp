#include <iostream>
using namespace std;

int main() {
	int t;
	cin >> t;
	for (int i = 0; i < t; i++) {
		int n, m, a = 0, b = 0;
		cin >> n;
		for (int j = 0; j < n; j++) {
			int x;
			cin >> x;
			a += x % 2;
		}
		cin >> m;
		for (int j = 0; j < m; j++) {
			int x;
			cin >> x;
			b += x % 2;
		}
		cout << 1ll * a * b + 1ll * (n - a) * (m - b) << endl;
	}
	return 0;
}