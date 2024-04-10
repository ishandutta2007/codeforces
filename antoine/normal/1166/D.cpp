#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define DBG(v) cerr << #v << " = " << (v) << endl;

vector<ll> getCoeffs(const int len) {
	vector<ll> coeffs(len + 1, 0);
	if (len == 1)
		return coeffs;
	if (len == 2)
		return {0,0,1};
	coeffs[len] = 1;
	coeffs[len - 1] = 1;
	for (int i = len - 2; i >= 2; --i)
		coeffs[i] = coeffs[i + 1] * 2;

	return coeffs;
}

void build(const vector<ll> r, const ll a, const ll b) {
	const int len = (int) r.size() - 1;

	vector<ll> arr(len + 1);
	vector<ll> cs(len + 1);
	arr[1] = a;
	cs[1] = a;
	cout << len << ' ' << a << ' ';

	for (int i = 2; i <= len; ++i) {
		arr[i] = cs[i - 1] + r[i];
		cs[i] = cs[i - 1] + arr[i];
		cout << arr[i] << ' ';
	}
	assert(arr[len] == b);

	cout << endl;
}

void f() {
	ll a, b, m;
	cin >> a >> b >> m;

	for (int len = 1;; ++len) {
		const ll pa = a * (1LL << max(0, len - 2));
		const ll c = len <= 2 ? len - 1 : 1LL << (len - 2);
		const ll lo = pa + c;
		const ll hi = pa + c * m;

		if (b < lo) {
			cout << -1 << endl;
			return;
		}

		if (b > hi)
			continue;

		// TBD

		assert((len == 1) == (a == b));

		vector<ll> r(len + 1);
		const vector<ll> coeffs = getCoeffs(len);

		ll rem = b - lo;
		for (int i = 2; i <= len; ++i) {
			r[i] = min(m - 1, rem / coeffs[i]);
			rem -= r[i] * coeffs[i];
			assert(rem >= 0);
			++r[i];
		}
		assert(rem == 0);

		build(r, a, b);
		return;
	}
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);

	int q;
	cin >> q;
	while (q--)
		f();

	return 0;
}