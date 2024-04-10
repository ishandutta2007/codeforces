#include <iostream>
using namespace std;

int a[105];
int main() {
	int n, k, ans = 0;
	cin >> n >> k;
	for (int i = 1; i <= n; i++) {
		cin >> a[i];
	}
	for (int i = 1; i <= n && a[i] <= k; i++) {
		ans++;
	}
	for (int i = n; i > 0 && a[i] <= k; i--) {
		ans++;
	}
	cout << min(ans, n);
	return 0;
}