#include <iostream>
using namespace std;

int main() {
	int n, x = 0;
	string s;
	cin >> n >> s;
	for (int i = 0; i < n; i++) {
		if (s[i] == '8') {
			x++;
		}
	}
	cout << min(x, n / 11);
	return 0;
}