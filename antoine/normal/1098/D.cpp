#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

struct FT {
	int n;
	vector<ll> vals;
	FT(const int n) :
			n(n), vals(vector<ll>(n + 1, 0)) {
	}

	void update(int i, const ll a) {
		for (++i; i <= n; i += i & -i)
			vals[i] += a;
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

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);

	int Q;
	cin >> Q;
	vector<pair<char, int>> queries(Q);
	for (auto &&p : queries)
		cin >> p.first >> p.second;

	vector<int> xs;
	for (const auto &p : queries)
		xs.push_back(p.second);

	sort(xs.begin(), xs.end());

	const int n = (int) xs.size();

	map<int, int> pos;

	for (int i = n - 1; i >= 0; --i)
		pos[xs[i]] = i;

	map<int, int> occ;
	set<int> s;

	FT ft(n);

	for (const auto &p : queries) {
		if (p.first == '+') {
			const int i = pos.at(p.second) + occ[p.second]++;
			s.insert(i);
			ft.update(i, p.second);
		} else {
			assert(p.first == '-');
			const int i = pos.at(p.second) + --occ.at(p.second);
			s.erase(s.find(i));
			ft.update(i, -p.second);
		}

		int gaps = 0;
		for (auto it = s.begin(); it != s.end() && next(it) != s.end();) {
			const ll sum = ft.query(*it);
			if(sum >= (ll)1e9) break;

			int lo = *it;
			int hi = n - 1;

			while (lo < hi) {
				const int mid = (lo + hi + 1) >> 1;
				if (xs[mid] <= 2 * sum)
					lo = mid;
				else
					hi = mid - 1;
			}

			auto it2 = prev(s.upper_bound(lo));
			if (*it == *it2) {
				++gaps;
				++it;
			} else
				it = it2;
		}

		cout << (s.empty() ? 0 : (int) s.size() - 1 - gaps) << '\n';
	}
	return 0;
}