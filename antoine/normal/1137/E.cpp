#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define DBG(v) cerr << #v << " = " << (v) << endl;

signed main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr), cout.tie(nullptr);

	auto weight = [&](const pair<int, ll> p1, const pair<int, ll> p2) {
		const ll d2 = p1.second - p2.second;
		const ll d1 = p2.first - p1.first;
		assert(d1 > 0);
		return (d2 + d1 - 1) / d1;
	};

	int lo = 1, hi, Q;
	cin >> hi >> Q;

	set<pair<int, ll>> s = { { lo, 0 } };
	priority_queue<pair<ll, int>, vector<pair<ll, int>>, greater<>> pq;

	ll B = 0, S = 0;

	while (Q--) {
		int type;
		cin >> type;
		if (type == 1) {
			ll k;
			cin >> k;
			lo -= k;
			B = S = 0;
			s = { {	lo, 0}};
			pq = decltype(pq)();
		} else if (type == 2) {
			ll k;
			cin >> k;
			pair<int, ll> p;
			p.first = hi + 1;
			p.second -= B + S * (p.first - lo);
			const ll w = weight(*s.rbegin(), p);
			if (w > S) {
				pq.push( { w, s.rbegin()->first });
				s.insert(p);
			}
			hi += k;
		} else {
			assert(type == 3);

			{
				ll db, ds;
				cin >> db >> ds;
				B += db;
				S += ds;
			}

			while (!pq.empty() && pq.top().first <= S) {
				const int i = pq.top().second;
				pq.pop();
				auto it = s.lower_bound( { i, numeric_limits<ll>::min() });
				if (it == s.end() || it->first != i)
					continue;
				while (next(it) != s.end() && weight(*it, *next(it)) <= S)
					s.erase(next(it));
				if (next(it) != s.end())
					pq.push( { weight(*it, *next(it)), it->first });
			}
		}
		assert(lo == s.begin()->first);
		const int i = s.rbegin()->first - lo + 1;
		const ll x = s.rbegin()->second + B + S * (i - 1);
		cout << i << ' ' << x << '\n';
	}

	return 0;
}