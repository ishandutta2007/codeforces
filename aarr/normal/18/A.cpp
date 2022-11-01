#include <iostream>
using namespace std;

bool right(int x1, int y1, int x2, int y2, int x3, int y3) {
	if (x1 == x2 && y1 == y2)
		return false;
	if (x1 == x3 && y1 == y3)
		return false;
	if (x2 == x3 && y2 == y3)
		return false;
	int a = (x1 - x2) * (x1 - x2) + (y1 - y2) * (y1 - y2);
	int b = (x2 - x3) * (x2 - x3) + (y2 - y3) * (y2 - y3);
	int c = (x1 - x3) * (x1 - x3) + (y1 - y3) * (y1 - y3);
//	cout << "73 " << a << " " << b << " " << c << endl;
	if (a == b + c)
		return true;
	if (b == a + c)
		return true;
	if (c == a + b)
		return true;
	return false;

}
int a[10];
int main() {
	for (int i = 1; i <= 6; i++) {
		cin >> a[i];
	}
	if (right(a[1], a[2], a[3], a[4], a[5], a[6]))
		cout << "RIGHT" << endl;
	else {
		bool b = false;
		for (int i = 1; i <= 6; i++) {
			a[i]++;
			if (right(a[1], a[2], a[3], a[4], a[5], a[6]))
				b = true;
			a[i] -= 2;
			if (right(a[1], a[2], a[3], a[4], a[5], a[6]))
				b = true;
			a[i]++;
		}
		if (b)
			cout << "ALMOST" << endl;
		else
			cout << "NEITHER" << endl;
	}

	return 0;
}