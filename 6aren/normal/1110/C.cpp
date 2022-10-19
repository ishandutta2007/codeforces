#include <bits/stdc++.h>

using namespace std;

int n;

int main() {
	cin >> n;
	while (n--) {
		int a, pow = 1;
		cin >> a;
		while (pow <= a) {
			pow *= 2;
		} 
		if (pow - 1 == a) {
			bool check = false;
			for (int i = 3; i * i <= pow - 1; i++) {
				if ((pow - 1) % i == 0) {
					cout << (pow - 1) / i << endl;
					check = true;
					break;
				}
			}
			if (!check) {
				cout << 1 << endl;
			}
		} else {
			cout << pow - 1 << endl;
		}
	}
	return 0;
}