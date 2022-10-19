#include <bits/stdc++.h>

using namespace std;

int main() {
	long long n, x, k;
	cin >> n >> x >> k;
	vector<long long> v(n);
	for (long long i = 0; i < n; ++i)
		cin >> v[i];
	sort(v.begin(), v.end());
	long long ans = 0;
	long long m;
	for (long long i = 0; i < n; ++i) {
		long long l = -1, r = n;
		while (r - l != 1) {
			m = (l + r) / 2;
			if (v[m] > v[i] || (v[i] / x) - ((v[m] - 1) / x) < k)
				r = m;
			else
				l = m;
		}
		long long t1 = l;
		l = -1, r = n;
		while (r - l != 1) {
			m = (l + r) / 2;
			if ((v[i] / x) - ((v[m] - 1) / x) > k)
				l = m;
			else
				r = m;
		}
		long long t2 = l;
		ans += max(0ll, t1 - t2);
	}
	cout << ans << endl;
}