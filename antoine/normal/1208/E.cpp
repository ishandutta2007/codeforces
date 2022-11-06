#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define DBG(v) cerr << #v << " = " << (v) << endl;

struct FT {
	int n;
	vector<ll> vals;
	FT(const int n) :
			n(n), vals(vector<ll>(n + 1, 0)) {
	}

	void update(int i, const ll x) {
		for (++i; i <= n; i += i & -i)
			vals[i] += x;
	}
	ll query(int i) const { // sum from 0 ... i
		assert(i >= -1 && i < n);
		ll sum = 0;
		for (++i; i; i -= i & -i)
			sum += vals[i];
		return sum;
	}
	ll query(int i, int j) const {
		return query(j) - query(i - 1);
	}
};

int sum = 0;
struct Range { // discrete range of type k
	int l, r, k;
	Range(const int l, const int r, const int k) :
			l(l), r(r), k(k) {
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

void addRange(set<Range> &ranges, const int l, const int r, const int k) {
	assert(l <= r);
	auto it = ranges.lower_bound(Range(l, l, 0));
	while (it != ranges.end() && it->r <= r)
		it = ranges.erase(it);
	if (it != ranges.end() && it->l <= r) {
		ranges.emplace(r + 1, it->r, it->k);
		it = ranges.erase(it);
	}
	if (it != ranges.begin() && (--it)->r >= l) {
		ranges.emplace(it->l, l - 1, it->k);
		if (it->r > r)
			ranges.emplace(r + 1, it->r, it->k);
		ranges.erase(it);
	}
	ranges.emplace(l, r, k);
}

signed main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr), cout.tie(nullptr);

	int n, m;
	cin >> n >> m;
	FT ft(m + 1);

	while (n--) {
		int k;
		cin >> k;
		vector<array<int, 3>> v = { { 0, 0, (m - k) - 1 }, { 0, m - (m - k), m - 1 } };
		if (k == m)
			v.clear();
		for (int i = 0; i < k; ++i) {
			int x;
			cin >> x;
			v.push_back(array<int, 3> { x, i, i + m - k });
		}
		sort(v.begin(), v.end());
		set<Range> ranges;
		for (auto e : v)
			addRange(ranges, e[1], e[2], e[0]);
		for (auto range : ranges) {
			ft.update(range.l, range.k);
			ft.update(range.r + 1, -range.k);
		}
	}

	for (int i = 0; i < m; ++i)
		cout << ft.query(i) << ' ';
	return 0;
}