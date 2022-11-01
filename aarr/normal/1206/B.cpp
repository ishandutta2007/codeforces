#include <iostream>
using namespace std;



int main() {
	int n, x = 0, y = 0, z = 0;
	long long ans = 0;
	cin >> n;
	for (int i = 0; i < n; i++) {
		int a;
		cin >> a;
		if (a == 0) {
			z++;
			ans++;
		}
		if (a > 0) {
			ans += a - 1;
			x++;
		}
		if (a < 0) {
			ans -= a + 1;
			y++;
		}
	}
	if (z > 0 || y % 2 == 0) {
		cout << ans;
	}
	else {
		cout << ans + 2;
	}
	return 0;
}