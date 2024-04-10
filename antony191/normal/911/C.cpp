#include <iostream>
#include <algorithm>


using namespace std;

int main() {
	int a, b, c;
	cin >> a >> b >> c;
	int x, y, z;
	x = max(max(a, b), c);
	z = min(min(a, b), c);
	y = a + b + c - z - x;
	if (z > 3)
		cout << "NO";
	else {
		if (z == 1)
			cout << "YES";
		else {
			if (z == 2)
				if (y == 2 || (y == 4 && x == 4))
					cout << "YES";
				else
					cout << "NO";
			else
				if (x == 3)
					cout << "YES";
				else
					cout << "NO";
		}
	}
	return 0;
}