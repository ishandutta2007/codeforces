#include <iostream>
#include <algorithm>
using namespace std;

int a[105];
int main() {
	int q;
	cin >> q;
	for (int i = 0; i < q; i++) {
		int l, r;
		cin >> l >> r;
		if (l % 2 == 1 && r % 2 == 0) {
			cout << (r - l + 1) / 2;
		}
		if (l % 2 == 0 && r % 2 == 1) {
			cout << -(r - l + 1) / 2;
		}
		if (l % 2 == 1 && r % 2 == 1) {
			cout << (r - l) / 2 - r;
		}
		if (l % 2 == 0 && r % 2 == 0) {
			cout << r - (r - l) / 2;
		}
		cout << endl;
	}
	return 0;
}