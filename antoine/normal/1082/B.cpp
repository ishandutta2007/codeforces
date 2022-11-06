#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

struct Range {
	int l, r;
	int size() {
		return r - l + 1;
	}
};
int main() {
	ios::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);

	int n;
	cin >> n;
	vector<Range> ranges;

	for (int i = 1; i <= n; ++i) {
		char c;
		cin >> c;
		if (c == 'S')
			continue;
		assert(c == 'G');
		if (ranges.empty() || ranges.back().r != i - 1)
			ranges.push_back( { i, i });
		else
			ranges.back().r++;
	}

	int ans = 0;
	for (auto &&x : ranges)
		ans = max(ans, x.size() + (ranges.size() > 1));

	for (int i = 0; i + 1 < (int) ranges.size(); ++i)
		if (ranges[i].r + 2 == ranges[i + 1].l)
			ans = max(ans, ranges[i].size() + ranges[i + 1].size() + (ranges.size() > 2));
	cout << ans;
	return 0;
}