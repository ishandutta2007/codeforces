#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

#define DBG(v) cerr << #v << " = " << (v) << endl;

signed main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr), cout.tie(nullptr);

	string a, b;
	cin >> a >> b;

	bool odd = false;
	for (int i = 1; i < (int) b.size(); ++i)
		if (b[i] != b[i - 1])
			odd ^= 1;

	int cnt = 0;

	for (int i = 0; i < (int) b.size(); ++i)
		cnt += b[i] != a[i];

	int ans = cnt % 2 == 0;
	for (int i = 1; i + (int) b.size() <= (int) a.size(); ++i) {
		cnt += odd;
		cnt -= a[i - 1] != b[0];
		cnt += a[i + (int) b.size() - 1] != b.back();
		ans += cnt % 2 == 0;
	}
	cout << ans;
	return 0;
}