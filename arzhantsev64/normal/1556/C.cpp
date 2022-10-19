#pragma GCC optimize("O3", "unroll-loops")
#pragma GCC target("sse4.2")

#include <bits/stdc++.h>

using namespace std;

#define int long long

signed main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	int n;
	cin >> n;
	vector<pair<int, int>> downs;

	int b = 0;
	int minn = 0;
	int ans = 0;
	for (int i = 0; i < n; ++i) {
		int x;
		cin >> x;
		if (i % 2 == 0) {
			b += x;
		} else {
			ans += min(b - minn, x);
			b -= x;
			if (b <= minn) {
				if (minn != 0)
					ans -= 1;
				minn = b;
			}
			bool flag = 0;
			while (!flag && !downs.empty() && downs.back().first >= b) {
				int val = downs.back().first;
				int cnt = downs.back().second;
				ans += cnt;
				if (val > b)
					downs.pop_back();
				if (val == b)
					flag = 1;
			}
			if (!downs.empty() && downs.back().first == b) {
				int val = downs.back().first;
				int cnt = downs.back().second;
				downs.pop_back();
				downs.push_back({val, cnt + 1});
			} else {
				downs.push_back({b, 1});
			}
			// cout << ans << endl;
			// cout << downs.size() << endl;
		}
	}
	cout << ans << endl;

	return 0;
}

// (((()(()))(