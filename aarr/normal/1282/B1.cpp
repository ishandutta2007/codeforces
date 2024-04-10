#include <iostream>
#include <algorithm>
using namespace std;

const int N = 200 * 1000 + 5;

int a[N];

int main() {
	ios :: sync_with_stdio(false);
	int t;
	cin >> t;
	for (int ii = 0; ii < t; ii++) {
		int n, p, k;
		cin >> n >> p >> k;
		int p2 = p;
		for (int i = 1; i <= n; i++) {
			cin >> a[i];
		}
		sort(a + 1, a + n + 1);
		if (a[1] > p) {
			cout << 0 << '\n';
			continue;
		}
		int ans = 0;
		int x = k;
		while (x <= n && p - a[x] >= 0) {
			p -= a[x];
			ans += k;
			x += k;
		}
	/*	x -= k - 1;
		while (p - a[x] >= 0 && x <= n) {
			p -= a[x];
			ans += 1;
			x += 1;			
		}*/
		int ans2 = 1, x2 = k + 1;
		p2 -= a[1];
		while (x2 <= n && p2 - a[x2] >= 0) {
			p2 -= a[x2];
			ans2 += k;
			x2 += k;
		}
		cout << max(ans, ans2) << endl;
	}
	return 0;
}