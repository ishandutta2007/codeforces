#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define DBG(v) cerr << #v << " = " << (v) << endl;

struct IdGen {
	map<int, int> mp;
	vector<int> lazy;
	void insert(int x) {
		assert(mp.empty());
		lazy.push_back(x);
	}
	void process() {
		assert(mp.empty());
		sort(lazy.begin(), lazy.end());
		lazy.erase(unique(lazy.begin(), lazy.end()), lazy.end());
		for (int i = 0; i < (int) lazy.size(); ++i)
			mp[lazy[i]] = i;
		lazy.clear();
	}
	int getId(int x) const {
		assert(lazy.empty());
		return mp.at(x);
	}
	int size() const {
		assert(lazy.empty());
		return mp.size();
	}
};

struct FT {
	int n;
	vector<int> v;

	FT(int _n) :
			n(_n), v(vector<int>(_n + 1, 0)) {
	}
	void inc(int i) {
		for (++i; i < (int) v.size(); i += i & -i)
			++v[i];
	}
	int query(int i) const { // sum from 0 ... i
		assert(i >= -1 && i < (int )v.size() - 1);
		int sum = 0;
		for (++i; i; i -= i & -i)
			sum += v[i];
		return sum;
	}
	int query(int i, int j) const {
		return query(j) - query(i - 1);
	}
};

ll f(ll x) {
	return x + x * (x - 1) / 2;
}

signed main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr), cout.tie(nullptr);

	int n;
	cin >> n;
	vector<pair<int, int>> pts(n);
	for (int i = 0; i < n; ++i)
		cin >> pts[i].first >> pts[i].second;

	{
		IdGen g1, g2;
		for (int i = 0; i < n; ++i) {
			g1.insert(pts[i].first);
			g2.insert(pts[i].second);
		}
		g1.process();
		g2.process();
		for (int i = 0; i < n; ++i) {
			pts[i].first = g1.getId(pts[i].first) + 1;
			pts[i].second = g2.getId(pts[i].second) + 1;
		}
	}

	map<int, vector<int>> mp;
	for (auto p : pts)
		mp[-p.second].push_back(p.first);

	FT ft((int) 4e5 + 9);
	ll ans = 0;
	for (pair<int, vector<int>> entry : mp) {
		vector<int> &v = entry.second;
		sort(v.begin(), v.end());


		for (int x : v) {
			assert(1 <= x && x < ft.n - 2);
			if (ft.query(x, x) == 0)
				ft.inc(x);
		}




		ans += f(ft.query(0, ft.n - 1));

		v.insert(v.begin(), -1);
		v.push_back(ft.n);
		for (int i = 0; i + 1 < (int) v.size(); ++i)
			ans -= f(ft.query(v[i] + 1, v[i + 1] - 1));

	}
	cout << ans;
	return 0;
}