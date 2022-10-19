#pragma GCC optimize("O3", "unroll-loops")
#pragma GCC target("sse4.2")

#include <bits/stdc++.h>

using namespace std;

#define int long long

void solve() {
	int n;
	cin >> n;
	multiset<int> s;
	int S = 0;
	for (int i = 0; i < n; ++i) {
		int x;
		cin >> x;
		S += x;
		s.insert(x);
	}
	queue<int> q;
	q.push(S);
	while (!q.empty()) {
		int x = q.front();
		q.pop();
		if (s.find(x) != s.end()) {
			s.erase(s.find(x));
			continue;
		}
		int v1 = x / 2;
		int v2 = (x - 1) / 2 + 1;
		if (v1 < *s.begin()) {
			cout << "NO\n";
			return;
		}
		q.push(v1);
		q.push(v2);
		if (q.size() > s.size()) {
			cout << "NO\n";
			return;
		}
	}
	cout << "YES\n";
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