#include <bits/stdc++.h>

using namespace std;

int main() {
	int a, b, c;
	cin >> a >> b >> c;
	for (int i = 0; a * i <= c; i++) {
		for (int j = 0; a * i + b * j <= c; j++) {
			if (a * i + b * j == c) {
				cout << "Yes" << endl;
				return 0;
			}
		}
	}
	cout << "No" << endl;
	return 0;
}