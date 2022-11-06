#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);

	int n, k;
	cin >> n >> k;

	set<pair<int, int>> s1, s2;

	for (int i = 0; i < n; ++i) {
		int x;
		cin >> x;
		--x;
		s1.insert( { i, x });
		s2.insert( { x, i });
	}

	vector<int> ans(n, -1);

	for (int turn = 0; !s1.empty(); turn ^= 1) {
		auto it = s1.find( { s2.rbegin()->second, s2.rbegin()->first });
		ans[it->first] = turn;

		for (int rep = 0; rep < k && it != s1.begin(); ++rep) {
			it = prev(it);
			ans[it->first] = turn;
			s2.erase( { it->second, it->first });
			it = s1.erase(it);
		}

		for (int rep = 0; rep < k && next(it) != s1.end(); ++rep) {
			ans[next(it)->first] = turn;
			s2.erase( { next(it)->second, next(it)->first });
			s1.erase(next(it));
		}

		s2.erase( { it->second, it->first });
		s1.erase(it);
		assert(s1.size() == s2.size());
	}

	for (int i = 0; i < n; ++i)
		cout << ans[i] + 1;
	return 0;
}