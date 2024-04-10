#include <iostream>
using namespace std;

int main() {
	int n;
	cin >> n;
	if (n % 10 > 5) {
		cout << n / 10 * 10 + 10;
	}
	else {
		cout << n / 10 * 10;
	}
	return 0;
}