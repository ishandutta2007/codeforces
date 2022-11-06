#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);

	int n, m, k;
	cin >> n >> m >> k;

	vector<pair<ll, int>> v(n);
	for (int i = 0; i < n; ++i) {
		cin >> v[i].first;
		v[i].second = i;
	}

	sort(v.rbegin(), v.rend());
	v.resize(m * k);

	vector<int> b(n, 0);

	ll ans = 0;

	for (auto &&p : v) {
		ans += p.first;
		b[p.second] = 1;
	}
	cout << ans << '\n';

	partial_sum(b.begin(), b.end(), b.begin());

	assert(b.back() == m * k);

	for (int i = 0; i < n; ++i)
		if (b[i] && b[i] % m == 0 && (i == 0 || b[i] != b[i - 1]) && b[i] != b.back())
			cout << i + 1 << ' ';

	return 0;
}