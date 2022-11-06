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

int gcd(int a, int b) {
	return b ? gcd(b, a % b) : a;
}

struct IdGen {
	map<pair<int, int>, int> mp;

	int getId(const int x, const int y) {
		pair<int, int> p = { x, y };
		auto it = mp.find(p);
		if (it != mp.end())
			return it->second;
		const int sz = (int) mp.size();
		return mp[p] = sz;
	}
} idGen;

signed main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr), cout.tie(nullptr);

	int n;
	cin >> n;
	vector<vector<ll>> a(n);
	for (vector<ll> &v : a) {
		int k;
		cin >> k;
		vector<pair<int, int>> pts(k);
		for (auto &&p : pts)
			cin >> p.first >> p.second;
		pts.push_back(pts[0]);
		for (int i = 0; i < k; ++i) {
			int dx = pts[i + 1].first - pts[i].first;
			int dy = pts[i + 1].second - pts[i].second;
			int g = gcd(dx, dy);
			if (g < 0)
				g = -g;
			dx /= g;
			dy /= g;
			v.push_back(idGen.getId(dx, dy));
		}
	}

	int Q;
	cin >> Q;
	vector<vector<pair<int, int>>> queries(n);
	vector<int> ans(Q, -1);
	for (int i = 0; i < Q; ++i) {
		int l, r;
		cin >> l >> r;
		--l, --r;
		queries[l].push_back( { i, r });
	}

	FT ft(n);
	map<int, int> mp;
	for (int i = n - 1; i >= 0; --i) {
		for (int x : a[i]) {
			auto it = mp.find(x);
			if (it != mp.end()) {
				ft.update(it->second, -1);
			}
			mp[x] = i;
			ft.update(i, 1);
		}
		for (const pair<int, int> &p : queries[i]) {
			ans[p.first] = ft.query(i, p.second);
		}
	}

	for (int x : ans)
		cout << x << '\n';

	return 0;
}