#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

struct Range;

set<array<int, 3>> S;

struct Range {
	int l, r, k;
	Range(const int l, const int r, const int k) :
			l(l), r(r), k(k) {
		S.insert(array<int, 3> { k, l, r });
	}
	~Range() {
		S.erase(S.find(array<int, 3> { k, l, r }));
	}
	bool operator<(const Range &other) const {
		if (l != other.l)
			return l < other.l;
		if (r != other.r)
			return r < other.r;
		return k < other.k;
	}
};

void addRange(set<Range> &ranges, int l, int r, const int k) {
	auto it = ranges.lower_bound(Range(l, l, 0));
	if (it != ranges.end() && it->k == k) {
		r = it->r;
		it = ranges.erase(it);
	}
	if (it != ranges.begin() && (--it)->k == k) {
		l = it->l;
		ranges.erase(it);
	}
	ranges.emplace(l, r, k);
}

void remRange(set<Range> &ranges, const int l, const int r, const int k) {
	auto it = ranges.lower_bound(Range(l, l, 0));
	assert(it != ranges.end() && it->l == l && it->r == r && it->k == k);
	ranges.erase(it);
}

int queryRange(set<Range> &ranges, int i) {
	auto it = ranges.upper_bound( { i + 1, i, -1 });
	assert(it != ranges.begin());
	assert((--it)->r >= i);
	return it->k;
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);

	int n;
	cin >> n;
	vector<int> a(n);

	set<Range> ranges;
	for (int i = 0; i < n; ++i) {
		cin >> a[i];
		addRange(ranges, i, i, a[i]);
	}

	while (S.begin()->at(0) != S.rbegin()->at(0)) {
/*

		for (auto &&x : ranges)
			cerr << "(" << x.l << ' ' << x.r << ' ' << x.k << "), ";
		cerr << endl;

		for(auto &&x : S)
			cerr << x[0] << ' ' << x[1] << ' ' << x[2] << '\t';
		cerr << endl;
*/

		const int k = S.begin()->at(0);
		const int l = S.begin()->at(1);
		const int r = S.begin()->at(2);

		if ((r - l + 1) & 1) {
			cout << "NO\n";
			return 0;
		}
		remRange(ranges, l, r, k);
		const int Inf = 1 << 30;
		const int newK = min(l == 0 ? Inf : queryRange(ranges, l - 1), r == n - 1 ? Inf : queryRange(ranges, r + 1));
		assert(newK < Inf);
		addRange(ranges, l, r, newK);
	}
	cout << "YES\n";
	return 0;
}