#include <iostream>
using namespace std;

int main() {
	int x = 0, n, y = 0;
	cin >> n;
	string s;
	cin >> s;
	for (int i = 0; i < n; i++) {
		if (s[i] == '+') {
			y++;
		}
		else {
			y--;
		}
		x = min(x, y);
	}
	cout << y - x;
	return 0;
}