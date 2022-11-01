#include <iostream>
using namespace std;



int main() {
	int n;
	cin >> n;
	if (n > 0) {
		cout << n;
	}
	else {
		if (abs(n) % 10 > abs(n) / 10 % 10) {
			cout << n / 10;
		}
		else {
			cout << - (abs(n) / 100 * 10 + abs(n) % 10);
		}
	}
	return 0;
}