#undef NDEBUG
#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

const int MaxN = (int)3e5 + 99;

struct FT {
	int n;
	ll v[MaxN + 9];
	FT(int n) {
		this->n = n;
		fill(v, v + n + 1, 0);
	}
	void update(int i, const ll a) {
		for (++i; i <= n; i += i & -i)
			v[i] += a;
	}
	ll query(int i) const { // sum from 0 ... i
		assert(i >= -1 && i < n);
		ll sum = 0;
		for (++i; i; i -= i & -i)
			sum += v[i];
		return sum;
	}
	ll query(const int i, const int j) const {
		return query(j) - query(i - 1);
	}
};

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

int a[MaxN];
int b[MaxN];
ll ans[MaxN];

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);

	cerr << "test" << endl;

	int n, m;
	cin >> n >> m;
	for (int i = 0; i < n; ++i)
		cin >> a[i] >> b[i];

	IdGen idGen;
	for (int i = 0; i < n; ++i)
		idGen.insert(a[i] - b[i]);
	idGen.process();

	const int k = idGen.size();
	FT fta(k), ftb(k), ftc(k);

	for (int i = 0; i < n; ++i) {
		const int id = idGen.getId(a[i] - b[i]);
		fta.update(id, a[i]);
		ftb.update(id, b[i]);
		ftc.update(id, 1);
	}

	for (int i = 0; i < n; ++i) {
		const int id = idGen.getId(a[i] - b[i]);
		ans[i] += fta.query(0, id);
		ans[i] += ftb.query(id + 1, k - 1);

		ans[i] += ftc.query(0, id) * b[i];
		ans[i] += ftc.query(id + 1, k - 1) * a[i];

		ans[i] -= a[i] + b[i];
	}

	while (m--) {
		int u, v;
		cin >> u >> v;
		--u, --v;
		const ll c = min(a[u] + b[v], a[v] + b[u]);
		ans[u] -= c;
		ans[v] -= c;
	}
	for (int i = 0; i < n; ++i)
		cout << ans[i] << ' ';
	return 0;
}