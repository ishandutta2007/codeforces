#include <iostream>
using namespace std;



int main() {
	int n, m, k;
	cin >> n >> m >> k;
	int ans = n;
	for (int i = 1; i <= n; i++) {
		int x;
		cin >> x;
		if (x != 0 && x <= k) {
			int y = abs(m - i);
		//	cout << i << " " << y << endl;
			ans = min(ans, y);
		}
	}
	cout << ans * 10;
	return 0;
}