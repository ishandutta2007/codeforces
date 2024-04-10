#include <iostream>
using namespace std;



int main() {
	int n, k, ans = 0;
	cin >> n >> k;
	for (int i = 0; i < n; i++) {
		int x;
		cin >> x;
		if (5 - x >= k) {
			ans++;
		}
	}
	cout << ans / 3;
	return 0;
}