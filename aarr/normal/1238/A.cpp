#include <iostream>
using namespace std;

int main() {
	int q;
	cin >> q;
	for (int i = 0; i < q; i++) {
		long long x, y;
		cin >> x >> y;
		if (x - y == 1) {
			cout << "NO" << endl;
		}
		else {
			cout << "YES" << endl;
		}
	}
	return 0;
}