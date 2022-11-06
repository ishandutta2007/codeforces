#undef NDEBUG
#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

auto getFact(ll x) {
	vector<pair<int, int>> v;
	for (ll i = 2; i * i <= x; ++i)
		if (x % i == 0) {
			v.emplace_back(i, 1);
			for (x /= i; x % i == 0; x /= i)
				v.back().second++;
		}
	if(x != 1)
		v.emplace_back(x, 1);
	return v;
}

int cLg(const int k) {
	int res = 0;
	while ((1 << res) < k)
		++res;
	return res;
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);

	int n;
	cin >> n;

	const auto v = getFact(n);

	bool mul = false;
	int ans1 = 1;
	int ans2 = -1;
	for (auto &&p : v) {
		cerr << p.first << ' ' << p.second << endl;
		ans1 *= p.first;
		const int l = cLg(p.second);
		mul |= ((1 << l) != p.second);
		mul |= (ans2 != -1 && ans2 != l);
		ans2 = max(ans2, l);
	}
	cerr << ans1 << ' ' << ans2 << ' ' << mul << endl;
	cout << ans1 << ' ' << max(0, ans2) + mul;
	return 0;
}