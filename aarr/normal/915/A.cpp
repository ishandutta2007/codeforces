#include <iostream>
using namespace std;

int main() {
	int n, k;
	cin >> n >> k;
	int ans = k;
	for (int i = 0; i < n; i++) {
		int a;
		cin >> a;
		if (k % a == 0) {
			ans = min(ans, k / a);
		}
	}
	cout << ans;
	return 0;
}