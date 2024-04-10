#pragma GCC optimize("O3", "unroll-loops")
#pragma GCC target("sse4.2")

#include <bits/stdc++.h>

using namespace std;

#define int long long

#define h first
#define c second

signed main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	int n;
	cin >> n;
	vector<pair<int, int>> all(n);
	int ans = 0;
	for (int i = 0; i < n; ++i) {
		cin >> all[i].h >> all[i].c;
		ans += all[i].c;
	}

	sort(all.begin(), all.end());
	int ch = all[0].h + all[0].c;
	for (int i = 0; i < n; ++i) {
		ans += max((int)0, all[i].h - ch);
		ch = max(ch, all[i].h + all[i].c);
	}

	cout << ans << endl;

	return 0;
}