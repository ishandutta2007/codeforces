#include <iostream>
using namespace std;

int main() {
	int q;
	cin >> q;
	for (int i = 0; i < q; i++) {
		int a;
		cin >> a;
		int now = 1;
		while (now <= a) {
			now <<= 1;
		}
		if (a != now - 1) {
			cout << now - 1 << "\n";
		}
		else {
			int ans = 1;
			for (int i = 2; i * i <= a; i++) {
				if (a % i == 0) {
					ans = max(ans, a / i);
				}
			}
			cout << ans << "\n";
		}
	}
	return 0;
}