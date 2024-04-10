#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

const ll Mx = (ll) 1e6;
const ll n = 2000;

ll f(const vector<ll> &a, int i) {
	ll sum = 0;
	ll coeff = (n - i);
	for (; i < n; ++i)
		sum += a[i];
	return sum * coeff;
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);

	ll K;
	cin >> K;

	vector<ll> a(n, 1);
	ll S = n - 1;
	for (int i = 1; i < n; ++i) {
		ll x = 0;
		if (S <= K) {
			x = Mx - 1;
		} else if ((S - K) % n != 0) {
			x = n - (S - K) % n;
		}
		S -= a[i];
		a[i] += x;
		S += a[i];
	}

	assert((S - K) % n == 0);
	assert(S > K);

	a[0] = -((S - K) / n);

	assert(a[0] < 0 && a[0] >= -Mx);

	for (int i = 0; i <= 20; ++i)
		cerr << a[i] << ' ';

	cerr << endl;

	cout << n << '\n';
	for (ll x : a)
		cout << x << ' ';

	assert(f(a, 1) + K == f(a, 0));
	return 0;
}