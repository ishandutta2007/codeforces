#include <iostream>
using namespace std;



int main() {
	int t;
	cin >> t;
	for (int i = 0; i < t; i++) {
		int n;
		cin >> n;
		if (n % 2) {
			cout << 7;
			n -= 3;
		}
		for (int i = 0; i < n / 2; i++) {
			cout << 1;
		}
		cout << endl;
	}
	return 0;
}