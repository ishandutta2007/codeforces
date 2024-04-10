#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define DBG(v) cerr << #v << " = " << (v) << endl;

int f() {

	int x, y, z;
	cin >> x >> y >> z;

	int lo = x - z - y;
	int hi = x + z - y;
	lo = max(1, lo);

	if (lo > hi)
		return 0;
	if (lo % 2 == (x + y + z) % 2)
		return (hi - lo + 1 + 1) / 2;
	return (hi - lo + 1) / 2;
}
signed main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr), cout.tie(nullptr);

	int t;
	cin >> t;
	while (t--) {
		cout << f() << '\n';
	}
	return 0;
}