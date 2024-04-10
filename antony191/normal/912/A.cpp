#include <iostream>
#include <vector>
#include <string>
#include <algorithm>


using namespace std;

int main() {
	long long a, b, x, y, z;
	cin >> a >> b >> x >> y >> z;
	long long a1 = 2 * x + y;
	long long b1 = y + 3 * z;
	long long s = 0;
	if (a1 > a)
		s += a1 - a;
	if (b1 > b)
		s += b1 - b;
	cout << s;
	return 0;
}