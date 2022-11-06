#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int ans[1009];

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);

	memset(ans, -1, sizeof ans);

	int n;
	cin >> n;
	vector<int> l(n), r(n);
	for(int i = 0; i < n; ++i)
		cin >> l[i];
	for(int i = 0; i < n; ++i)
		cin >> r[i];

	for (int curr = n; any_of(ans, ans + n, [](const int &x) {return x == -1;});
			--curr) {
		assert(curr >= 1);
		bool ok = false;
		for (int i = 0; i < n; ++i) {
			if (ans[i] != -1)
				continue;
			if (!l[i] && !r[i]) {
				ans[i] = curr;
				ok = true;
			}
		}

		if (!ok) {
			cout << "NO";
			return 0;
		}

		int cnt = 0;
		for (int i = 0; i < n; ++i) {
			if(ans[i] == curr) {
				++cnt;
			} else {
				if (ans[i] != -1)
					continue;
				l[i] -= cnt;
				// cerr << "deccc\n" << l[i] << ' ' << cnt << endl;
			}
		}

		cnt = 0;
		for (int i = n - 1; i >= 0; --i) {
			if (ans[i] == curr) {
				++cnt;
			} else {
				if (ans[i] != -1)
					continue;
				r[i] -= cnt;
				// cerr << "deccc\n" << r[i] << ' ' << cnt << endl;
			}
		}
	}

	cout << "YES\n";
	for(int i = 0; i < n; ++i)
		cout << ans[i] << ' ';
	return 0;
}