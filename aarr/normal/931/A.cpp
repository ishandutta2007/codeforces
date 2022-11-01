#include <iostream>
using namespace std;

int main() {
	int a, b;
	cin >> a >> b;
	int x = abs(a - b) / 2, y = abs(a - b) - x;
	cout << x * (x + 1) / 2 + y * (y + 1) / 2;
	return 0;
}