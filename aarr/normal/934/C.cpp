#include <iostream>
using namespace std;

const int N = 100 * 1000 + 5;

int a[N];
int ps[N];
int main() {
	int n;
	cin >> n;
	for (int i = 1; i <= n; i++) {
		cin >> a[i];
		ps[i] = ps[i - 1];
		if (a[i] == 1) {
			ps[i]++;
		}
	}
	int ans = 0;
	for (int i = 1; i <= n; i++) {
		int x = 0, y = 0;
		for (int j = i; j <= n; j++) {
			x = max(x, 2 * (ps[j] - ps[i]) - j + i);
		}
		for (int j = 0; j <= i; j++) {
			y = max(y, i - j - 2 * (ps[i] - ps[j]));
		}
	//	cout << i << " " << x << " " << y << endl;
		ans = max(ans, n - i - ps[n] + 2 * ps[i] + x + y);
	}
	cout << ans << endl;
	return 0;
}