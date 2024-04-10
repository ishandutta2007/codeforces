#include <iostream>
using namespace std;

int main() {
	ios :: sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	int n, m, x = 0, y = 0;
	cin >> n;
	cin >> m;
	for (int i = 1; i <= n / 2; i++) {
		for (int j = 1; j <= m; j++) {
			cout << i << " " << j << "\n";
			cout << n - i + 1 << " " << m - j + 1 << "\n";
			x += 2;
		}
	}
	if (n % 2 == 1) {
		for (int j = 1; j <= m / 2; j++) {
			cout << n / 2 + 1 << " " << j << "\n";
			cout << n / 2 + 1 << " " << m - j + 1 << "\n";
			x += 2;
		}
		if (m % 2 == 1) {
			cout << n / 2 + 1 << " " << m / 2 + 1 << "\n";
			x++;
 		}
	}
	if (x != n * m) {
		x /= y;
		cout << x;
	}
	return 0;
}