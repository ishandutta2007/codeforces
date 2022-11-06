#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

ll A, B;

ll f(const int lo, const int hi, vector<int>::iterator begin, vector<int>::iterator end) {
	if (begin == end)
		return A;

	ll ans = B * ll(end - begin) * ll(hi - lo);
	if (hi - lo > 1) {
		const ll mid = lo + (hi - lo) / 2;
		auto it = lower_bound(begin, end, mid);
		ans = min(ans, f(lo, mid, begin, it) + f(mid, hi, it, end));
	}
	return ans;
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);

	int n, k;
	cin >> n >> k >> A >> B;
	vector<int> a(k);
	for (int &x : a) {
		cin >> x;
		--x;
	}
	sort(a.begin(), a.end());
	cout << f(0, 1 << n, a.begin(), a.end());
	return 0;
}