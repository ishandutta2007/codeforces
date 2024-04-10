#undef NDEBUG
#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

ll x[(int)2e5 + 9];
ll t[(int)2e5 + 9];
int ans[(int)2e5 + 9];

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);

	int n, m;
	cin >> n >> m;

	vector<ll> a, b;
	for(int i = 0; i < n + m; ++i)
		cin >> x[i];

	for(int i = 0; i < n + m; ++i) {
		cin >> t[i];
		if(t[i])
			a.push_back(x[i]);
		else
			b.push_back(x[i]);
	}
	assert((int)a.size() == m && (int)b.size() == n);

	for(auto &&x : b) {
		auto it = lower_bound(a.begin(), a.end(), x);
		ll curr = 1LL << 50;
		if(it != a.end())
			curr = *it;
		if(it != a.begin()) {
			--it;
			if(llabs(x - *it) <= llabs(x - curr)) {
				++ans[it - a.begin()];
				continue;
			}
			++it;
		}
		++ans[it - a.begin()];
	}

	for(int i = 0; i < m; ++i)
		cout << ans[i] << ' ';

	return 0;
}