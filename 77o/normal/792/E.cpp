// #pragma GCC optimize("O3")
// #pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,tune=native")

#include <bits/stdc++.h>

using namespace std;
using ll = long long;

const int N = 50000;

int main() {
	// freopen("input.txt", "r", stdin);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	int n;
	cin >> n;
	vector<int> a(n);
	for (int& i : a) {
		cin >> i;
	}
	sort(a.begin(), a.end());
	vector<int> candidates(N);
	iota(candidates.begin(), candidates.end(), 1);
	for (int d = 1; d < N; d++) {
		if (a[0] / d) candidates.push_back(a[0] / d);
		if (a[0] % d == 0) {
			if (a[0] / d - 1 > 0) candidates.push_back(a[0] / d - 1);
		}
	}
	sort(candidates.begin(), candidates.end());
	candidates.erase(unique(candidates.begin(), candidates.end()), candidates.end());

	ll ans = LLONG_MAX;
	for (int x : candidates) {
		bool ok = true;
		ll cnt = 0;
		for (int i = 0; i < n; i++) {
			if (a[i] / x < a[i] % x) {
				ok = false;
				break;
			}
			ll k = a[i] / x - a[i] % x;
			ll l = a[i] % x;
			l += k / (x + 1) * x;
			k %= x + 1;
			cnt += k + l;
		}
		if (ok) {
			ans = min(ans, cnt);
		}
	}

	cout << ans << endl;
	return 0;
}