#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

#define DBG(v) cerr << #v << " = " << (v) << endl;

signed main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr), cout.tie(nullptr);

	int n;
	cin >> n;
	vector<int> a(n);
	vector<bool> b(n);
	for (int i = 0; i < n; ++i) {
		double x;
		cin >> x;
		a[i] = (int) floor(x);
		b[i] = x == a[i];
	}

	int lo = 0, hi = n;

	while (lo <= hi) {
		const int mid = (lo + hi) / 2;

		{
			int temp = mid;
			ll sum = 0;

			vector<int> c = a;
			for (int i = 0; i < n; ++i) {

				if (!b[i] && temp) {
					++c[i];
					temp--;
				}
				sum += c[i];
			}

			if (temp || sum > 0)
				hi = mid - 1;
			else if (sum < 0)
				lo = mid + 1;
			else {
				for (int x : c)
					cout << x << '\n';
				return 0;
			}
		}
	}
	assert(false);
	cout << -1;
	return 0;
}