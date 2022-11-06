#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

int f(const vector<ll> &a) {
	assert(!a[0]);
	vector<ll> cs(a.size(), 0);
	partial_sum(a.begin(), a.end(), cs.begin());
	const int n = (int) a.size() - 1;

	for (ll k = 1, j = n; k <= n; ++k) {
		while (j > k && a[j] < k)
			--j;
		if (cs[k] > k * (k - 1) + (j - k) * k + cs[n] - cs[j])
			return k;
	}
	return -1;
}

int f(vector<ll> a, const int x) {
	assert(is_sorted(a.rbegin(), a.rend() - 1));
	if (x < 0)
		return -1;
	int i = 1;
	while (i < (int) a.size() && a[i] > x)
		++i;
	a.insert(a.begin() + i, x);
	assert(is_sorted(a.rbegin(), a.rend() - 1));
	const int k = f(a);
	return k == -1 ? 0 : i <= k ? 1 : -1;
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);

	int n;
	cin >> n;
	vector<ll> a(n);
	for (ll &x : a)
		cin >> x;
	sort(a.rbegin(), a.rend());
	a.insert(a.begin(), 0);

	const ll parity = accumulate(a.begin(), a.end(), 0LL) & 1;

	for (int i = parity; i <= 100; i += 2)
		assert(f(a, i) <= f(a, i + 2));

	const int ans1 = [&]() {
		int lo = -2, hi = n+2;

		while (lo < hi) {
			const int mid = (lo + hi) >> 1;
			const int x = parity + 2 * mid;
			if (x > n || f(a, x) >= 0)
			hi = mid;
			else
			lo = mid + 1;
		}
		return parity + 2 * lo;
	}();

	const int ans2 = [&]() {
		int lo = -2, hi = n +2;

		while (lo < hi) {
			const int mid = (lo + hi + 1) >> 1;
			const int x = parity + 2 * mid;
			if (x > n || f(a, x) > 0)
			hi = mid -1;
			else
			lo = mid;
		}
		return parity + 2 * lo;

	}();

	if (ans1 > ans2)
		cout << -1;
	else {
		cerr << ans1 << ' ' << ans2 << endl;
		assert(f(a, ans1) == 0);
		assert(f(a, ans2) == 0);
		for (int i = ans1; i <= ans2; i += 2)
			cout << i << ' ';
	}
	return 0;
}