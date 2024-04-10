#include <iostream>
using namespace std;



int main() {
	int n, ans = 0;
	cin >> n;
	for (int i = 1; i <= n; i++) {
		int c = 0, x = i;
		for (int j = 2; j <= x; j++) {
			if (x % j == 0) {
				c++;
			}
			while (x % j == 0) {
				x /= j;
			}
		}
		if (c == 2) {
			ans++;
		}
	}
	cout << ans;
	return 0;
}