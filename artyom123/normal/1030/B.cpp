#include <bits/stdc++.h>
using namespace std;

int main() {
	int n, d;
	cin >> n >> d;
	int m;
	cin >> m;
	while (m--) {
		int x, y;
		cin >> x >> y;
		if (x + y < d || x + y > 2 * n - d) {
			cout << "NO" << "\n";
			continue;
		}
		if (x - y > d || x - y < -d) {
			cout << "NO" << "\n";
			continue;
		}
		cout << "YES" << "\n";
	}
	return 0;
}