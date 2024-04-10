#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

struct DS {
	struct Entry {
		int i, x, res;
		bool operator<(const Entry &other) const {
			return i < other.i;
		}
	};
	vector<Entry> v;

	void insert(const int i, int x) {
		for (auto &&e : v)
			x = min(x, x ^ e.x);

		if (x) {
			int res = v.empty() ? 0 : v.back().res;
			res = max(res, res ^ x);
			v.push_back( { i, x, res });
		}
	}

	int query(const int r) const {
		auto it = lower_bound(v.begin(), v.end(), Entry { r + 1, 0, 0 });
		return it == v.begin() ? 0 : (--it)->res;
	}
};

struct Query {
	int id, r;
	bool operator<(const Query &other) const {
		return r < other.r;
	}
};

const int Mx = (int) 5e5 + 9;

int a[Mx];
vector<Query> queries[Mx];
int ans[Mx];

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);

	int n;
	cin >> n;
	for (int i = 1; i <= n; ++i)
		cin >> a[i];

	int Q;
	cin >> Q;
	for (int i = 0; i < Q; ++i) {
		int l, r;
		cin >> l >> r;
		queries[l].push_back( { i, r });
	}

	DS ds;
	for (int l = n; l >= 1; --l) {

		{
			DS newDs;
			newDs.insert(l, a[l]);
			for (auto &&e : ds.v)
				newDs.insert(e.i, e.x);
			ds = move(newDs);
		}

		for (const Query &query : queries[l])
			ans[query.id] = ds.query(query.r);
	}

	for (int i = 0; i < Q; ++i)
		cout << ans[i] << '\n';
	return 0;
}