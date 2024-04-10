#include <iostream>
using namespace std;

int main() {
	long long x, y, z;
	cin >> x;
	cin >> y;
	cin >> z;
	long long s = x + y;
	if (x / z + y / z == (x + y) / z) {
		cout << x / z + y / z << " " << 0;
	}
	else {
		if (x % z > y % z)
			swap(x, y);
		cout << (x + y) / z << " " << z - y % z;
	}
	return 0;
}