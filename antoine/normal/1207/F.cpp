#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define DBG(v) cerr << #v << " = " << (v) << endl;

const int MxQ = (int) 5e5 + 9;
const int MxS = (int) sqrt(MxQ) + 2;
int a[MxQ + 9];
ll dp[MxS + 2][MxS + 2];

signed main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr), cout.tie(nullptr);

	int q;
	cin >> q;
	const int s = (int) sqrt(q);
	assert(1 <= s && s <= MxS);

	while (q--) {
		int type, x, y;
		cin >> type >> x >> y;
		if (type == 1) {
			a[x] += y;
			for (int i = s; i >= 1; --i)
				dp[i][x % i] += y;
		} else {
			assert(type == 2);
			ll ans = 0;
			if (x <= s)
				ans = dp[x][y];
			else {
				for (int i = y; i < MxQ; i += x)
					ans += a[i];
			}
			cout << ans << '\n';
		}
	}
	return 0;
}