#include <iostream>
using namespace std;

int main() {
	int q;
	cin >> q;
	for (int i = 0; i < q; i++) {
		int x, y, z;
		cin >> x >> y >> z;
		int a = min(x + y, z), b = min(y + z, x), c = min(x + z, y);
		int ans = (x + y + z) / 2;
		ans = min(ans, x + y);
		ans = min(ans, x + z);
		ans = min(ans, y + z);
		cout << ans << endl;
	}
	return 0;
}