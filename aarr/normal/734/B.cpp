#include <iostream>
using namespace std;

int main() {
	int a, b, c, d;
	cin >> a >> b >> c >> d;
	int x = min(a, c);
	x = min(x, d);
	cout << x * 256 + min(b, a - x) * 32 << endl;
	return 0;
}