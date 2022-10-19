#include<bits/stdc++.h>
#define int long long
using namespace std;
signed main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int t;
	cin >> t;
	for (int i = 0; i < t; ++i) {
		int a, b;
		cin >> a >> b;
		vector<int> c;
		for (int j = 0; j < a * b; ++j) {
			if (j % a % b != j % b % a)
				c.push_back(j);
		}
		int q;
		cin >> q;
		vector<int> ans1(q);
		for (int j = 0; j < q; ++j) {
			int l, r;
			cin >> l >> r;
			int l2, r2;
			r2 = r / (a * b) * a * b;
			l2 = l / (a * b) * a * b;
			if (l2 < l)
				l2 += a * b;
			int ans = 0;
			if (r2 >= l2) {
				ans = ans + (r2 / (a * b) - l2 / (a * b)) * c.size();
				int l1 = -1, r1 = c.size();
				while (l1 < r1 - 1) {
					int m = (l1 + r1) / 2;
					if (c[m] > r%(a*b))
						r1 = m;
					else
						l1 = m;
				}
				ans += l1 + 1;
				l1 = -1;
				r1 = c.size();
				if (l % (a * b) != 0) {
					while (l1 < r1 - 1) {
						int m = (l1 + r1) / 2;
						if (c[m] < l % (a * b))
							l1 = m;
						else
							r1 = m;
					}
					ans += c.size() - r1;
				}
				ans1[j] = ans;
			}
			else {
				int l1 = -1, r1 = c.size();
				while (l1 < r1 - 1) {
					int m = (l1 + r1) / 2;
					if (c[m] < l % (a * b))
						l1 = m;
					else
						r1 = m;
				}
				int r3 = r1;
				l1 = -1;
				r1 = c.size();
				while (l1 < r1 - 1) {
					int m = (l1 + r1) / 2;
					if (c[m] > r % (a * b))
						r1 = m;
					else
						l1 = m;
				}
				int l3 = l1;
				if (l3 >= r3)
					ans += l3 - r3 + 1;
				ans1[j] = ans;
			}
		}
		for (int j = 0; j < q; ++j)
			cout << ans1[j] << ' ';
		cout << "\n";
	}
	return 0;
}