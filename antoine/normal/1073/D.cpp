#undef NDEBUG
#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);

	int n;
	ll T;
	cin >> n >> T;

	ll sum = 0;
	set<pair<int, ll>> s;
	for (int i = 0; i < n; ++i) {
		ll x;
		cin >> x;
		s.emplace(i, x);
		sum += x;
	}

	ll ans = 0;
	for (auto it = s.begin(); s.size();) {
		if (it == s.end())
			it = s.begin();

		ans += (T / sum) * (ll)s.size();
		T %= sum;

		if (it->second > T) {
			sum -= it->second;
			it = s.erase(it);
		} else {
			T -= it->second;
			++ans;
			++it;
		}
	}
	assert(sum == 0);
	cout << ans;
	return 0;
}