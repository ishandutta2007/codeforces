#include <iostream>
#include <vector>
#include <algorithm>
#include <set>
#include <tuple>

using namespace std;

set<pair<int64_t, int64_t>> inc;
void add(int64_t pos, int64_t val)
{
	// cout << "add " << pos << ' ' << val << endl;
	if (pos == 0) return;
	auto p = make_pair(pos, val);
	set<pair<int64_t, int64_t>>::iterator it;

	it = inc.lower_bound(p);
	if (it != inc.end() && it->second >= val) return;

	while (true) {
		it = inc.lower_bound(p);
		if (it != inc.begin() && prev(it)->second < val) inc.erase(prev(it));
		else break;
	}
	inc.insert(p);
}

int main()
{
	ios_base::sync_with_stdio(0); cin.tie(0);
	int N;
	cin >> N;

	vector<int64_t> A(N + 1);
	for (int i = 1; i <= N; ++i) cin >> A[i];
	inc.emplace(A[1], 0);

	for (int i = 2; i <= N; ++i) {
		int64_t cur = A[i];
		if (cur >= inc.rbegin()->first) continue;

		int64_t bestY = inc.rbegin()->second;
		while (!inc.empty() && inc.rbegin()->first > cur) {
			int64_t x, y;
			tie(x, y) = *inc.rbegin();
			inc.erase(prev(inc.end()));

			add(x % cur, y + (x / cur) * cur * (i - 1));
			bestY = max(bestY, y + (x / cur - 1) * cur * (i - 1));
		}
		add(cur, bestY);
	}

	int64_t ans = 0;
	for (auto p : inc) ans = max(ans, (p.first - 1) * N + p.second);
	cout << ans << endl;
}