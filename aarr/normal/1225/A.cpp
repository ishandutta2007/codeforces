#include <iostream>
using namespace std;



int main() {
	bool b = false;
	int x, y;
	cin >> x >> y;
	if (x == y) {
		cout << x << "1 " << x << 2;
		b = true;
	}
	if (y == x + 1) {
		cout << x << "9 " << y << 0;
		b = true;
	}
	if (x == 9 && y == 1) {
		cout << "99 100";
		b = true;
	}
	if (!b) {
		cout << -1;
	}
	return 0;
}