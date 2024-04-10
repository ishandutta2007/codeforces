#include <iostream>
using namespace std;

int main() {
	int n ;
	cin >> n;
	int s = 0, x = 0;
	for (int i = 0; i < n; i++) {
		int a;
		cin >> a;
		s += a;
		x += a % 2;
	}
	if (s % 2) {
		cout << x;
	}
	else {
		cout << n - x;
	}
	return 0;
}