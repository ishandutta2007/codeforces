#include <bits/stdc++.h>
using namespace std;
int main() {
	int n, p;
	cin >> n >> p;
	for (int c = 1; c <= 1000000; c++) {
		int t = n - p * c;
		if (t >= 0 && __builtin_popcount(t) <= c && c <= t) {
			cout << c << endl;
			return 0;
		}
	}
	cout << -1 << endl;
	return 0;
}