#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

ll a[(int) 1e6 + 9];


struct Range {
	ll * begin, *end;

	ll * mid(const int pos) {
		assert(begin != end);
		return lower_bound(begin, end, (*begin | 1LL << pos) & ~((1LL << pos) - 1));
	}

	bool empty() const {
		return begin == end;
	}
};

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);

	int n;
	ll k;
	cin >> n >> k;

	for (int i = 1; i < n; ++i) {
		int p;
		ll w;
		cin >> p >> w;
		a[i] = a[p - 1] ^ w;
	}

	sort(a, a + n);

	vector<pair<Range, Range>> v = { { { a, a + n }, { a, a + n } } };

	ll ans = 0;

	for (int pos = 62; pos >= 0; --pos) {
		ll cnt0 = 0;
		vector<pair<ll*, ll*>> mid(v.size());
		for (int i = 0; i < (int) v.size(); ++i) {
			mid[i] = {v[i].first.mid(pos), v[i].second.mid(pos)};

			cnt0 += ll(mid[i].first - v[i].first.begin) * (mid[i].second - v[i].second.begin);
			cnt0 += ll(v[i].first.end - mid[i].first) * (v[i].second.end - mid[i].second);
		}


		vector<pair<Range, Range>> newV;
		newV.reserve((int) v.size());

		auto push = [&newV](const Range r1, const Range r2) {
			if(!r1.empty() && !r2.empty())
			newV.push_back( {r1, r2});
		};

		if (k <= cnt0) {
			for (int i = 0; i < (int) v.size(); ++i) {
				push( { v[i].first.begin, mid[i].first }, { v[i].second.begin, mid[i].second });
				push( { mid[i].first, v[i].first.end }, { mid[i].second, v[i].second.end });
			}
		} else {
			k -= cnt0;
			ans |= 1LL << pos;

			for (int i = 0; i < (int) v.size(); ++i) {
				push( { v[i].first.begin, mid[i].first }, { mid[i].second, v[i].second.end });
				push( { mid[i].first, v[i].first.end }, { v[i].second.begin, mid[i].second });
			}
		}

		v = move(newV);
	}

	cerr << v.size() << endl;
	cerr << bitset<63>(ans) << endl;
	cout << ans << '\n';
	return 0;
}