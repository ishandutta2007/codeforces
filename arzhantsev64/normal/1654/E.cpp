#pragma GCC optimize("O3", "unroll-loops")
#pragma GCC target("sse4.2")

#include <bits/stdc++.h>

using namespace std;

signed main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	int n;
	cin >> n;
	vector<int> v(n);
	for (int i = 0; i < n; ++i)
		cin >> v[i];

	int D = 1000;
	int d = (1e5 / D) + 10;
	unordered_map<int, int> cnt;
	int ans = n;
	for (int a = -d; a <= d; ++a) {
		cnt.clear();
		for (int j = 0; j < n; ++j) {
			int b = v[j] - a * j;
			if (cnt.find(b) == cnt.end())
				cnt[b] = 0;
			cnt[b]++;
			ans = min(ans, n - cnt[b]);
		}
	}

	for (int i = 0; i < n; i += D) {
		for (int j = 0; i + j < n && j < D; ++j)
			for (int k = 1; i + j + k < n && k < D; ++k) {
				int i1 = i + j;
				int i2 = i + j + k;
				if (abs(v[i2] - v[i1]) % (i2 - i1) != 0)
					continue;
				int a = (v[i2] - v[i1]) / (i2 - i1);
				int b = v[i1] - a * i1;
				if (abs(a) < d)
					continue;
				int cnt = 0;
				for (int t = i; t < n && t - i <= 2 * D; ++t)
					if (v[t] == a * t + b)
						cnt++;
				ans = min(ans, n - cnt);
			}
	}
	cout << ans << endl;

	return 0;
}