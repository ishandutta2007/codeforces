#include <iostream>
using namespace std;



int main() {
	int n, mini, maxi, ans = 0;
	cin >> n >> mini;
	maxi = mini;
	for (int i = 2; i <= n; i++) {
		int x;
		cin >> x;
		if (x < mini) {
			mini = x;
			ans++;
		}
		if (x > maxi) {
			maxi = x;
			ans++;
		}
	}
	cout << ans;
	return 0;
}