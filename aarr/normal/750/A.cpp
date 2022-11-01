#include <iostream>
using namespace std;

int main() {
	int n, k;
	cin >> n >> k;
	int ans = 0, s = 0;
	for (int i = 1; i <= n; i++) {
		s += 5 * i;
		if (s <= 240 - k)
			ans = i;
	}
	cout << ans;
	return 0;
}