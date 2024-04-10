#include <iostream>
using namespace std;

int a[105];
int main() {
	int n, mini = 105, maxi = 0;
	cin >> n;
	for (int i = 1; i <= n; i++) {
		cin >> a[i];
		maxi = max(maxi, a[i]);
		mini = min(mini, a[i]);
	}
	int x, y;
	bool b = false;
	for (int i = 1; i <= n; i++) {
		if (a[i] == mini) {
			y = i;
		}
		if (a[i] == maxi && !b) {
			b = true;
			x = i;
		}
	}
	int ans = x + n - y - 1;
//	cout << x << " " << y << endl;
	if (x > y) {
		ans--;
	}
	cout << ans;
	return 0;
}