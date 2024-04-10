#include <iostream>
using namespace std;

int a[55];

int main() {
	int n, h, m;
	cin >> n >> h >> m;
	for (int i = 1; i <= n; i++) {
		a[i] = h;
	}
	for (int i = 0; i < m; i++) {
		int l, r, x;
		cin >> l >> r >> x;
		for (int j = l; j <= r; j++) {
			a[j] = min(a[j], x);
		}
	}
	int ans = 0;
	for (int i = 1; i <= n; i++) {
		ans += a[i] * a[i];
	}
	cout << ans;
	return 0;
}