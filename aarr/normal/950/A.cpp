#include <iostream>
using namespace std;



int main() {
	int l, r, a;
	cin >> l >> r >> a;
	if (l > r) {
		swap(l, r);
	}
	if (l + a <= r) {
		cout << 2 * (l + a);
	}
	else {
		cout << (l + r + a) / 2 * 2;
	}
	return 0;
}