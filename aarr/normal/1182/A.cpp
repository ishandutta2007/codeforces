#include <iostream>
using namespace std;

int main() {
	int n;
	cin >> n;
	if (n % 2 == 1) {
		cout << 0;
	}
	else {
		n /= 2;
		cout << (1 << n);
	}
	return 0;
}