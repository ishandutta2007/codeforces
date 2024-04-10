#include <bits/stdc++.h>

using namespace std;

const int N = 505;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int n, k;
	cin >> n >> k;
	auto ask = [&](bitset<N> b) -> int {
		cout << "? ";
		for (int i = 0; i < n; ++i) {
			if (b[i]) {
				cout << i + 1 << " ";
			}
		}
		cout << endl;
		int res;
		cin >> res;
		return res;
	};
	int lim = 2 * min(k - 1, n - k);
	vector<int> dist(n + 1, n + 1);
	vector<int> bef(n + 1);
	priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
	auto add_pq = [&](int a, int b, int f) {
		if (a > n) return;
		if (dist[a] <= b) {
			return;
		}
		bef[a] = f;
		pq.push({dist[a] = b, a});
	};
	add_pq(0, 0, -1);
	while (!pq.empty()) {
		pair<int, int> x = pq.top();
		pq.pop();
		if (dist[x.second] < x.first) {
			continue;
		}
		add_pq(x.second + k, x.first + 1, x.second);
		for (int i = 2; i <= lim; i += 2) {
			add_pq(x.second + i, x.first + 2, x.second);
		}
	}
	if (dist[n] == n + 1) {
		cout << -1 << '\n';
		return 0;
	}
	vector<int> need;
	int cur = n;
	while (cur) {
		int nxt = bef[cur];
		need.push_back(cur - nxt);
		swap(nxt, cur);
	}
	int ans = 0;
	int l = 0;
	bitset<N> b;
	for (int x : need) {
		b.reset();
		int r = l + x - 1;
		if (x == k) {
			for (int i = l; i <= r; ++i) {
				b[i] = 1;
			}
			ans ^= ask(b);
			l += x;
		} else {	
			vector<int> bad;
			x /= 2;
			int waste = k - x;
			int m = (l + r) >> 1;
			for (int i = l; i <= m; ++i) {
				b[i] = 1;
			}
			for (int i = 0; i < n; ++i) {
				if (l <= i && i <= r) {
					continue;
				}
				bad.push_back(i);
				if (bad.size() == waste) {
					break;
				}
			}
			for (int x : bad) {
				b[x] = 1;
			}
			ans ^= ask(b);
			b.reset();
			for (int i = m + 1; i <= r; ++i) {
				b[i] = 1;
			}
			for (int x : bad) {
				b[x] = 1;
			}
			ans ^= ask(b);
			l += 2 * x;
		}
	}
	cout << "! " << ans << endl;
	return 0;
}