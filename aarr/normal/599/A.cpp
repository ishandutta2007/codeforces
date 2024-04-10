#include <iostream>
using namespace std;

int main() {
	int x, y, z;
	cin >> x >> y >> z;
	int ans = min(2 * (x + y), x + y + z);
	ans = min(ans, 2 * (y + z));
	ans = min(ans, 2 * (x + z));
	cout << ans;
	return 0;
}