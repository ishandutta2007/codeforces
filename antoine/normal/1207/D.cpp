#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define DBG(v) cerr << #v << " = " << (v) << endl;

const int mod = 998244353;

signed main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr), cout.tie(nullptr);

	int n;
	cin >> n;
	vector<pair<int, int>> v(n);
	for (pair<int, int> &p : v)
		cin >> p.first >> p.second;

	ll ans = 1;
	for (int i = 2; i <= n; ++i)
		(ans *= i) %= mod;
	for (int rep = 0; rep < 2; ++rep) {
		sort(v.begin(), v.end());
		ll temp = 1;
		int cnt = 1;
		for (int i = 1; i < n; ++i)
			if (v[i].first == v[i - 1].first)
				(temp *= ++cnt) %= mod;
			else
				cnt = 1;
		ans -= temp;
		for (pair<int, int> &p : v)
			swap(p.first, p.second);
	}

	if (is_sorted(v.begin(), v.end())) {
		ll temp = 1;
		int cnt = 1;
		for (int i = 1; i < n; ++i)
			if (v[i] == v[i - 1])
				(temp *= ++cnt) %= mod;
			else
				cnt = 1;
		ans += temp;
	}

	cout << (ans % mod + mod) % mod;
	return 0;
}