#include <iostream>
using namespace std;

int main() {
	int a, b, x = 0, y = 0, z = 0;
	cin >> a >> b;
	for (int i = 1; i <= 6; i++) {
		int e = abs(a - i), f = abs(i - b);
		if (e < f)
			x++;
		if (e == f)
			y++;
		if (f < e)
			z++;
	}
	cout << x << " " << y << " " << z << endl;
	return 0;
}