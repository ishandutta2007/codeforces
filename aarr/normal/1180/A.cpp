#include <iostream>
using namespace std;

int main() {
	int x = 1, y = 0, n;
	cin >> n;
	for (int i = 1; i < n; i++) {
		y += 4;
		x += y;
		
	}
	cout << x;
	return 0;
}