#include <bits/stdc++.h>
#define int long long
using namespace std;

signed main() {
	int a, b, x;
	cin >> a >> b >> x;
	vector<int> arr(x + 1, 1);
	int cur;
	if (a > b) {
		cur = 0;
		a -= (x + 2) / 2;
		b -= (x + 1) / 2;
	} else {
		cur = 1;
		b -= (x + 2) / 2;
		a -= (x + 1) / 2;
	}
	int c = cur;
	if (a > 0) {
		if (c == 0) {
			arr[0] += a;
		} else {
			arr[1] += a;
		}
	}
	if (b > 0) {
		if (c == 0) {
			arr[1] += b;
		} else {
			arr[0] += b;
		}
	}
	for (int i = 0; i < x + 1; i++) {
		for (int j = 0; j < arr[i]; j++) {
			cout << c;
		}
		c = 1 - c;
	}
	cout << endl;
	return 0;
}