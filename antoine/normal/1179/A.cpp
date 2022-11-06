#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

#define DBG(v) cerr << #v << " = " << (v) << endl;

const int MxN = (int) 1e5 + 9;
pair<int, int> ans[3 * MxN + 9];

signed main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr), cout.tie(nullptr);

	int n, q;
	cin >> n >> q;
	deque<int> dq;
	for (int i = 0; i < n; ++i) {
		int x;
		cin >> x;
		dq.push_back(x);
	}

	for (int i = 0; i < 3 * n + 9; ++i) {
		int x = dq[0], y = dq[1];
		ans[i] = {x, y};
		if (x > y)
			swap(x, y);
		dq.pop_front();
		dq.pop_front();
		dq.push_back(x);
		dq.push_front(y);
	}

	while (q--) {

		ll m;
		cin >> m;
		--m;
		if (m >= 3 * n + 5) {
			m %= n - 1;
			m += n - 1;
		}
		cout << ans[m].first << ' ' << ans[m].second << '\n';
	}

	return 0;
}