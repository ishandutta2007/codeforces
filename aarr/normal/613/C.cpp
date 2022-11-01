#include <iostream>
using namespace std;

const int N = 30;

int c[N];

int bmm(int x, int y) {
	if (y == 0) {
		return x;
	}
	return bmm(y, x % y);
}

int main() {
	int n, k = 0, x, o = 0;
	cin >> n;
	x = n;
	for (int i = 0; i < n; i++) {
		cin >> c[i];
		if (c[i] % 2) {
			o++;
			x = i;
		}
		
	}
	if (o > 1) {
		cout << "0\n";
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < c[i]; j++) {
				cout << (char) ('a' + i);
			}
		}
	}
	if (o == 0) {
		for (int i = 0; i < n; i++) {
			if (__builtin_ctz(c[i]) < __builtin_ctz(c[x])) {
				x = i;
			}
		}	
		
	}
	k = c[x];
	for (int i = 0; i < n; i++) {
		if (i != x) {
			k = bmm(k, c[i] / 2);
		}
	}
	if (o <= 1) {
		if (o == 0 && c[x] / k % 2 == 0) 
			cout << k * 2 << endl;
		else
			cout << k << endl;
		for (int ii = 0; ii < k; ii++) {
			for (int i = 0; i < n; i++) {
				if (i != x) {
					for (int j = 0; j < c[i] / k / 2; j++) {
						cout << (char) ('a' + i);
					}
				}
			}
			for (int j = 0; j < c[x] / k; j++) {
				cout << (char) ('a' + x);
			}
			for (int i = n - 1; i >= 0; i--) {
				if (i != x) {
					for (int j = 0; j < c[i] / k / 2; j++) {
						cout << (char) ('a' + i);
					}
				}
			}
		}
	}
	return 0;
}