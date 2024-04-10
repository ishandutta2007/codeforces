#include <iostream>
using namespace std;

int main() {
	int a, b, c, d, e, f;
	cin >> a >> b >> c >> d >> e >> f;
	int ans = 0;
	for (int i = 0; i <= min(a, d); i++) {
		int j = min(min(d - i, b), c);
		ans = max(ans, i * e + j * f);
	}
	cout << ans << "\n";
	return 0;
}