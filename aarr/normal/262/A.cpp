#include <iostream>
using namespace std;

int main() {
	int n, k, ans = 0;
	cin >> n >> k;
	for (int i = 0; i < n; i++) {
		int x, cnt = 0;
		cin >> x;
		while (x > 0) {
			if (x % 10 == 7 || x %  10 == 4) {
				cnt++;
			}
			x /= 10;
		}
		if (cnt <= k)
			ans++;
	}
	cout << ans;
	return 0;
}