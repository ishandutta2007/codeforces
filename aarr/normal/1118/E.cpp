#include <iostream>
using namespace std;

int main() {
	int n, k;
	cin >> n >> k;
	if (n > 1ll * k * (k - 1)) {
		cout << "NO" << endl;
	}
	else {
		cout << "YES" << endl;
		int x = 0, y = 1;
		for (int i = 0; i < n; i++) {
			cout << x + 1 << " " << y + 1 << endl;
			x++;
			y++;
			x %= k;
			y %= k;
			if (x == 0) {
				y++;
			}
		}
	}
	return 0;
}