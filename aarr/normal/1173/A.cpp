#include <iostream>
using namespace std;

int main() {
	int x, y, z;
	cin >> x >> y >> z;
	if (x > y + z) {
		cout << '+';
		return  0;
	}
	if (y > x + z) {
		cout << '-';
		return 0;
	}
	if (z == 0 && x == y) {
		cout << '0';
		return 0;
	}
	cout << '?';
	return 0;
}