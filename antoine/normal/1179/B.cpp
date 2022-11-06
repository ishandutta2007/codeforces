#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

#define DBG(v) cerr << #v << " = " << (v) << endl;

signed main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr), cout.tie(nullptr);

	int n, m;
	cin >> n >> m;

	for (int j = 1, k = m; j <= k; ++j, --k) {

		for (int i = 1; i <= n; ++i) {
			if (j == k && i > n + 1 - i)
				break;
			cout << i << ' ' << j << '\n';
			if (j == k && i == n + 1 - i)
				break;
			cout << n + 1 - i << ' ' << k << '\n';
		}

	}

	return 0;
}