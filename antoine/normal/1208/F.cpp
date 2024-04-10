#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define DBG(v) cerr << #v << " = " << (v) << endl;

const int B = 21;
int dp[1 << B];

void upd(const int mask, const int idx) {
	dp[mask] = max(dp[mask], idx);
}

void f(vector<pair<int, int>> v, const int fix) {
	if (v.size() <= 1)
		return;
	assert(v.back().first);
	int mask = 1;
	while ((mask << 1) <= v.back().first)
		mask <<= 1;
	const auto mid = lower_bound(v.begin(), v.end(), pair<int, int> { mask, -1 });
	for (auto it = mid; it != v.end(); ++it)
		it->first -= mask;
	f(vector<pair<int, int>>(mid, v.end()), fix | mask);

	auto it1 = v.begin(), it2 = mid;
	vector<pair<int, int>> v2;
	while (it1 != mid && it2 != v.end()) {
		if (it1->first == it2->first) {
			upd(it1->first | fix, min(it1->second, it2->second));
			v2.push_back( { it1->first, max(it1->second, it2->second) });
			it1++, it2++;
		} else {
			auto &&it = it1->first < it2->first ? it1 : it2;
			v2.push_back(*it);
			it++;
		}
	}
	v2.insert(v2.end(), it1, mid);
	v2.insert(v2.end(), it2, v.end());

	f(v2, fix);
}

signed main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr), cout.tie(nullptr);

	int n;
	cin >> n;
	vector<int> a(n);
	for (int &x : a)
		cin >> x;

	vector<pair<int, int>> v(n);
	for (int i = 0; i < n; ++i)
		v[i] = {a[i], i};
	sort(v.begin(), v.end());

	{
		auto it = v.begin();
		for (int i = 0; i < n; ++i) {
			if (i + 1 < n && v[i].first == v[i + 1].first)
				upd(v[i].first, v[i].second);
			else {
				*it = v[i];
				it++;
			}
		}
		v.erase(it, v.end());
	}

	f(v, 0);

	for (int i = 0; i < B; ++i)
		for (int mask = 0; mask < (1 << B); ++mask)
			if (!(mask & (1 << i)))
				upd(mask, dp[mask | (1 << i)]);

	int ans = 0;
	for (int i = 0; i + 2 < n; ++i) {
		int temp = 0;
		for (int j = B - 1; j >= 0; --j) {
			if (a[i] & (1 << j))
				continue;
			if (i < dp[temp | (1 << j)])
				temp |= 1 << j;
		}
		ans = max(ans, a[i] | temp);
		// DBG(ans)
	}
	cout << ans;
	return 0;
}