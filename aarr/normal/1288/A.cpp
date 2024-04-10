#include <bits/stdc++.h>
using namespace std;

int main() {
	ios :: sync_with_stdio(false);
	int t;
	cin >> t;
	for (int i = 0; i < t; i++) {
		int n, d;
		cin >> n >> d;
		int x = n / 2;
		bool b = false;
		if (n >= d) {
			b = true;
		}
		for (int j = max(x - 2, 0); j <= x + 2 && j <= n; j++) {
			int y = (int) ceil((double) d / (x + 1));
			if (x + y <= n) {
				b = true;
			}
		}
		if (b) {
			cout << "YES" << endl;
		}
		else {
			cout << "NO" << endl;
		}
	}
	return 0;
}