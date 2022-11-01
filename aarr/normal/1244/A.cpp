#include <bits/stdc++.h>
using namespace std;

int main() {
	int t;
	cin >> t;
	for (int i = 0; i < t; i++) {
		int a, b, c, d, k;
		cin >> a >> b >> c >> d >> k;
		int x = (int) ceil((double) a / c);
		int y = (int) ceil((double) b / d);
		if (x + y > k) {
			cout << -1 << endl;
		}
		else{
			cout << x << " " << k - x << endl;
		}
	}
	return 0;
}