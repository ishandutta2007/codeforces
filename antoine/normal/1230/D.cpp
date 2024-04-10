#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define DBG(v) cerr << #v << " = " << (v) << endl;

signed main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr), cout.tie(nullptr);

	int n;
	cin >> n;
	vector<ll> a(n);
	vector<int> b(n);
	for (ll &x : a)
		cin >> x;
	for (int&x : b)
		cin >> x;
	map<ll, vector<int>> mp;
	for (int i = 0; i < n; ++i)
		mp[a[i]].push_back(b[i]);
	a.clear();
	for (auto e : mp)
		if (e.second.size() > 1)
			a.push_back(e.first);
	ll ans=0;
	for (auto e : mp) {
		bool ok = false;
		for (ll x : a)
			ok |= (x & e.first) == e.first;
		if(ok)
			ans += accumulate(e.second.begin(), e.second.end(), 0LL);
	}
	cout << ans;
	return 0;
}