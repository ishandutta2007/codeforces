#include<bits/stdc++.h>
using namespace std;
int cnt[200001], tot[200001];
int main() {
	int t;
	cin >> t;
	while (t--) {
		int n, l, r;
		cin >> n >> l >> r;
		for (int i = 1; i <= n; i++) cnt[i] = tot[i] = 0;
		for (int i = 1; i <= n; i++) {
			int c;
			cin >> c, ++tot[c];
			if (i <= l) --cnt[c];
			else ++cnt[c];
		}
		if (l > r) {
			swap(l, r);
			for (int i = 1; i <= n; i++) cnt[i] = -cnt[i];
		}
		priority_queue<pair<int, int>> pq;
		int ans = r - l;
		for (int i = 1; i <= n; i++) pq.push(make_pair(cnt[i], tot[i])), ans += abs(cnt[i]);
		while (l < r) {
			pair<int, int> p = pq.top();
			pq.pop();
			if (p.first == -p.second) continue;
			ans -= abs(p.first), p.first -= 2, ans += abs(p.first);
			pq.push(p), ++l, --r;
		}
		cout << ans/2 << endl;
	}
}