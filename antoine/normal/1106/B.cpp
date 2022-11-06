#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);

	int n, m;
	cin >> n >> m;
	vector<int> a(n + 1), c(n + 1);
	for (int i = 1; i <= n; ++i)
		cin >> a[i];
	for (int i = 1; i <= n; ++i)
		cin >> c[i];

	priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
	for (int i = 1; i <= n; ++i)
		pq.push( { c[i], i });

	while (m--) {
		int t, d;
		cin >> t >> d;

		ll ans = 0;
		while (d > 0) {
			if (!a[t]) {
				while (!pq.empty() && !a[pq.top().second])
					pq.pop();
				if (pq.empty()) {
					ans = d = 0;
					break;
				}
				t = pq.top().second;
			}
			const int x = min(a[t], d);
			a[t] -= x;
			d -= x;
			ans += (ll) c[t] * x;
		}
		cout << ans << '\n';
	}
	return 0;
}