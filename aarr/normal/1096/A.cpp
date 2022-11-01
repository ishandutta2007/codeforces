#include <iostream>
using namespace std;

int main() {
	int t;
	cin >> t;
	for (int i = 1; i <= t; i++) {
		int l, r;
		cin >> l >> r;
		cout << l << " " << 2 * l << endl;
	}
	return 0;
}