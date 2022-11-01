#include <iostream>
using namespace std;

int main() {
	ios :: sync_with_stdio(false);
	int t;
	cin >> t;
	for (int i = 0; i < t; i++) {
		long long a, b, c, r;
		cin >> a >> b >> c >> r;
		if (a > b) {
			swap(a, b);
		}
		long long x = c - r, y = c + r;
		if (y <= a || b <= x) {
			cout << abs(b - a) << endl;
			continue;
		}
		long long ans = 0;
		if (y <= b) {
			ans += b - y;
		}
		if (a <= x) {
			ans += x - a;
		}
		cout << ans << endl;
	}
	return 0;
}