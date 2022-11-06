#include <iostream>
#include <algorithm>
#include <cstring>
#include <string>
#include <vector>
#include <set>
#include <map>
#include <queue>
#include <cmath>
#include <stack>
#include <iomanip>
#include <functional>

using namespace std;

int sum;
struct Range {
	int l, r, k;
	Range(const int l, const int r, const int k) : l(l), r(r), k(k) {
		if (k == 2)
			sum += r - l + 1;
	}
	~Range() {
		if (k == 2)
			sum -= r - l + 1;
	}
	bool operator<(const Range &other) const {
		if (l != other.l)
			return l < other.l;
		return r < other.r;
	}
};

set<Range> ranges;

void addRange(int l, int r, int k) {
	auto it = ranges.lower_bound(Range(l, -1, 0));
	while (it != ranges.end() && it->r <= r)
		it = ranges.erase(it);
	if (it != ranges.end() && it->l <= r) {
		ranges.emplace(r + 1, it->r, it->k);
		it = ranges.erase(it);
	}
	if (it != ranges.begin()) {
		--it;
		if (it->r >= l) {
			ranges.emplace(it->l, l - 1, it->k);
			if (it->r > r)
				ranges.emplace(r + 1, it->r, it->k);
			ranges.erase(it);
		}
	}
	ranges.emplace(l, r, k);
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	int n, q;
	cin >> n >> q;

	ranges.insert({ 1, n, 2 });
	sum = n;

	while (q-- > 0) {
		int l, r, k;
		cin >> l >> r >> k;
		addRange(l, r, k);
		cout << sum << '\n';
	}
	return 0;
}