#include <iostream>
using namespace std;


int a[100 * 1000 + 5];

int main() {
	int n;
	cin >> n;
	int x = 0, ans = 0;
	for (int i = 1; i <= n; i++) {
		cin >> a[i];
		if (a[i] > a[i - 1]) {
			x++;
		}
		else {
			x = 1;
		}
		ans = max(ans, x);
	}
	cout << ans;
	return 0;
}