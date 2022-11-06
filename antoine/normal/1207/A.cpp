#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define DBG(v) cerr << #v << " = " << (v) << endl;

signed main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr), cout.tie(nullptr);

	int t;
	cin >> t;
	while (t--) {
		int n, a, b, x, y;
		cin >> n >> a >> b >> x >> y;
		n /= 2;
		if (x < y) {
			swap(x, y);
			swap(a, b);
		}

		a = min(a, n);
		b = min(b, n - a);
		cout << a*x + b*y << '\n';
	}
	return 0;
}