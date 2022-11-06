#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define DBG(v) cerr << #v << " = " << (v) << endl;

ll f(ll n, ll k) {
	if (k % 3)
		return n % 3;
	if (!n)
		return 0;
	n %= k + 1;
	if (n == k)
		return 3;
	return n % 3;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr), cout.tie(nullptr);

	int k = 6;
	int n = 100;

	vector<int> a(n + 1);
	a[0] = 0, a[1] = 1;
	for (int i = 2; i <= n; ++i) {
		set<int> s = { a[i - 1], a[i - 2] };
		if (i >= k)
			s.insert(a[i - k]);

		for (int x = 0;; ++x)
			if (!s.count(x)) {
				a[i] = x;
				break;
			}
	}
	for (int i = 0; i <= n; ++i) {
		cerr << i << ": " << a[i] << '\n';
		if (a[i] != f(i, k)) {
			DBG(i)
			DBG(a[i])
			DBG(f(n, k))
			assert(false);
		}
	}

	int Q;
	cin >> Q;
	while (Q--) {
		ll n, k;
		cin >> n >> k;
		cout << (f(n, k) ? "Alice" : "Bob") << '\n';
	}
	return 0;
}