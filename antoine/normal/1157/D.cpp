#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

ll n, k;

ll f(const ll start) {
	return start * k + (k - 1) * k / 2;
}

void no() {
	cout << "NO";
	exit(0);
}
int main() {
	ios::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);

	cin >> n >> k;

	ll start = 1;
	if (f(start) > n)
		no();

	{
		ll lo = 1;
		ll hi = n;
		while(lo < hi) {
			const ll mid = (lo + hi + 1) / 2;
			if(f(mid) <= n)
				lo = mid;
			else
				hi = mid - 1;
		}
		start = lo;
	}

	ll rem = n - f(start);
	assert(0 <= rem && rem < n);

	cerr << "start: " << start << ' ' << rem << endl;
	vector<ll> res(k);
	res[0] = start;
	for (int i = 1; i < k; ++i)
		res[i] = res[i - 1] + 1;
	for (int i = k - 1; i >= 2 && rem; --i) {
		rem--;
		res[i]++;
	}

	if (rem) {
		assert(rem == 1);
		if (k < 2)
			no();
		if (res[0] > 1)
			res[1]++;
		else {
			res.back()++;if
(			res[k-2]*2 < res.back())
			no();
		}}

	cout << "YES\n";
	for (int x : res)
		cout << x << ' ';
	return 0;
}