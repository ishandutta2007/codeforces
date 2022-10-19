// #include "railroad.h"
#include <vector>
#include <algorithm>
#include <numeric>
#include <iostream>

using namespace std;

struct dsu_t {
	vector<int> a;
	dsu_t(int n) { a.assign(n, -1); }
	int get(int u) { return a[u] < 0 ? u : a[u] = get(a[u]); }
	bool same(int u, int v) { return get(u) == get(v); }
	void join(int u, int v) {
		u = get(u), v = get(v);
		if (u == v) return;
		if (a[u] > a[v]) swap(u, v);
		a[u] += a[v], a[v] = u;
	}
};

long long plan_roller_coaster(std::vector<int> s, std::vector<int> t) {
	// s.push_back(*max_element(t.begin(), t.end()));
	// t.push_back(*min_element(s.begin(), s.end()));
	
	int n = (int) s.size();

    vector<int> a;
    a.insert(a.end(), s.begin(), s.end());
    a.insert(a.end(), t.begin(), t.end());
    sort(a.begin(), a.end());
    a.erase(unique(a.begin(), a.end()), a.end());
    int m = (int) a.size();

    dsu_t dsu(m);
    vector<int> d(m);

    for (int i = 0; i < n; ++i) {
    	int l = (int) (lower_bound(a.begin(), a.end(), s[i]) - a.begin());
    	int r = (int) (lower_bound(a.begin(), a.end(), t[i]) - a.begin());
    	dsu.join(l, r);
    	++d[l], --d[r];
    }

    int64_t ans = 0;
    for (int j = 0; j + 1 < m; ++j) {
    	if (d[j] != 0) dsu.join(j, j + 1);
    	if (d[j] > 0) ans += (int64_t) d[j] * (a[j + 1] - a[j]);
    	d[j + 1] += d[j];
    }

    vector<int> p(m - 1);
    iota(p.begin(), p.end(), 0);
    sort(p.begin(), p.end(), [&](int i, int j) { return a[i + 1] - a[i] < a[j + 1] - a[j]; });
    for (int j : p) {
    	if (!dsu.same(j, j + 1)) {
    		ans += a[j + 1] - a[j];
    		dsu.join(j, j + 1);
    	}
    }

    return ans;
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	int n;
	cin >> n;
	vector<int> a(n), c(n);

	int64_t ans = 0;
	for (int i = 0; i < n; ++i) {
		cin >> a[i] >> c[i];
		ans += c[i];
		c[i] += a[i];
	}

	ans += plan_roller_coaster(c, a);
	cout << ans << endl;
}