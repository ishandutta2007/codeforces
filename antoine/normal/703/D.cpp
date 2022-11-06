#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define DBG(v) cerr << #v << " = " << (v) << endl;

#define REP(i,n) for((i)=0;(i)<(int)(n);(i)++)

struct FT {
	int n;
	vector<ll> vals;
	FT(const int n) :
			n(n), vals(vector<ll>(n + 1, 0)) {
	}

	void update(int i, const int x) {
		for (++i; i <= n; i += i & -i)
			vals[i] ^= x;
	}
	int query(int i) const { // sum from 0 ... i
		assert(i >= -1 && i < n);
		int sum = 0;
		for (++i; i; i -= i & -i)
			sum ^= vals[i];
		return sum;
	}
	ll query(int i, int j) const {
		return query(j) ^ query(i - 1);
	}
};
signed main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr), cout.tie(nullptr);

	int n;
	cin >> n;
	vector<int> a(n);
	for (int &x : a)
		cin >> x;
	a.insert(a.begin(), 0);

	int Q;
	cin >> Q;
	vector<vector<pair<int, int>>> queries(n + 1);
	vector<int> ans(Q, -1);
	for (int i = 0; i < Q; ++i) {
		int l, r;
		cin >> l >> r;
		queries[l].push_back( { i, r });
	}

	FT ft(n + 1);
	for (int i = 1; i <= n; ++i)
		ft.update(i, a[i]);

	map<int, int> mp;
	for (int i = n; i >= 1; --i) {
		if (mp.count(a[i]))
			ft.update(mp.at(a[i]), a[i]);
		ft.update(i, a[i]);
		mp[a[i]] = i;

		for (const pair<int, int> &p : queries[i])
			ans[p.first] = ft.query(i, p.second);
	}

	for (int x : ans)
		cout << x << '\n';
	return 0;
}