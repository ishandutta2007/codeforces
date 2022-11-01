#include <iostream>
#include <cmath>
using namespace std;



int main() {
	int x = 0, y = 0, n;
	for (int i = 0; i < 3; i++) {
		int a;
		cin >> a;
		x += a;
	}
	for (int i = 0; i < 3; i++) {
		int a;
		cin >> a;
		y += a;
	}
	cin >> n;
	int m = (int) ceil((double) x / 5);
	m += (int) ceil((double) y / 10);
	if (m <= n) {
		cout << "YES";
	}
	else {
		cout << "NO";
	}
	return 0;
}