#include <bits/stdc++.h>
using namespace std;

map <int, int> mp;
set <int> s;

bool ok(long long s, long long a) {
	long long y = s - (a % s);
	if (y == s)
		y = 0;
	return a + y - s * y >= 0;
}

void solve() {
	int n;
	cin >> n;
	for (int i = 1; i <= n; i++) {
		int t;
		cin >> t;
		s.insert(t);
		mp[t]++;
	}
	set <int>::iterator it;
	int mn = mp[*s.begin()];
	for (it = s.begin(); it != s.end(); it++)
		mn = min(mn, mp[*it]);
	vector <int> can;
	for (int i = mn + 1; i >= 1; i--) {
		if (ok(i, mn))
			can.push_back(i);
	}
	for (auto u: can) {
		int sum = 0;
		for (it = s.begin(); it != s.end(); it++) {
			if (!ok(u, mp[*it])) {
					break;
			}
			else
				sum += (mp[*it] + u - 1) / u;
		}
		if (it == s.end()) {
			cout << sum << '\n';
			while (s.size()) {
				mp[*s.begin()] = 0;
				s.erase(s.begin());
			}
			return;
		}
	}
}

int main() {
	ios::sync_with_stdio(0);
	cout.tie(0);
	cin.tie(0);
	int t;
	cin >> t;
	while (t--) 
		solve();

	return 0;
}