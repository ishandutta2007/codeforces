#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);

	int n;
	cin >> n;

	vector<ll> a(n);
	for (ll &x : a)
		cin >> x;

	sort(a.begin(), a.end());
	a.erase(unique(a.begin(), a.end()), a.end());
	n = (int) a.size();

	map<ll, ll> updates;
	set<pair<ll, int>> queries;

	for (int i = 0; i + 1 < n; ++i)
		updates[a[i + 1] - a[i]]--;

	int Q;
	cin >> Q;
	vector<ll> ans(Q, 0);
	for (int i = 0; i < Q; ++i) {
		ll l, r;
		cin >> l >> r;
		queries.insert( { r - l + 1, i });
	}

	ll slope = n, t = 0, f = 0;
	while (!queries.empty()) {
		auto up = [&](const ll newT) {
			f += slope * (newT - t);
			t = newT;
		};
		if (updates.empty() || queries.begin()->first < updates.begin()->first) {
			up(queries.begin()->first);
			ans[queries.begin()->second] = f;
			queries.erase(queries.begin());
		} else {
			up(updates.begin()->first);
			slope += updates.begin()->second;
			updates.erase(updates.begin());
		}
	}
	for (int i = 0; i < Q; ++i)
		cout << ans[i] << ' ';
	return 0;
}