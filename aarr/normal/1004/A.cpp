#include <iostream>
#include <algorithm>
using namespace std;

int a[105];
int main() {
	int n, d, ans = 2;
	cin >> n >> d;
	for (int i = 0; i < n; i++) {
		cin >> a[i];
	}
	sort(a, a + n);
	for (int i = 1; i < n; i++) {
		if (a[i] - a[i - 1] > 2 * d) {
			ans += 2;
		}
		if (a[i] - a[i - 1] == 2 * d) {
			ans++;
		}
	}
	cout << ans;
	return 0;
}