#include <iostream>
using namespace std;



int main() {
	long long a, b, x, y, z;
	cin >> a >> b >> x >> y >> z;
	cout << max(x * 2 + y - a, 0ll) + max(z * 3 + y - b, 0ll);
	return 0;
}