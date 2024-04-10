#include <iostream>
using namespace std;

int main() {
	int x, y, z, t1, t2, t3;
	cin >> x >> y >> z >> t1 >> t2 >> t3;
	int a = abs(x - y) * t1;
	int b = abs(x - y) * t2 + abs(x - z) * t2 + 3 * t3;
	if (b <= a) {
		cout << "YES";
	}
	else {
		cout << "NO";
	}
	return 0;
}