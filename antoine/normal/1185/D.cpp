#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

#define DBG(v) cerr << #v << " = " << (v) << endl;

signed main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr), cout.tie(nullptr);

	int n;
	cin >> n;
	vector<pair<int, int>> v(n);
	for (int i = 0; i < n; ++i) {
		cin >> v[i].first;
		v[i].second = i + 1;
	}
	sort(v.begin(), v.end());

	if(n <= 3) {
		cout << 1;
		return 0;
	}
	multiset<int> ms;

	for (int i = 0; i + 1 < n; ++i)
		ms.insert(v[i + 1].first - v[i].first);

	for (int i = 0; i < n; ++i) {
		if (i > 0)
			ms.erase(ms.find(v[i].first - v[i - 1].first));
		if (i + 1 < n)
			ms.erase(ms.find(v[i + 1].first - v[i].first));
		if (i > 0 && i + 1 < n)
			ms.insert(v[i + 1].first - v[i - 1].first);

		if (*ms.begin() == *ms.rbegin()) {
			cout << v[i].second;
			return 0;
		}

		if (i > 0)
			ms.insert(v[i].first - v[i - 1].first);
		if (i + 1 < n)
			ms.insert(v[i + 1].first - v[i].first);
		if (i > 0 && i + 1 < n)
			ms.erase(ms.find(v[i + 1].first - v[i - 1].first));
	}
	cout << -1;

	return 0;
}