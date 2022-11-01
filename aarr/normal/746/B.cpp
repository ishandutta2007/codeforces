#include <iostream>
#include <algorithm>
using namespace std;

char c[2005];

int main() {
	string s;
	int n;
	cin >> n >> s;
	if (n % 2 == 0) {
		for (int i = 0; i < s.size(); i++) {
			if (i % 2 == 0) {
				c[n / 2 - i / 2 - 1] = s[i];
			}
			else {
				c[n / 2 + i / 2] = s[i];
			}
		}
	}
	else {
		for (int i = 0; i < s.size(); i++) {
			if (i % 2 == 0) {
				c[n / 2 - i / 2] = s[i];
			}
			else {
				c[n / 2 + i / 2 + 1] = s[i];
			}
		}
		reverse(c, c + n);
	}
	for (int i = 0; i < n; i++) {
		cout << c[i];
	}
	return 0;
}