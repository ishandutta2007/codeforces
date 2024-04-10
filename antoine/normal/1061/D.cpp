#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

typedef pair<int, int> pii;
const int mod = (int) 1e9 + 7;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);

	int n;
	ll X, Y;
	cin >> n >> X >> Y;

	vector<pii> v(n);
	for (pii &p : v)
		cin >> p.first >> p.second;

	sort(v.begin(), v.end());

	ll ans = 0;
	multiset<int> ms;

	for(const pii &p : v) {
		ans += X + (p.second - p.first) * Y;
		ans %= mod;
		ms.insert(p.second);
		auto it = ms.lower_bound(p.first);
		if(it != ms.begin()) {
			--it;
			const ll diff = (p.first - *it) * Y - X;
			if(diff < 0) {
				ms.erase(it);
				ans += diff;
				ans %= mod;
			}
		}
	}

	cout << ((ans%mod)+mod)%mod << '\n';
	return 0;
}