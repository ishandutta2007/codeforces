#include<bits/stdc++.h>
using namespace std;

#define int long long

const int N = 100005;

int a[7];
int b[N];
int n;


signed main() {
	ios::sync_with_stdio(false); cin.tie(0);

	for (int i = 1; i <= 6; i++) {
		cin >> a[i];
	}

	cin >> n;

	for (int i = 1; i <= n; i++) {
		cin >> b[i];
	}

	if (n == 1) {
		cout << 0 << endl;
		return 0;
	}

	vector<pair<int, int>> v;

	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= 6; j++) {
			v.push_back({b[i] - a[j], i});
		}
	}

	sort(v.begin(), v.end());

	multiset<pair<int, int>> ms;

	vector<int> cnt(n + 1);

	int dem = 0;
	int ans = 2e9;

	for (auto e : v) {
		ms.insert(e);

		// cout << e.first << ' ' << e.second << endl;
	
		if (cnt[e.second] == 0)
			dem++;

		cnt[e.second]++;

		if (dem < n)
			continue;

		int pre = 0;

		while (dem >= n) {
			auto u = *ms.begin();
			ms.erase(ms.begin());
			pre = u.first;
			if (cnt[u.second] == 1)
				dem--;
			cnt[u.second]--;
		}

		// cout << (*ms.rbegin()).first << ' ' << pre << endl;

		ans = min(ans, (*ms.rbegin()).first - pre);
	}

	cout << ans << endl;

	return 0;
}