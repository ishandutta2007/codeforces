#include <iostream>
using namespace std;

int main() {
	long long n;
	cin >> n;
	if (n == 1) {
		cout << 1 << endl;
		return 0;
	}
	long long x = 0;
	for (int i = 2; 1ll * i * i <= n; i++) {
	//	if (i % 10000 == 0) {
	//		cout << i << endl;
	//	}
		if (n % i == 0) {
			if (x != 0) {
				cout << 1 << endl;
				return 0;
			}
			x = i;
			while (n % i == 0) {
				n /= i;
			}
		}
	}
	if (n != 1 && x != 0 && n != x) {
		cout << 1 << endl;
		return 0;
	}
	if (n == 1) {
		cout << x << endl;
	}
	else {
		cout << n << endl;
	}
	return 0;
}