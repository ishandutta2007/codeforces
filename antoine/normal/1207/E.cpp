#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define DBG(v) cerr << #v << " = " << (v) << endl;

signed main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr), cout.tie(nullptr);

	int ans = 0;
	for (int rep = 0; rep < 2; ++rep) {
		cout << "?";
		for (int i = 1; i <= 100; ++i)
			cout << ' ' << (i << (7 * rep));
		cout << endl;
		int resp;
		cin >> resp;
		if (!rep)
			ans |= (resp >> 7) << 7;
		else
			ans |= resp & ((1 << 7) - 1);
	}
	cout << "! " << ans;
	return 0;
}