#include <bits/stdc++.h>
#include <ext/pb_ds/tree_policy.hpp>
#include <ext/pb_ds/assoc_container.hpp>

using namespace __gnu_pbds;
using namespace std;

template <class T> using Tree = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;

template <class T> struct Multiset {
	Tree<std::pair<T, int>> oset;
	int mx = 0;

	void insert(T x) {
		oset.insert({x, ++mx});
	}

	void erase(T x) {
		oset.erase(oset.lower_bound({x, -1}));
	}

	int order_of_key(T x) { // assumes in set
		return oset.order_of_key({x, ++mx}) - 1;
	}
};

void solve_case(int tc = 0) { 
	int n, m;
	cin >> n >> m;
	vector<int> a(n);
	for (int i = 0; i < n; ++i) {
		cin >> a[i];
	}
	vector<vector<int>> b(m);
	vector<long long> sum(m);
	for (int i = 0; i < m; ++i) {
		int k;
		cin >> k;
		b[i].resize(k);
		for (int j = 0; j < k; ++j) {
			cin >> b[i][j];
		}
		sum[i] = accumulate(b[i].begin(), b[i].end(), 0ll);
	}
	sort(a.rbegin(), a.rend());
	while ((int)a.size() > m) {
		a.pop_back();
	}
	reverse(a.begin(), a.end());
	vector<long long> ages(m);
	for (int i = 0; i < m; ++i) {
		int k = (int)b[i].size();
		ages[i] = (sum[i] + k - 1) / k;
	}
	sort(ages.begin(), ages.end());
	vector<int> left(m), center(m), right(m);
	for (int i = 0; i < m; ++i) {
		left[i] = (i ? (a[i - 1] >= ages[i]) + left[i - 1] : 0);
		center[i] = (a[i] >= ages[i]) + (i ? center[i - 1] : 0);
		right[i] = (i != n - 1 ? a[i + 1] >= ages[i] : 0) + (i ? right[i - 1] : 0);
	}
	auto get = [&](vector<int>& v, int l, int r) {
		if (l > r) {
			return 0;
		} else {
			return v[r] - (l ? v[l - 1] : 0);
		}
	};
	string ans = "";
	Multiset<long long> ms;
	for (long long x : ages) {
		ms.insert(x);
	}
	for (int i = 0; i < m; ++i) {
		int k = (int)b[i].size();
		long long prv = (sum[i] + k - 1) / k;
		int oi = ms.order_of_key(prv);
		ms.erase(prv);
		for (int x : b[i]) {
			long nxt = (sum[i] - x + k - 2) / (k - 1);
			ms.insert(nxt);
			int ni = ms.order_of_key(nxt);
			int sum;
			if (oi == ni) {
				sum = (a[ni] >= nxt) + get(center, 0, oi - 1) + get(center, ni + 1, m - 1);
			} else if (oi < ni) {
				sum = (a[ni] >= nxt) + get(center, ni + 1, m - 1) + get(center, 0, oi - 1) + get(left, oi + 1, ni);
			} else {
				sum = (a[ni] >= nxt) + get(center, oi + 1, m - 1) + get(center, 0, ni - 1) + get(right, ni, oi - 1);
			}
			ans += '0' + (sum == m);
			ms.erase(nxt);
		}
		ms.insert(prv);
	}
	cout << ans << '\n';
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int tt;
	cin >> tt;
	for (int tc = 1; tc <= tt; ++tc) {
		solve_case(tc);
	}
	return 0;
}