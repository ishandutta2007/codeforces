#include <iostream>
using namespace std;

int main() {
	ios :: sync_with_stdio(false);
	int a, b, c, d, e, f;
	cin >> a >> b >> c >> d >> e >> f;
	int ans = min(a, d) * e;
	int x = min(b, c);
	ans = max(ans, min(x, d) * f);
	if (a < d) {
		int y = min(x, d - a);
		ans = max(ans, a * e + y * f);
	}
	if (x < d) {
		int z = min(a, d - x);
		ans = max(ans, x * f + z * e);
	}
	cout << ans << endl;
	return 0;
}