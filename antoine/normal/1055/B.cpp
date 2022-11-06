#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

struct DSU {
	vector<ll> rank;
	vector<ll> parent;
	ll ans = 0;

	DSU(ll n) {
		rank.resize(n, 0);
		parent.resize(n);
		for (ll i = 0; i < n; ++i)
			parent[i] = i;
	}

	ll find(const ll u) {
		return parent[u] == u ? u : (parent[u] = find(parent[u]));
	}

	bool merge(ll u, ll v) {
		if ((u = find(u)) == (v = find(v)))
			return false;
		assert(rank[u] && rank[v]);
		ans--;

		if (rank[u] < rank[v])
			swap(u, v);
		rank[u] += rank[v];
		parent[v] = u;
		return true;
	}

	ll size(ll u) {
		return rank[find(u)];
	}
};

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);

	ll n, m, L;
	cin >> n >> m >> L;

	vector<ll> a(n + 1);

	for (ll i = 1; i <= n; ++i)
		cin >> a[i];

	DSU dsu(n + 1);

	for (ll i = 1; i <= n; ++i)
		if (a[i] > L) {
			dsu.rank[i] = a[i] > L;
			dsu.ans += a[i] > L;
		}

	for (ll i = 1; i < n; ++i)
		if (a[i] > L && a[i + 1] > L)
			dsu.merge(i, i + 1);

	while (m--) {
		ll type;
		cin >> type;
		if (type == 0) {
			cout << dsu.ans << '\n';
		} else {

			assert(type == 1);
			ll p, d;
			cin >> p >> d;

			if (a[p] <= L && a[p] + d > L) {
				dsu.rank[p]++;
				dsu.ans++;
			}

			a[p] += d;
			if (a[p] > L && p > 1 && a[p - 1] > L)
				dsu.merge(p - 1, p);
			if (a[p] > L && p < n && a[p + 1] > L)
				dsu.merge(p, p + 1);

		}
	}
	return 0;
}