#include <iostream>
using namespace std;

int main() {
	int n, k;
	cin >> n >> k;
	char c;
	cin >> c;
	if (n == 1 && k > 0) {
		cout << 0;
		return 0;
	}
	if (c == '1')
		cout << 1;
	else {
		if (k > 0) {
			cout << 1;
			k--;
		}
		else {
			cout << c;
		}
	}
	for (int i = 1; i < n; i++) {
		char c;
		cin >> c;
		if (c == '0')
			cout << 0;
		else {
			if (k > 0) {
				cout << 0;
				k--;
			}
			else {
				cout << c;
			}
		}
	}
	return 0;
}