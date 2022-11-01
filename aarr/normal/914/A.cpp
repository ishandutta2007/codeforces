#include <iostream>
#include <cmath>
using namespace std;

int a[105], b[105];

int main() {
	int n, ans = -1000 * 1000 - 5;
	cin >> n;
	for (int i = 0; i < n; i++) {
		int x;
		cin >> x;
		int y = sqrt(x);
		if (x < 0 || y * y != x) {
			ans = max(ans, x);
		}
	}
	cout << ans;
	return 0;
}