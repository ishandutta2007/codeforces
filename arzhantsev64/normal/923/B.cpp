#include <bits/stdc++.h>

using namespace std;

#define int long long

void solve() {
	int n;
	cin >> n;
	vector<int> V(n), T(n);
	for (int& v : V) cin >> v;
	for (int& t : T) cin >> t;	
	multiset<int> q;
	int pref_sum = 0;
	for (int i = 0; i < n; ++i) {
		int ans = 0;
		q.insert(pref_sum + V[i]);
		while (q.size()) {
			if (*q.begin() <= pref_sum + T[i]) {
				ans += (*q.begin() - pref_sum);
				q.erase(q.begin());
			} else {
				break;
			}
		}
		pref_sum += T[i];
		ans += q.size() * T[i];
		cout << ans << " ";
	}
}

signed main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	solve();
	return 0;
}