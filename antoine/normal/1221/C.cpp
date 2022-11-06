#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define DBG(v) cerr << #v << " = " << (v) << endl;

signed main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr), cout.tie(nullptr);

	int q;
	cin >> q;
	while (q--) {
		int a, b, x;
		cin >> a >> b >> x;
		if (a > b)
			swap(a, b);
		x += b - a;
		b = a;
		x = min(x, a);
		int ans = x;
		a -= x, b -= x, x = 0;
		ans += (a + b) / 3;
		cout << ans << '\n';
	}
	return 0;
}