#include <bits/stdc++.h>
using namespace std;

const int N = 200 * 1000 + 5;

int a[N];

int main() {
	ios :: sync_with_stdio(false);
	int t;
	cin >> t;
	for (int ii = 0; ii < t; ii++) {
		int n;
		cin >> n;
		bool b = false;
		for (int i = 1; i <= n; i++) {
			cin >> a[i];
			if (i > 1 && a[i] != a[i - 1]) {
				b = true;
			}
		}
		if (b) {
			cout << "1\n";
		}
		else {
			cout << n << endl;
		}
	}
	return 0;
}