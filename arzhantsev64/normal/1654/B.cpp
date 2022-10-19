#pragma GCC optimize("O3", "unroll-loops")
#pragma GCC target("sse4.2")

#include <bits/stdc++.h>

using namespace std;

#define int long long

void solve() {
	string v;
	cin >> v;
	int n = v.size();
	vector<int> cnt(26);
	for (int i = 0; i < n; ++i) {
		cnt[v[i] - 'a']++;
	}
	int i = 0;
	while (i < n) {
		if (cnt[v[i] - 'a'] == 1)
			break;
		cnt[v[i] - 'a']--;
		i++;
	}
	for (; i < n; ++i)
		cout << v[i];
	cout << '\n';
}

signed main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	int t;
	cin >> t;
	while (t--)
		solve();

	return 0;
}