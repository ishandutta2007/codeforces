#include <bits/stdc++.h>
using namespace std;


long long get(long long x, int y) {
	return (x >> y) & 1;
}
int main() {
	long long x, y;
	cin >> x >> y;
	if (x == 0 && y == 0) {
		cout << 0;
		return 0;
	}
	if ((x + y) % 2 == 1 || x > y) {
		cout << -1;
		return 0;
	}
	if (x == y) {
		cout << 1 << endl << x;
		return 0;
	}
	long long z = 0;
	for (int i = 1; i < 60; i++) {
		if (get(x, i) != get(y, i)) {
			z |= (1ll << (i - 1));
		}
	}
//	cout << z << endl;
	if (z + (z ^ x) == y) {
		cout << 2 << endl << z << " " << (z ^ x);
	}
	else {
		cout << 3 << endl << x << " " << (y - x) / 2 << " " << (y - x) / 2;
	}
	return 0;
}