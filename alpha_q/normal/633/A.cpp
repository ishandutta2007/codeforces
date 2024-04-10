#include <bits/stdc++.h>

using namespace std;

int a, b, c, i, num;

int main() {
	cin >> a >> b >> c;
	for (i = 0; i * a <= c; i++) {
		num = c - i * a;
		if (num % b == 0) {
			cout << "Yes" << endl;
			return 0;
		}
	}
	cout << "No" << endl;
	return 0;
}